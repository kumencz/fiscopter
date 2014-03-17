using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Tamir.Streams;
using Tamir.SharpSsh;

namespace FlyControler
{


    public class RxParser
    {
        private List<string> RxBufferList = new List<string>();
        private String RxBuffer = "";
        private UInt32 MessagesToParse = 0;
        byte[] rx_buff = new byte[200];
        SshStream ssh_rx;
        AsyncCallback rx_clbk;
        public event EventHandler<ParseMessgaeArgs> RxMessageReceived_event;
        public event EventHandler<LogArgs> LogEvent;

        public RxParser()
        {
            rx_clbk = new AsyncCallback(SSH_Rx_receive_calback);
        }


        private void SSH_Rx_receive_calback(IAsyncResult result)
        {            
            this.ssh_rx.EndRead(result);
            foreach (byte b in rx_buff)
            {
                if ((char)b != '\0')
                {
                    if ((char)b == '\r')
                    {
                        RxBuffer += '\n';
                    }
                    else
                    {
                        RxBuffer += (char)b;
                    }
                    if ((char)b == '\n' || (char)b == '\r')
                    {
                        RxBufferList.Add(RxBuffer);
                        RxBuffer = String.Empty;
                        this.Parse();
                    }
                }
            }
            rx_buff = new byte[200];
            this.ssh_rx.BeginRead(rx_buff, 0, rx_buff.Length, rx_clbk, new object());
        }

        public void SSH_Disconnect()
        {
            this.ssh_rx.Dispose();
        }

        public void SSH_Connect(string IP)
        {
            this.ssh_rx = new SshStream(IP, "root", "fiskopter348");
            this.ssh_rx.Write("stty -F /dev/ttyUSB0 sane raw -echo -echoe -echok 115200");
            this.ssh_rx.Write("echo \"PC_Connected_to_Fiscopter\n\" > /dev/ttyUSB0");
            this.ssh_rx.Write("cat /dev/ttyUSB0");
            MessageBox.Show(this.ssh_rx.ReadResponse());
            this.ssh_rx.BeginRead(rx_buff, 0, rx_buff.Length, rx_clbk, new object());
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
                else if (String.Compare(RxBufferList[0],RxMsg.texts[RxMsg_types.K_DBG_PID_X]) == 0)
                {
                    float [] hodnoty = new float[4];
                    parsed_msg = RxMsg_types.K_DBG_PID_X;
                    string[] subretezce = RxBufferList[0].Split(' ');
                    hodnoty[0] = float.Parse(subretezce[1]);
                    hodnoty[1] = float.Parse(subretezce[2]);
                    hodnoty[2] = float.Parse(subretezce[3]);
                    hodnoty[3] = float.Parse(subretezce[4]);
                    parsed_data = (object)hodnoty;
                }
                else if (String.Compare(RxBufferList[0], RxMsg.texts[RxMsg_types.K_DBG_PID_Y]) == 0)
                {
                    float[] hodnoty = new float[4];
                    parsed_msg = RxMsg_types.K_DBG_PID_Y;
                    string[] subretezce = RxBufferList[0].Split(' ');
                    hodnoty[0] = float.Parse(subretezce[1]);
                    hodnoty[1] = float.Parse(subretezce[2]);
                    hodnoty[2] = float.Parse(subretezce[3]);
                    hodnoty[3] = float.Parse(subretezce[4]);
                    parsed_data = (object)hodnoty;
                }

                if (this.LogEvent != null) this.LogEvent(this, new LogArgs(this.RxBufferList[0]));
                this.RxBufferList.RemoveAt(0);
                if (this.RxMessageReceived_event != null) RxMessageReceived_event(this, new ParseMessgaeArgs(parsed_msg, parsed_data));
            }
        }

    }
}
