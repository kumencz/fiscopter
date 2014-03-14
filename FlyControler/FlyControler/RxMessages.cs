using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace FlyControler
{
    public class ParseMessgaeArgs : EventArgs
    {
        public RxMsg_types Msg_type { private set; get; }
        public object Msg_data { private set; get; }

        public ParseMessgaeArgs(RxMsg_types type, object data)
        {
            this.Msg_type = type;
            this.Msg_data = data;
        }
    }

    public static class RxMsg
    {

        static public Dictionary<RxMsg_types, string> texts = new Dictionary<RxMsg_types, string>
        {
            {RxMsg_types.K_LIVE_OK, "K_LIVE_OK\n"},
            {RxMsg_types.K_RPM_SET, "K_SET_RPM"}
        };



    }
    


    public enum RxMsg_types
    {
        UNDEFINED,
        K_LIVE_OK,
        K_RPM_SET,
    }
}