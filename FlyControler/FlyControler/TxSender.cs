﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Tamir.Streams;
using Tamir.SharpSsh;

namespace FlyControler
{
    public class TxSender
    {
        SshStream ssh_tx;


        public event EventHandler<LogArgs> LogEvent;

        public TxSender()
        {
        }

        public void SSH_Disconnect()
        {
            this.ssh_tx.Dispose();
        }

        public void SSH_Connect(string IP)
        {
            this.ssh_tx = new SshStream(IP, "root", "fiskopter348");
            this.ssh_tx.Write("stty -F /dev/ttyUSB0 sane raw -echo -echoe -echok 115200");
        }

        public void Send_message(TxMsg_types msg_to_send, object data)
        {
            string to_send = TxMsg.texts[msg_to_send];
            switch (msg_to_send)
            {
                case TxMsg_types.P_RPM_SET:
                    UInt32 [] MotorSpeedArray = (UInt32 []) data;
                    to_send += String.Format(" {0} {1} {2} {3}\n", MotorSpeedArray[0], MotorSpeedArray[1], MotorSpeedArray[2], MotorSpeedArray[4]);
                    this.Send_string(to_send);
                    break;
                case TxMsg_types.P_PID_SET:
                    to_send += (string) data;
                    this.Send_string(to_send);
                    break;
            }

            this.Send_string(msg_to_send.ToString());
        }

        public void Send_string(string str_to_send)
        {
            if (str_to_send[str_to_send.Length - 1] != '\n') str_to_send += '\n';
            if (this.LogEvent != null) this.LogEvent(this, new LogArgs(str_to_send));
            this.ssh_tx.Write(String.Format("echo \"{0}\" > /dev/ttyUSB0", str_to_send));
        }

    }


}
