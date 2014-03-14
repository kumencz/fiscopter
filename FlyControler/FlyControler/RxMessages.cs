using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FlyControler
{
    public class ParseMessgaeArgs : EventArgs
    {
        public RxMessages Msg_type { private set; get; }
        public object Msg_data {private set; get;}

        public ParseMessgaeArgs(RxMessages type, object data)
        {
            this.Msg_type = type;
            this.Msg_data = data;
        }
    }

    enum RxMessages
    {
        UNDEFINED,
        K_CHECK_LIVE = "K_CHECK_LIVE",
        K_RPM_SET = "K_RPM_SET"
    }
}