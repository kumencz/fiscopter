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
    public partial class DBGForm : Form
    {
        DataLoger DBG;
        public DBGForm(DataLoger loger)
        {
            InitializeComponent();
            DBG = loger;
            this.DBG.LogEvent += new EventHandler<LogArgs>(DBG_LogEvent);
        }

        void DBG_LogEvent(object sender, LogArgs e)
        {
            if (this.InvokeRequired)
            {
                this.BeginInvoke((MethodInvoker)delegate
                {
                    DBG_LogEvent(sender, e);
                });
                return;
            }
            this.rtb_debug.AppendText(e.data);
        }

        private void tsbtn_clear_Click(object sender, EventArgs e)
        {
            this.rtb_debug.Clear();
        }

        private void tsbtn_stopLog_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_stopLog.Text == "Start log")
            {
                this.DBG.LogEvent += DBG_LogEvent;
                this.tsbtn_stopLog.Text = "Stop log";
            }
            else
            {
                this.DBG.LogEvent -= DBG_LogEvent;
                this.tsbtn_stopLog.Text = "Start log";
            }
        }

        private void DBGForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (this.tsbtn_stopLog.Text != "Start log")
            {
                this.DBG.LogEvent -= DBG_LogEvent;
            }
        }
    }
}
