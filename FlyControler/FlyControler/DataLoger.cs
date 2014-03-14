using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO.Ports;
using System.IO;

namespace FlyControler
{
    public class DataLoger
    {
        SerialPort cport;
        StreamWriter writer;

        public delegate void DataToLog(object sender, LogArgs data);
        public DataToLog DataLogFunc;

        public DataLoger(string COM)
        {
            cport = new SerialPort();
            cport.PortName = COM;
            cport.BaudRate = 115200;
            cport.Open();

            this.writer = new StreamWriter(string.Format("FiscopterLog_{0:YY_mm_dd_hh_MM}.txt", DateTime.Now));
            this.DataLogFunc = new DataToLog(this.LogData);

        }

        void LogData(object sender, LogArgs arg)
        {
            this.writer.WriteLine(arg.data);
        }
    }

    public class LogArgs : EventArgs
    {
        public string data { private set; get; }

        public LogArgs( string data)
        {
            this.data = data;
        }
    }
}
