namespace FlyControler
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripLabel1 = new System.Windows.Forms.ToolStripLabel();
            this.tstb_IP = new System.Windows.Forms.ToolStripTextBox();
            this.tsbtn_SSH_connect = new System.Windows.Forms.ToolStripButton();
            this.toolStripLabel2 = new System.Windows.Forms.ToolStripLabel();
            this.toolStripLabel3 = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripLabel4 = new System.Windows.Forms.ToolStripLabel();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.tsbtn_com_connect = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtn_ESC_calibrate = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripLabel1,
            this.tstb_IP,
            this.tsbtn_SSH_connect,
            this.toolStripLabel2,
            this.toolStripLabel3,
            this.toolStripSeparator1,
            this.toolStripLabel4,
            this.toolStripComboBox1,
            this.tsbtn_com_connect,
            this.toolStripSeparator2,
            this.tsbtn_ESC_calibrate,
            this.toolStripSeparator3});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(916, 25);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripLabel1
            // 
            this.toolStripLabel1.Name = "toolStripLabel1";
            this.toolStripLabel1.Size = new System.Drawing.Size(21, 22);
            this.toolStripLabel1.Text = "IP:";
            // 
            // tstb_IP
            // 
            this.tstb_IP.Name = "tstb_IP";
            this.tstb_IP.Size = new System.Drawing.Size(100, 25);
            this.tstb_IP.Text = "10.2.0.1";
            // 
            // tsbtn_SSH_connect
            // 
            this.tsbtn_SSH_connect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_SSH_connect.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_SSH_connect.Image")));
            this.tsbtn_SSH_connect.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_SSH_connect.Name = "tsbtn_SSH_connect";
            this.tsbtn_SSH_connect.Size = new System.Drawing.Size(51, 22);
            this.tsbtn_SSH_connect.Text = "Connect";
            this.tsbtn_SSH_connect.Click += new System.EventHandler(this.tsbtn_SSH_connect_Click);
            // 
            // toolStripLabel2
            // 
            this.toolStripLabel2.Enabled = false;
            this.toolStripLabel2.Name = "toolStripLabel2";
            this.toolStripLabel2.Size = new System.Drawing.Size(31, 22);
            this.toolStripLabel2.Text = "Ping:";
            // 
            // toolStripLabel3
            // 
            this.toolStripLabel3.Name = "toolStripLabel3";
            this.toolStripLabel3.Size = new System.Drawing.Size(64, 22);
            this.toolStripLabel3.Text = "disconected";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripLabel4
            // 
            this.toolStripLabel4.Name = "toolStripLabel4";
            this.toolStripLabel4.Size = new System.Drawing.Size(67, 22);
            this.toolStripLabel4.Text = "Output COM";
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size(75, 25);
            // 
            // tsbtn_com_connect
            // 
            this.tsbtn_com_connect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_com_connect.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_com_connect.Image")));
            this.tsbtn_com_connect.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_com_connect.Name = "tsbtn_com_connect";
            this.tsbtn_com_connect.Size = new System.Drawing.Size(51, 22);
            this.tsbtn_com_connect.Text = "Connect";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbtn_ESC_calibrate
            // 
            this.tsbtn_ESC_calibrate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_ESC_calibrate.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_ESC_calibrate.Image")));
            this.tsbtn_ESC_calibrate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_ESC_calibrate.Name = "tsbtn_ESC_calibrate";
            this.tsbtn_ESC_calibrate.Size = new System.Drawing.Size(109, 22);
            this.tsbtn_ESC_calibrate.Text = "Start ESC calibration";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(916, 477);
            this.Controls.Add(this.toolStrip1);
            this.Name = "Form1";
            this.Text = "FlyControl";
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        private System.Windows.Forms.ToolStripTextBox tstb_IP;
        private System.Windows.Forms.ToolStripButton tsbtn_SSH_connect;
        private System.Windows.Forms.ToolStripLabel toolStripLabel2;
        private System.Windows.Forms.ToolStripLabel toolStripLabel3;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripLabel toolStripLabel4;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
        private System.Windows.Forms.ToolStripButton tsbtn_com_connect;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton tsbtn_ESC_calibrate;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;

    }
}

