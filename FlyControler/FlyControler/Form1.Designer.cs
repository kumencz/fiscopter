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
            this.tslbl_ping_value = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripLabel4 = new System.Windows.Forms.ToolStripLabel();
            this.tscb_com_ports = new System.Windows.Forms.ToolStripComboBox();
            this.tsbtn_com_connect = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtn_ESC_calibrate = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtn_dbg = new System.Windows.Forms.ToolStripButton();
            this.tsbtn_pid = new System.Windows.Forms.ToolStripButton();
            this.tsbtn_rot = new System.Windows.Forms.ToolStripButton();
            this.tb_motor_speed = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.toolStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tb_motor_speed)).BeginInit();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripLabel1,
            this.tstb_IP,
            this.tsbtn_SSH_connect,
            this.toolStripLabel2,
            this.tslbl_ping_value,
            this.toolStripSeparator1,
            this.toolStripLabel4,
            this.tscb_com_ports,
            this.tsbtn_com_connect,
            this.tsbtn_dbg,
            this.tsbtn_pid,
            this.tsbtn_rot,
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
            this.toolStripLabel1.Size = new System.Drawing.Size(20, 22);
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
            this.tsbtn_SSH_connect.Size = new System.Drawing.Size(56, 22);
            this.tsbtn_SSH_connect.Text = "Connect";
            this.tsbtn_SSH_connect.Click += new System.EventHandler(this.tsbtn_SSH_connect_Click);
            // 
            // toolStripLabel2
            // 
            this.toolStripLabel2.Enabled = false;
            this.toolStripLabel2.Name = "toolStripLabel2";
            this.toolStripLabel2.Size = new System.Drawing.Size(34, 22);
            this.toolStripLabel2.Text = "Ping:";
            // 
            // tslbl_ping_value
            // 
            this.tslbl_ping_value.Name = "tslbl_ping_value";
            this.tslbl_ping_value.Size = new System.Drawing.Size(71, 22);
            this.tslbl_ping_value.Text = "disconected";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripLabel4
            // 
            this.toolStripLabel4.Name = "toolStripLabel4";
            this.toolStripLabel4.Size = new System.Drawing.Size(76, 22);
            this.toolStripLabel4.Text = "Output COM";
            // 
            // tscb_com_ports
            // 
            this.tscb_com_ports.Name = "tscb_com_ports";
            this.tscb_com_ports.Size = new System.Drawing.Size(75, 25);
            this.tscb_com_ports.DropDown += new System.EventHandler(this.toolStripComboBox1_DropDown);
            // 
            // tsbtn_com_connect
            // 
            this.tsbtn_com_connect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_com_connect.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_com_connect.Image")));
            this.tsbtn_com_connect.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_com_connect.Name = "tsbtn_com_connect";
            this.tsbtn_com_connect.Size = new System.Drawing.Size(56, 22);
            this.tsbtn_com_connect.Text = "Connect";
            this.tsbtn_com_connect.Click += new System.EventHandler(this.tsbtn_com_connect_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbtn_ESC_calibrate
            // 
            this.tsbtn_ESC_calibrate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_ESC_calibrate.Enabled = false;
            this.tsbtn_ESC_calibrate.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_ESC_calibrate.Image")));
            this.tsbtn_ESC_calibrate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_ESC_calibrate.Name = "tsbtn_ESC_calibrate";
            this.tsbtn_ESC_calibrate.Size = new System.Drawing.Size(117, 22);
            this.tsbtn_ESC_calibrate.Text = "Start ESC calibration";
            this.tsbtn_ESC_calibrate.Click += new System.EventHandler(this.tsbtn_ESC_calibrate_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbtn_dbg
            // 
            this.tsbtn_dbg.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_dbg.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_dbg.Image")));
            this.tsbtn_dbg.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_dbg.Name = "tsbtn_dbg";
            this.tsbtn_dbg.Size = new System.Drawing.Size(46, 22);
            this.tsbtn_dbg.Text = "Debug";
            this.tsbtn_dbg.Click += new System.EventHandler(this.tsbtn_dbg_Click);
            // 
            // tsbtn_pid
            // 
            this.tsbtn_pid.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_pid.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_pid.Image")));
            this.tsbtn_pid.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_pid.Name = "tsbtn_pid";
            this.tsbtn_pid.Size = new System.Drawing.Size(29, 22);
            this.tsbtn_pid.Text = "PID";
            // 
            // tsbtn_rot
            // 
            this.tsbtn_rot.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_rot.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_rot.Image")));
            this.tsbtn_rot.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_rot.Name = "tsbtn_rot";
            this.tsbtn_rot.Size = new System.Drawing.Size(61, 22);
            this.tsbtn_rot.Text = "Rotations";
            // 
            // tb_motor_speed
            // 
            this.tb_motor_speed.Location = new System.Drawing.Point(15, 90);
            this.tb_motor_speed.Name = "tb_motor_speed";
            this.tb_motor_speed.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.tb_motor_speed.Size = new System.Drawing.Size(45, 313);
            this.tb_motor_speed.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 74);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Motor speed";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(916, 477);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tb_motor_speed);
            this.Controls.Add(this.toolStrip1);
            this.Name = "Form1";
            this.Text = "FlyControl";
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tb_motor_speed)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        private System.Windows.Forms.ToolStripTextBox tstb_IP;
        private System.Windows.Forms.ToolStripButton tsbtn_SSH_connect;
        private System.Windows.Forms.ToolStripLabel toolStripLabel2;
        private System.Windows.Forms.ToolStripLabel tslbl_ping_value;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripLabel toolStripLabel4;
        private System.Windows.Forms.ToolStripComboBox tscb_com_ports;
        private System.Windows.Forms.ToolStripButton tsbtn_com_connect;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton tsbtn_ESC_calibrate;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripButton tsbtn_dbg;
        private System.Windows.Forms.ToolStripButton tsbtn_pid;
        private System.Windows.Forms.ToolStripButton tsbtn_rot;
        private System.Windows.Forms.TrackBar tb_motor_speed;
        private System.Windows.Forms.Label label1;

    }
}

