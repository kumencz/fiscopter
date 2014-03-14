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
 

        public Form1()
        {
            InitializeComponent();
            this.Parser = new RxParser();
            this.Sender = new TxSender();
            
        }

        private void tsbtn_SSH_connect_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_SSH_connect.Text == "Disconect")
            {
                this.tsbtn_SSH_connect.Text = "Connect";
                this.Sender.SSH_Disconnect();
                this.Parser.SSH_Disconnect();
                this.tstb_IP.Enabled = true;
            }
            else
            {
                this.Parser.SSH_Connect(this.tstb_IP.Text);
                this.Sender.SSH_Connect(this.tstb_IP.Text);
                this.tstb_IP.Enabled = false;
                this.tsbtn_SSH_connect.Text = "Disconect";
            }
            
        }



    }
}
