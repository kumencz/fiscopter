using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tamir.SharpSsh;
using Tamir.Streams;

namespace FlyControler
{
    public partial class Form1 : Form
    {
        RxParser Parser;
        TxSender Sender;

        LiveControler LControl;

        public Form1()
        {
            InitializeComponent();
            this.Parser = new RxParser();
            this.Sender = new TxSender();
            this.LControl = new LiveControler(this.Parser, this.Sender);
            this.LControl.PingChanged_event += new EventHandler<LiveControlerArgs>(LControl_PingChanged_event);
            
        }

        void LControl_PingChanged_event(object sender, LiveControlerArgs e)
        {
            if (this.InvokeRequired)
            {
                this.BeginInvoke((MethodInvoker)delegate
                {
                    LControl_PingChanged_event(sender, e);
                });
                return;
            }
            switch (e.state)
            {
                case GuardStates.ERROR:
                    this.tslbl_ping_value.BackColor = Color.Red;
                    this.tslbl_ping_value.Text = e.Interval.ToString();
                    break;
                case GuardStates.OK:
                    this.tslbl_ping_value.BackColor = Color.Green;
                    this.tslbl_ping_value.Text = e.Interval.ToString();
                    break;
                case GuardStates.WARNING:
                    this.tslbl_ping_value.BackColor = Color.OrangeRed;
                    this.tslbl_ping_value.Text = e.Interval.ToString();
                    break;
            }
        }

        private void tsbtn_SSH_connect_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_SSH_connect.Text == "Disconect")
            {
                this.tslbl_ping_value.Text = "disconected";
                this.tsbtn_SSH_connect.Text = "Connect";
                this.LControl.Stop_check();
                this.Sender.SSH_Disconnect();
                this.Parser.SSH_Disconnect();
                this.tstb_IP.Enabled = true;
            }
            else
            {
                this.Parser.SSH_Connect(this.tstb_IP.Text);
                this.Sender.SSH_Connect(this.tstb_IP.Text);
                this.tstb_IP.Enabled = false;
                this.LControl.Start_check();
                this.tsbtn_SSH_connect.Text = "Disconect";
            }
            
        }





    }
}
