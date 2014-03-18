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


        public event EventHandler<LogArgs> LogEvent;

        public delegate void DataToLog(object sender, LogArgs data);


        public DataToLog DataLogFunc;

        public DataLoger()
        {
            this.DataLogFunc = new DataToLog(this.LogData);
        }

        public void DataLogerInitCOM(string COM)
        {

            cport = new SerialPort();
            cport.PortName = COM;
            cport.BaudRate = 115200;
            cport.Open();

        }

        public void DataLogerDeInitCOM()
        {
            if (this.cport.IsOpen)
            {
                cport.Close();
            }
        }

        void LogData(object sender, LogArgs arg)
        {
            if (this.LogEvent != null) this.LogEvent(this, arg);
            this.cport.Write(arg.data);
            
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
