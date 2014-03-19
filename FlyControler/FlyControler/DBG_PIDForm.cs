using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FlyControler
{
    public partial class DBG_PIDForm : Form
    {
        UniversalComunicator comunicatror;

        
        public DBG_PIDForm(UniversalComunicator com)
        {
            InitializeComponent();
            this.comunicatror = com;
            this.comunicatror.RxMessageReceived_event += new EventHandler<ParseMessgaeArgs>(parser_RxMessageReceived_event);
        }

        void parser_RxMessageReceived_event(object sender, ParseMessgaeArgs e)
        {
            if (this.InvokeRequired)
            {
                this.BeginInvoke((MethodInvoker)delegate
                {
                    parser_RxMessageReceived_event(sender, e);
                });
                return;
            }
            if (e.Msg_type == RxMsg_types.K_DBG_PID_Y)
            {
                float[] hodnoty = (float[])e.Msg_data;
                this.chart_PID.Series["series_e"].Points.Add(hodnoty[0]);
                this.chart_PID.Series["series_sum"].Points.Add(hodnoty[1]);
                this.chart_PID.Series["series_dif"].Points.Add(hodnoty[2]);
                this.chart_PID.Series["series_out"].Points.Add(hodnoty[3]);
            }
        }

        private void tsbtn_clear_chartPID_Click(object sender, EventArgs e)
        {
            this.chart_PID.Series["series_e"].Points.Clear();
            this.chart_PID.Series["series_sum"].Points.Clear();
            this.chart_PID.Series["series_dif"].Points.Clear();
            this.chart_PID.Series["series_out"].Points.Clear();
        }

        private void tsbtn_set_PID_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_set_PID.Text == "Set")
            {
                this.tsbtn_set_PID.Text = "Change";
                this.tstb_kd.Enabled = false;
                this.tstb_ki.Enabled = false;
                this.tstb_kp.Enabled = false;
                string hodnoty = String.Format(" {0} {1} {2}\n", this.tstb_kp.Text, this.tstb_ki.Text, this.tstb_kd.Text);
                this.comunicatror.Send_message(TxMsg_types.P_PID_SET, (object)hodnoty);
            }
            else
            {
                this.tsbtn_set_PID.Text = "Set";

                this.tstb_kd.Enabled = true;
                this.tstb_ki.Enabled = true;
                this.tstb_kp.Enabled = true;
            }
        }

        private void DBG_PIDForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.comunicatror.RxMessageReceived_event -= parser_RxMessageReceived_event;
        }
    }
}
