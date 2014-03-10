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
 

        public Form1()
        {
            InitializeComponent();
            this.Parser = new RxParser();
            
        }

        private void tsbtn_SSH_connect_Click(object sender, EventArgs e)
        {
            if (this.tsbtn_SSH_connect.Text == "Disconect")
            {
                this.tsbtn_SSH_connect.Text = "Connect";
            }
            else
            {
                this.Parser.SSH_Connect(this.tstb_IP.Text);
                this.tsbtn_SSH_connect.Text = "Disconect";
            }
            
        }



    }
}
