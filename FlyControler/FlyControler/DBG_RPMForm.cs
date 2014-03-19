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
    public partial class DBG_RPMForm : Form
    {
        UniversalComunicator comunicator;
        List<UInt32> To_show_series_pl = new List<uint>();
        List<UInt32> To_show_series_pp = new List<uint>();
        List<UInt32> To_show_series_zl = new List<uint>();
        List<UInt32> To_show_series_zp = new List<uint>();

        public DBG_RPMForm(UniversalComunicator com)
        {
            InitializeComponent();
            this.comunicator = com;
            this.comunicator.RxMessageReceived_event += new EventHandler<ParseMessgaeArgs>(parser_RxMessageReceived_event);
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
            if (e.Msg_type == RxMsg_types.K_DBG_RPM)
            {
                UInt32[] hodnoty = (UInt32[]) e.Msg_data;

                //this.chart1.Series["series_pl"].Points.Add(hodnoty[0]);
                //this.chart1.Series["series_pp"].Points.Add(hodnoty[1]);
                //this.chart1.Series["series_zl"].Points.Add(hodnoty[2]);
                //this.chart1.Series["series_zp"].Points.Add(hodnoty[3]);
                this.To_show_series_pl.Add(hodnoty[0]);
                this.To_show_series_pp.Add(hodnoty[1]);
                this.To_show_series_zl.Add(hodnoty[2]);
                this.To_show_series_zp.Add(hodnoty[3]);
            }
        }

        private void tsbtn_chartRPM_clear_Click(object sender, EventArgs e)
        {
            //this.chart1.Series["series_pl"].Points;
            //this.chart1.Series["series_pp"].Points;
            //this.chart1.Series["series_zl"].Points;
            //this.chart1.Series["series_zp"].Points;


            this.chart1.Series["series_pl"].Points.Clear();
            this.chart1.Series["series_pp"].Points.Clear();
            this.chart1.Series["series_zl"].Points.Clear();
            this.chart1.Series["series_zp"].Points.Clear();
        }

        private void DBG_RPMForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.comunicator.RxMessageReceived_event -= parser_RxMessageReceived_event;
        }

        private void show_timer_Tick(object sender, EventArgs e)
        {
            this.chart1.Series["series_pl"].Points.AddY(this.To_show_series_pl.ToArray());
            this.chart1.Series["series_pp"].Points.AddY(this.To_show_series_pp.ToArray());
            this.chart1.Series["series_zl"].Points.AddY(this.To_show_series_zl.ToArray());
            this.chart1.Series["series_zp"].Points.AddY(this.To_show_series_zp.ToArray());
            this.To_show_series_pl.Clear();
            this.To_show_series_pp.Clear();
            this.To_show_series_zl.Clear();
            this.To_show_series_zp.Clear();
        }
    }
}
