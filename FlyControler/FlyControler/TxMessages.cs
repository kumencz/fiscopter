using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FlyControler
{
    public static class TxMsg
    {

        static public Dictionary<TxMsg_types, string> texts = new Dictionary<TxMsg_types, string>
        {
            {TxMsg_types.P_CHECK_LIVE, "P_CHECK_LIVE\n"},
            {TxMsg_types.P_RPM_SET, "P_RPM_SET"},
            {TxMsg_types.P_START_ESC_CALIBRATE, "P_START_ESC_CALIBRATE"},
            {TxMsg_types.P_PID_SET, "P_SET_PID"}

        };



    }

    public enum TxMsg_types
    {
        P_CHECK_LIVE,
        P_RPM_SET,
        P_START_ESC_CALIBRATE,
        P_PID_SET
    }
}