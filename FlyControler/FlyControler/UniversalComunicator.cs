using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO.Ports;

namespace FlyControler
{
    public class UniversalComunicator
    {
        string SerialPortBuffer = "";

        private List<string> RxBufferList = new List<string>();

        bool use_IP;

        public RxReceiver SSH_RX = new RxReceiver();
        public TxSender SSH_TX = new TxSender();

        public SerialPort cPort = new SerialPort();


        public event EventHandler<ParseMessgaeArgs> RxMessageReceived_event;
        public event EventHandler<LogArgs> LogEvent;

        public UniversalComunicator()
        {
        }

        public void  Connect(string connecting_text)
        {
            if (String.Compare(connecting_text.Substring(0, 3), "COM") == 0) //Srerial port connection
            {
                use_IP = false;
                this.cPort.PortName = connecting_text;
                this.cPort.BaudRate = 115200;
                this.cPort.DataReceived += new SerialDataReceivedEventHandler(cPort_DataReceived);  
                this.cPort.Open();
            }
            else // IP connection
            {
                use_IP = true;
                this.SSH_RX.SSH_Connect(connecting_text);
                this.SSH_TX.SSH_Connect(connecting_text);
                this.SSH_RX.RxMessageReceived_event += new EventHandler<ReceiveMessgaeArgs>(SSH_RX_RxMessageReceived_event);
                this.SSH_RX.LogEvent += new EventHandler<LogArgs>(SSH_RX_LogEvent);
                this.SSH_TX.LogEvent += SSH_RX_LogEvent;
            }
        }

        void cPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            this.SerialPortBuffer += this.cPort.ReadExisting();
            int index = this.SerialPortBuffer.IndexOf('\n');
            if (index >= 0)
            {
                this.RxBufferList.Add(this.SerialPortBuffer.Substring(0, index + 1));
                this.SerialPortBuffer = this.SerialPortBuffer.Remove(0, index + 1);
                this.Parse();
            }

        }

        void SSH_RX_LogEvent(object sender, LogArgs e)
        {
            if (this.LogEvent != null) this.LogEvent(sender, e);
        }

        void SSH_RX_RxMessageReceived_event(object sender, ReceiveMessgaeArgs e)
        {
            this.RxBufferList.Add(e.received_data);
            this.Parse();
        } 

        public void Disconnect()
        {
            if (this.use_IP)
            {
                this.SSH_RX.LogEvent -= SSH_RX_LogEvent;
            }
            else
            {
                this.cPort.DataReceived -= cPort_DataReceived; 
            }
        }



        public void Send_message(TxMsg_types msg_to_send, object data)
        {
            string to_send = TxMsg.texts[msg_to_send];
            switch (msg_to_send)
            {
                case TxMsg_types.P_RPM_SET:
                    UInt32[] MotorSpeedArray = (UInt32[])data;
                    to_send += String.Format(" {0} {1} {2} {3}\n", MotorSpeedArray[0], MotorSpeedArray[1], MotorSpeedArray[2], MotorSpeedArray[3]);
                    this.Send_string(to_send);
                    break;
                case TxMsg_types.P_PID_SET:
                    to_send += (string)data;
                    this.Send_string(to_send);
                    break;
            }

            this.Send_string(to_send.ToString());
        }

        public void Send_string(string str)
        {
            if (use_IP)
            {
                this.SSH_TX.Send_string(str);
            }
            else
            {
                this.cPort.Write(str);
            }
        }

        private void Parse()
        {
            RxMsg_types parsed_msg = RxMsg_types.UNDEFINED;
            object parsed_data = null;
            if (RxBufferList.Count > 0)
            {
                if (String.Compare(RxBufferList[0], RxMsg.texts[RxMsg_types.K_LIVE_OK]) == 0)
                {
                    parsed_msg = RxMsg_types.K_LIVE_OK;
                }
                else if (RxBufferList[0].Length >= RxMsg.texts[RxMsg_types.K_DBG_PID_X].Length && String.Compare(RxBufferList[0].Substring(0, RxMsg.texts[RxMsg_types.K_DBG_PID_X].Length), RxMsg.texts[RxMsg_types.K_DBG_PID_X]) == 0)
                {
                    try
                    {
                        float[] hodnoty = new float[4];
                        parsed_msg = RxMsg_types.K_DBG_PID_X;
                        string[] subretezce = RxBufferList[0].Replace('.', ',').Split(' ');
                        hodnoty[0] = float.Parse(subretezce[1]);
                        hodnoty[1] = float.Parse(subretezce[2]);
                        hodnoty[2] = float.Parse(subretezce[3]);
                        hodnoty[3] = float.Parse(subretezce[4]);
                        parsed_data = (object)hodnoty;
                    }
                    catch
                    {
                        parsed_msg = RxMsg_types.UNDEFINED;
                        parsed_data = null;
                    }
                }
                else if (RxBufferList[0].Length >= RxMsg.texts[RxMsg_types.K_DBG_PID_Y].Length &&  String.Compare(RxBufferList[0].Substring(0, RxMsg.texts[RxMsg_types.K_DBG_PID_Y].Length), RxMsg.texts[RxMsg_types.K_DBG_PID_Y]) == 0)
                {
                    try
                    {
                        float[] hodnoty = new float[4];
                        parsed_msg = RxMsg_types.K_DBG_PID_Y;
                        string[] subretezce = RxBufferList[0].Replace('.', ',').Split(' ');
                        hodnoty[0] = float.Parse(subretezce[1]);
                        hodnoty[1] = float.Parse(subretezce[2]);
                        hodnoty[2] = float.Parse(subretezce[3]);
                        hodnoty[3] = float.Parse(subretezce[4]);
                        parsed_data = (object)hodnoty;
                    }
                    catch
                    {
                        parsed_msg = RxMsg_types.UNDEFINED;
                        parsed_data = null;
                    }
                }
                else if (String.Compare(RxBufferList[0], RxMsg.texts[RxMsg_types.K_DBG_RPM]) == 0)
                {
                    UInt32[] hodnoty = new UInt32[4];
                    parsed_msg = RxMsg_types.K_DBG_RPM;
                    string[] subretezce = RxBufferList[0].Split(' ');
                    hodnoty[0] = UInt32.Parse(subretezce[1]);
                    hodnoty[1] = UInt32.Parse(subretezce[2]);
                    hodnoty[2] = UInt32.Parse(subretezce[3]);
                    hodnoty[3] = UInt32.Parse(subretezce[4]);
                    parsed_data = (object)hodnoty;
                }

                if (this.LogEvent != null) this.LogEvent(this, new LogArgs(this.RxBufferList[0]));
                this.RxBufferList.RemoveAt(0);
                if (this.RxMessageReceived_event != null) RxMessageReceived_event(this, new ParseMessgaeArgs(parsed_msg, parsed_data));
            }
        }
    }
}
