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
        List<Double> ToAdd_series_e = new List<Double>();
        List<Double> ToAdd_series_sum = new List<Double>();
        List<Double> ToAdd_series_dif = new List<Double>();
        List<Double> ToAdd_series_out = new List<Double>();
        
        public DBG_PIDForm(UniversalComunicator com)
        {
            InitializeComponent();
            this.comunicatror = com;
            this.comunicatror.RxMessageReceived_event += new EventHandler<ParseMessgaeArgs>(parser_RxMessageReceived_event);
            this.show_timer.Enabled = true;
        }

        void parser_RxMessageReceived_event(object sender, ParseMessgaeArgs e)
        {
            //if (this.InvokeRequired)
            //{
            //    this.BeginInvoke((MethodInvoker)delegate
            //    {
            //        parser_RxMessageReceived_event(sender, e);
            //    });
            //    return;
            //}
            if (e.Msg_type == RxMsg_types.K_DBG_PID_Y)
            {
                float[] hodnoty = (float[])e.Msg_data;
                //    this.chart_PID.Series["series_e"].Points.Add(hodnoty[0]);
                //    this.chart_PID.Series["series_sum"].Points.Add(hodnoty[1]);
                //    this.chart_PID.Series["series_dif"].Points.Add(hodnoty[2]);
                //    this.chart_PID.Series["series_out"].Points.Add(hodnoty[3]);
                this.ToAdd_series_e.Add((Double)hodnoty[0]);
                this.ToAdd_series_sum.Add((Double)hodnoty[1]);
                this.ToAdd_series_dif.Add((Double)hodnoty[2]);
                this.ToAdd_series_out.Add((Double)hodnoty[3]);
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
            this.show_timer.Enabled = false;
        }

        private void show_timer_Tick(object sender, EventArgs e)
        {
            //if (this.ToAdd_series_e.Count > 0)
            //{
            //    Double[] array = this.ToAdd_series_e.ToArray();
            //    this.chart_PID.Series["series_e"].Points.AddY(array);
            //    this.ToAdd_series_e.Clear();
            //}
            //if (this.ToAdd_series_sum.Count > 0)
            //{
            //    this.chart_PID.Series["series_sum"].Points.AddY(this.ToAdd_series_sum.ToArray());
            //    this.ToAdd_series_sum.Clear();
            //}
            //if (this.ToAdd_series_dif.Count > 0)
            //{
            //    this.chart_PID.Series["series_dif"].Points.AddY(this.ToAdd_series_dif.ToArray());
            //    this.ToAdd_series_dif.Clear();
            //}
            //if (this.ToAdd_series_out.Count > 0)
            //{
            //    this.chart_PID.Series["series_out"].Points.AddY(this.ToAdd_series_out.ToArray());
            //    this.ToAdd_series_out.Clear();
            //}
            foreach (double data in this.ToAdd_series_e.ToArray())
            {
                this.chart_PID.Series["series_e"].Points.Add(data);
            }
            this.ToAdd_series_e.Clear();
            foreach (double data in this.ToAdd_series_sum.ToArray())
            {
                this.chart_PID.Series["series_sum"].Points.Add(data);
            }
            this.ToAdd_series_sum.Clear();
            foreach (double data in this.ToAdd_series_dif.ToArray())
            {
                this.chart_PID.Series["series_dif"].Points.Add(data);
            }
            this.ToAdd_series_dif.Clear();
            foreach (double data in this.ToAdd_series_out.ToArray())
            {
                this.chart_PID.Series["series_out"].Points.Add(data);
            }
            this.ToAdd_series_out.Clear();
        }

        private void tsbtn_stop_log_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_stop_log.Text == "Stop log")
            {
                this.tsbtn_stop_log.Text = "Start log";
                this.comunicatror.RxMessageReceived_event -= parser_RxMessageReceived_event;
            }
            else
            {
                this.tsbtn_stop_log.Text = "Stop log";
                this.comunicatror.RxMessageReceived_event += parser_RxMessageReceived_event;
            }

        }

        private void tsbtn_reset_zoom_y_Click(object sender, EventArgs e)
        {
            this.chart_PID.ChartAreas[0].Axes[1].ScaleView.ZoomReset(0);
        }

        private void tsbtn_reset_zoom_x_Click(object sender, EventArgs e)
        {
            this.chart_PID.ChartAreas[0].Axes[0].ScaleView.ZoomReset(0);
        }

        private void tsbtn_reset_zoom_Click(object sender, EventArgs e)
        {
            this.chart_PID.ChartAreas[0].Axes[1].ScaleView.ZoomReset(0);
            this.chart_PID.ChartAreas[0].Axes[0].ScaleView.ZoomReset(0);
        }
    }
}
