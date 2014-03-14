using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

using Tamir.SharpSsh;
using Tamir.Streams;

namespace FlyControler
{
    public partial class Form1 : Form
    {
        RxParser Parser;
        TxSender Sender;

        DataLoger Loger;

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
                this.tsbtn_ESC_calibrate.Enabled = false;
            }
            else
            {
                this.Parser.SSH_Connect(this.tstb_IP.Text);
                this.Sender.SSH_Connect(this.tstb_IP.Text);
                this.LControl.Start_check();
                this.tsbtn_SSH_connect.Text = "Disconect";


                this.tstb_IP.Enabled = false;
                this.tsbtn_ESC_calibrate.Enabled = true;
            }
            
        }

        private void tsbtn_ESC_calibrate_Click(object sender, EventArgs e)
        {
            DialogResult res = MessageBox.Show("Opravdu spustit kalibraci?", "Warning", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (res == System.Windows.Forms.DialogResult.Yes)
            {
                this.Sender.Send_message(TxMsg_types.P_START_ESC_CALIBRATE, null);
            }
        }

        private void toolStripComboBox1_DropDown(object sender, EventArgs e)
        {
            this.tscb_com_ports.Items.Clear();
            this.tscb_com_ports.Items.AddRange(SerialPort.GetPortNames());
        }

        private void tsbtn_com_connect_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_com_connect.Text == "Connect")
            {
                if (this.tscb_com_ports.SelectedIndex >= 0)
                {
                    this.tsbtn_com_connect.Text = "Disconect";
                    this.Loger = new DataLoger(this.tscb_com_ports.Items[this.tscb_com_ports.SelectedIndex].ToString());
                    this.Parser.LogEvent += new EventHandler<LogArgs>(Loger.DataLogFunc);
                    this.Sender.LogEvent += new EventHandler<LogArgs>(Loger.DataLogFunc);
                }
                else
                {
                    MessageBox.Show("Není vybrán žádný výstupní port.", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
            else
            {
                this.tsbtn_com_connect.Text = "Connect";
            }
        }





    }
}
