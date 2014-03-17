namespace FlyControler
{
    partial class DBG_PIDForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DBG_PIDForm));
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripLabel1 = new System.Windows.Forms.ToolStripLabel();
            this.tstb_kp = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripLabel2 = new System.Windows.Forms.ToolStripLabel();
            this.tstb_ki = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripLabel3 = new System.Windows.Forms.ToolStripLabel();
            this.tstb_kd = new System.Windows.Forms.ToolStripTextBox();
            this.tsbtn_set_PID = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtn_clear_chartPID = new System.Windows.Forms.ToolStripButton();
            this.chart_PID = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.toolStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart_PID)).BeginInit();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripLabel1,
            this.tstb_kp,
            this.toolStripLabel2,
            this.tstb_ki,
            this.toolStripLabel3,
            this.tstb_kd,
            this.tsbtn_set_PID,
            this.toolStripSeparator1,
            this.tsbtn_clear_chartPID});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(882, 25);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripLabel1
            // 
            this.toolStripLabel1.Name = "toolStripLabel1";
            this.toolStripLabel1.Size = new System.Drawing.Size(35, 22);
            this.toolStripLabel1.Text = "Kp = ";
            // 
            // tstb_kp
            // 
            this.tstb_kp.Name = "tstb_kp";
            this.tstb_kp.Size = new System.Drawing.Size(50, 25);
            // 
            // toolStripLabel2
            // 
            this.toolStripLabel2.Name = "toolStripLabel2";
            this.toolStripLabel2.Size = new System.Drawing.Size(31, 22);
            this.toolStripLabel2.Text = "Ki = ";
            // 
            // tstb_ki
            // 
            this.tstb_ki.Name = "tstb_ki";
            this.tstb_ki.Size = new System.Drawing.Size(50, 25);
            // 
            // toolStripLabel3
            // 
            this.toolStripLabel3.Name = "toolStripLabel3";
            this.toolStripLabel3.Size = new System.Drawing.Size(35, 22);
            this.toolStripLabel3.Text = "Kd = ";
            // 
            // tstb_kd
            // 
            this.tstb_kd.Name = "tstb_kd";
            this.tstb_kd.Size = new System.Drawing.Size(50, 25);
            // 
            // tsbtn_set_PID
            // 
            this.tsbtn_set_PID.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_set_PID.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_set_PID.Image")));
            this.tsbtn_set_PID.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_set_PID.Name = "tsbtn_set_PID";
            this.tsbtn_set_PID.Size = new System.Drawing.Size(27, 22);
            this.tsbtn_set_PID.Text = "Set";
            this.tsbtn_set_PID.Click += new System.EventHandler(this.tsbtn_set_PID_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbtn_clear_chartPID
            // 
            this.tsbtn_clear_chartPID.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_clear_chartPID.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_clear_chartPID.Image")));
            this.tsbtn_clear_chartPID.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_clear_chartPID.Name = "tsbtn_clear_chartPID";
            this.tsbtn_clear_chartPID.Size = new System.Drawing.Size(68, 22);
            this.tsbtn_clear_chartPID.Text = "Clear chart";
            this.tsbtn_clear_chartPID.Click += new System.EventHandler(this.tsbtn_clear_chartPID_Click);
            // 
            // chart_PID
            // 
            this.chart_PID.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            chartArea1.Name = "ChartArea1";
            this.chart_PID.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chart_PID.Legends.Add(legend1);
            this.chart_PID.Location = new System.Drawing.Point(12, 28);
            this.chart_PID.Name = "chart_PID";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Legend = "Legend1";
            series1.LegendText = "Odchylka";
            series1.Name = "series_e";
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series2.Legend = "Legend1";
            series2.LegendText = "Sumator";
            series2.Name = "series_sum";
            series3.ChartArea = "ChartArea1";
            series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series3.Legend = "Legend1";
            series3.LegendText = "Rozdíl";
            series3.Name = "series_dif";
            series4.ChartArea = "ChartArea1";
            series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series4.Legend = "Legend1";
            series4.LegendText = "Vystup";
            series4.Name = "series_out";
            this.chart_PID.Series.Add(series1);
            this.chart_PID.Series.Add(series2);
            this.chart_PID.Series.Add(series3);
            this.chart_PID.Series.Add(series4);
            this.chart_PID.Size = new System.Drawing.Size(858, 420);
            this.chart_PID.TabIndex = 1;
            this.chart_PID.Text = "chart1";
            // 
            // DBG_PIDForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(882, 460);
            this.Controls.Add(this.chart_PID);
            this.Controls.Add(this.toolStrip1);
            this.Name = "DBG_PIDForm";
            this.Text = "DBG_PIDForm";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.DBG_PIDForm_FormClosed);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart_PID)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart_PID;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        private System.Windows.Forms.ToolStripTextBox tstb_kp;
        private System.Windows.Forms.ToolStripLabel toolStripLabel2;
        private System.Windows.Forms.ToolStripTextBox tstb_ki;
        private System.Windows.Forms.ToolStripLabel toolStripLabel3;
        private System.Windows.Forms.ToolStripTextBox tstb_kd;
        private System.Windows.Forms.ToolStripButton tsbtn_set_PID;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton tsbtn_clear_chartPID;
    }
}