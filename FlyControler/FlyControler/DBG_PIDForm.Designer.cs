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
            this.components = new System.ComponentModel.Container();
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
            this.tsbtn_reset_zoom = new System.Windows.Forms.ToolStripButton();
            this.tsbtn_reset_zoom_x = new System.Windows.Forms.ToolStripButton();
            this.tsbtn_reset_zoom_y = new System.Windows.Forms.ToolStripButton();
            this.tsbtn_stop_log = new System.Windows.Forms.ToolStripButton();
            this.chart_PID = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.show_timer = new System.Windows.Forms.Timer(this.components);
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
            this.tsbtn_clear_chartPID,
            this.tsbtn_reset_zoom,
            this.tsbtn_reset_zoom_x,
            this.tsbtn_reset_zoom_y,
            this.tsbtn_stop_log});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1176, 27);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripLabel1
            // 
            this.toolStripLabel1.Name = "toolStripLabel1";
            this.toolStripLabel1.Size = new System.Drawing.Size(45, 24);
            this.toolStripLabel1.Text = "Kp = ";
            // 
            // tstb_kp
            // 
            this.tstb_kp.Name = "tstb_kp";
            this.tstb_kp.Size = new System.Drawing.Size(65, 27);
            // 
            // toolStripLabel2
            // 
            this.toolStripLabel2.Name = "toolStripLabel2";
            this.toolStripLabel2.Size = new System.Drawing.Size(40, 24);
            this.toolStripLabel2.Text = "Ki = ";
            // 
            // tstb_ki
            // 
            this.tstb_ki.Name = "tstb_ki";
            this.tstb_ki.Size = new System.Drawing.Size(65, 27);
            // 
            // toolStripLabel3
            // 
            this.toolStripLabel3.Name = "toolStripLabel3";
            this.toolStripLabel3.Size = new System.Drawing.Size(45, 24);
            this.toolStripLabel3.Text = "Kd = ";
            // 
            // tstb_kd
            // 
            this.tstb_kd.Name = "tstb_kd";
            this.tstb_kd.Size = new System.Drawing.Size(65, 27);
            // 
            // tsbtn_set_PID
            // 
            this.tsbtn_set_PID.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_set_PID.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_set_PID.Image")));
            this.tsbtn_set_PID.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_set_PID.Name = "tsbtn_set_PID";
            this.tsbtn_set_PID.Size = new System.Drawing.Size(34, 24);
            this.tsbtn_set_PID.Text = "Set";
            this.tsbtn_set_PID.Click += new System.EventHandler(this.tsbtn_set_PID_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 27);
            // 
            // tsbtn_clear_chartPID
            // 
            this.tsbtn_clear_chartPID.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_clear_chartPID.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_clear_chartPID.Image")));
            this.tsbtn_clear_chartPID.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_clear_chartPID.Name = "tsbtn_clear_chartPID";
            this.tsbtn_clear_chartPID.Size = new System.Drawing.Size(84, 24);
            this.tsbtn_clear_chartPID.Text = "Clear chart";
            this.tsbtn_clear_chartPID.Click += new System.EventHandler(this.tsbtn_clear_chartPID_Click);
            // 
            // tsbtn_reset_zoom
            // 
            this.tsbtn_reset_zoom.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_reset_zoom.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_reset_zoom.Image")));
            this.tsbtn_reset_zoom.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_reset_zoom.Name = "tsbtn_reset_zoom";
            this.tsbtn_reset_zoom.Size = new System.Drawing.Size(91, 24);
            this.tsbtn_reset_zoom.Text = "Reset zoom";
            this.tsbtn_reset_zoom.Click += new System.EventHandler(this.tsbtn_reset_zoom_Click);
            // 
            // tsbtn_reset_zoom_x
            // 
            this.tsbtn_reset_zoom_x.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_reset_zoom_x.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_reset_zoom_x.Image")));
            this.tsbtn_reset_zoom_x.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_reset_zoom_x.Name = "tsbtn_reset_zoom_x";
            this.tsbtn_reset_zoom_x.Size = new System.Drawing.Size(104, 24);
            this.tsbtn_reset_zoom_x.Text = "Reset zoom X";
            this.tsbtn_reset_zoom_x.Click += new System.EventHandler(this.tsbtn_reset_zoom_x_Click);
            // 
            // tsbtn_reset_zoom_y
            // 
            this.tsbtn_reset_zoom_y.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_reset_zoom_y.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_reset_zoom_y.Image")));
            this.tsbtn_reset_zoom_y.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_reset_zoom_y.Name = "tsbtn_reset_zoom_y";
            this.tsbtn_reset_zoom_y.Size = new System.Drawing.Size(103, 24);
            this.tsbtn_reset_zoom_y.Text = "Reset zoom Y";
            this.tsbtn_reset_zoom_y.Click += new System.EventHandler(this.tsbtn_reset_zoom_y_Click);
            // 
            // tsbtn_stop_log
            // 
            this.tsbtn_stop_log.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.tsbtn_stop_log.Image = ((System.Drawing.Image)(resources.GetObject("tsbtn_stop_log.Image")));
            this.tsbtn_stop_log.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtn_stop_log.Name = "tsbtn_stop_log";
            this.tsbtn_stop_log.Size = new System.Drawing.Size(70, 24);
            this.tsbtn_stop_log.Text = "Stop log";
            this.tsbtn_stop_log.Click += new System.EventHandler(this.tsbtn_stop_log_Click);
            // 
            // chart_PID
            // 
            this.chart_PID.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            chartArea1.CursorX.IsUserSelectionEnabled = true;
            chartArea1.CursorY.IsUserSelectionEnabled = true;
            chartArea1.Name = "ChartArea1";
            this.chart_PID.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chart_PID.Legends.Add(legend1);
            this.chart_PID.Location = new System.Drawing.Point(16, 34);
            this.chart_PID.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chart_PID.Name = "chart_PID";
            series1.BorderWidth = 5;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Legend = "Legend1";
            series1.LegendText = "Odchylka";
            series1.Name = "series_e";
            series2.BorderWidth = 5;
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series2.Legend = "Legend1";
            series2.LegendText = "Sumator";
            series2.Name = "series_sum";
            series3.BorderWidth = 5;
            series3.ChartArea = "ChartArea1";
            series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series3.Legend = "Legend1";
            series3.LegendText = "Rozdíl";
            series3.Name = "series_dif";
            series4.BorderWidth = 5;
            series4.ChartArea = "ChartArea1";
            series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series4.Legend = "Legend1";
            series4.LegendText = "Vystup";
            series4.Name = "series_out";
            series4.YAxisType = System.Windows.Forms.DataVisualization.Charting.AxisType.Secondary;
            this.chart_PID.Series.Add(series1);
            this.chart_PID.Series.Add(series2);
            this.chart_PID.Series.Add(series3);
            this.chart_PID.Series.Add(series4);
            this.chart_PID.Size = new System.Drawing.Size(1144, 517);
            this.chart_PID.TabIndex = 1;
            this.chart_PID.Text = "chart1";
            this.chart_PID.TextAntiAliasingQuality = System.Windows.Forms.DataVisualization.Charting.TextAntiAliasingQuality.SystemDefault;
            // 
            // show_timer
            // 
            this.show_timer.Interval = 1000;
            this.show_timer.Tick += new System.EventHandler(this.show_timer_Tick);
            // 
            // DBG_PIDForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1176, 566);
            this.Controls.Add(this.chart_PID);
            this.Controls.Add(this.toolStrip1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
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
        private System.Windows.Forms.Timer show_timer;
        private System.Windows.Forms.ToolStripButton tsbtn_reset_zoom;
        private System.Windows.Forms.ToolStripButton tsbtn_reset_zoom_x;
        private System.Windows.Forms.ToolStripButton tsbtn_reset_zoom_y;
        private System.Windows.Forms.ToolStripButton tsbtn_stop_log;
    }
}