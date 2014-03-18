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

        UniversalComunicator comunicator;


        DataLoger Loger = new DataLoger();

        DBGForm DebugForm;
        DBG_PIDForm DebugPID;

        LiveControler LControl;

        public Form1()
        {
            InitializeComponent();
            comunicator = new UniversalComunicator();

            this.LControl = new LiveControler(this.comunicator);
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
                this.comunicator.Disconnect();

                this.tstb_IP.Enabled = true;
                this.tsbtn_ESC_calibrate.Enabled = false;
            }
            else
            {
                this.comunicator.Connect(this.tstb_IP.Text);
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
                this.comunicator.Send_message(TxMsg_types.P_START_ESC_CALIBRATE, null);
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
                    this.Loger.DataLogerInitCOM(this.tscb_com_ports.Items[this.tscb_com_ports.SelectedIndex].ToString());
                    this.comunicator.LogEvent += new EventHandler<LogArgs>(Loger.DataLogFunc);
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

        private void tsbtn_dbg_Click(object sender, EventArgs e)
        {
            this.DebugForm = new DBGForm(this.comunicator);
            this.DebugForm.Show();
        }

        private void tsbtn_pid_Click(object sender, EventArgs e)
        {
            this.DebugPID = new DBG_PIDForm(this.comunicator);
            this.DebugPID.Show();
        }

        private void tb_motor_speed_Scroll(object sender, EventArgs e)
        {
            UInt32 [] MotorSpeedArray = new UInt32[4];
            MotorSpeedArray[0] = (UInt32) this.tb_motor_speed.Value;
            MotorSpeedArray[1] = (UInt32) this.tb_motor_speed.Value;
            MotorSpeedArray[2] = (UInt32) this.tb_motor_speed.Value;
            MotorSpeedArray[3] = (UInt32) this.tb_motor_speed.Value;
            this.comunicator.Send_message(TxMsg_types.P_RPM_SET, (object)MotorSpeedArray);
            this.nud_RPM.Value = this.tb_motor_speed.Value;

        }

        private void nud_RPM_ValueChanged(object sender, EventArgs e)
        {
            //this.tb_motor_speed.Value = (int)this.nud_RPM.Value;
        }

        private void tsbtn_enable_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_enable.Checked)
            {
                this.LControl.Start_check();
            }
            else
            {
                this.LControl.Stop_check();
            }

        }





    }
}
