namespace FlyControler
{
    partial class DBGForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DBGForm));
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.tsbtn_clear = new System.Windows.Forms.ToolStripButton();
            this.tsbtn_stopLog = new System.Windows.Forms.ToolStripButton();
            this.rtb_debug = new System.Windows.Forms.RichTextBox();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbtn_clear,
            this.tsbtn_stopLog});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(853, 25);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // tsbtn_clear
            // 
            this.tsbtn_clear.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_clear.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_clear.Image")));
            this.tsbtn_clear.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_clear.Name = "tsbtn_clear";
            this.tsbtn_clear.Size = new System.Drawing.Size(38, 22);
            this.tsbtn_clear.Text = "Clear";
            this.tsbtn_clear.Click += new System.EventHandler(this.tsbtn_clear_Click);
            // 
            // tsbtn_stopLog
            // 
            this.tsbtn_stopLog.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_stopLog.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_stopLog.Image")));
            this.tsbtn_stopLog.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_stopLog.Name = "tsbtn_stopLog";
            this.tsbtn_stopLog.Size = new System.Drawing.Size(55, 22);
            this.tsbtn_stopLog.Text = "Stop log";
            this.tsbtn_stopLog.Click += new System.EventHandler(this.tsbtn_stopLog_Click);
            // 
            // rtb_debug
            // 
            this.rtb_debug.Location = new System.Drawing.Point(12, 28);
            this.rtb_debug.Name = "rtb_debug";
            this.rtb_debug.Size = new System.Drawing.Size(829, 482);
            this.rtb_debug.TabIndex = 1;
            this.rtb_debug.Text = "";
            // 
            // DBGForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(853, 522);
            this.Controls.Add(this.rtb_debug);
            this.Controls.Add(this.toolStrip1);
            this.Name = "DBGForm";
            this.Text = "DBGForm";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.DBGForm_FormClosed);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton tsbtn_clear;
        private System.Windows.Forms.ToolStripButton tsbtn_stopLog;
        private System.Windows.Forms.RichTextBox rtb_debug;
    }
}