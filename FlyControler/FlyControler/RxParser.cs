﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Tamir.Streams;
using Tamir.SharpSsh;

namespace FlyControler
{
    class RxParser
    {
        private List<string> RxBufferList = new List<string>();
        private String RxBuffer = "";
        private UInt32 MessagesToParse = 0;
        byte[] rx_buff = new byte[200];
        SshStream ssh_rx;
        AsyncCallback rx_clbk;

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
            if (RxBufferList.Count > 0)
            {
                if (String.Compare(RxBufferList[0], "LIVE_OK\n") == 0)
                {
                }
                else if (String.Compare(RxBufferList[0], "NejakA_dalsi_zprava\n") == 0)
                {
                }
                this.RxBufferList.RemoveAt(0);
            }
        }

    }
}
