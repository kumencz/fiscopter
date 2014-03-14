using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FlyControler
{
    class LiveControler
    {
        public const Int32 SHOW_INTERVAL = 1000; 
        public const Int32 GUARD_INTERVAL = 500;
        public const Int16 LIVE_TIME = 10; //Doba na odpoved = GUARD_INTERVAL * LIVE_TIME

        private const UInt32 WARNING_VALUE = 250; //ms

        RxParser Parser;
        TxSender Sender;
        Timer tim = new Timer();
        Timer show_tim = new Timer();

        public event EventHandler<LiveControlerArgs> PingChanged_event;

        UInt32 Sended_counter = 0;
        UInt32 Interval = 0xFFFFFFFF; // in ms

        public LiveControler(RxParser parser, TxSender sender)
        {
            this.Parser = parser;
            this.Sender = sender;
            this.Parser.RxMessageReceived_event += new EventHandler<ParseMessgaeArgs>(Parser_RxMessageReceived_event);

            
            tim.Interval = GUARD_INTERVAL;
            tim.Tick += new EventHandler(tim_Tick);

            show_tim.Interval = SHOW_INTERVAL;
            show_tim.Tick += new EventHandler(show_tim_Tick);
        }


        void show_tim_Tick(object sender, EventArgs e)
        {
            if (this.Interval > (GUARD_INTERVAL * LIVE_TIME))
            {
                if (this.PingChanged_event != null) this.PingChanged_event(this, new LiveControlerArgs(GuardStates.ERROR, GUARD_INTERVAL * LIVE_TIME));
            }
            else if (this.Interval > WARNING_VALUE)
            {
                if (this.PingChanged_event != null) this.PingChanged_event(this, new LiveControlerArgs(GuardStates.ERROR, this.Interval));
            }
            else
            {
                if (this.PingChanged_event != null) this.PingChanged_event(this, new LiveControlerArgs(GuardStates.ERROR, this.Interval));
            }
        }


        void Parser_RxMessageReceived_event(object sender, ParseMessgaeArgs e)
        {
            if (e.Msg_type == RxMsg_types.K_LIVE_OK)
            {
                this.Sended_counter--;
                if (this.Sended_counter > LIVE_TIME)
                {
                    if (this.PingChanged_event != null) this.PingChanged_event(this, new LiveControlerArgs(GuardStates.ERROR, this.Sended_counter * GUARD_INTERVAL));
                }
                else if (this.Sended_counter >= 0)
                {
                    Compute_stats();
                }                
            }
        }

        void tim_Tick(object sender, EventArgs e)
        {
            this.Sender.Send_message(TxMsg_types.P_CHECK_LIVE, null);
            Sended_counter++;
        }

        public void  Start_check()
        {
            this.tim.Enabled = true;
            this.show_tim.Enabled = true;

        }

        public void Stop_check()
        {
            this.tim.Enabled = false;
            this.show_tim.Enabled = false;
        }

        private void Compute_stats()
        {
            if (this.Interval == 0xFFFFFFFF)
            {
                if (this.Sended_counter == 0)
                {
                    this.Interval = GUARD_INTERVAL;
                }
                else
                {
                    this.Interval = Sended_counter * GUARD_INTERVAL;
                }
            }
            else
            {
                if (this.Sended_counter == 0)
                {
                    this.Interval += GUARD_INTERVAL;
                    this.Interval /= 2;
                }
                else
                {
                    this.Interval += Sended_counter * GUARD_INTERVAL;
                    this.Interval /= 2;
                }
            }
        }

    }

    public class LiveControlerArgs : EventArgs
    {
        public GuardStates state;
        public UInt32 Interval; // in ms
        const Int32 GUARD_INTERVAL = LiveControler.GUARD_INTERVAL;
        const Int32 LIVE_TIME = LiveControler.LIVE_TIME; //Doba na odpoved = GUARD_INTERVAL * LIVE_TIME

        public LiveControlerArgs(GuardStates new_state,  UInt32 interval)
        {
            this.state = new_state;
            this.Interval = interval;
        }
    }

    public enum GuardStates
    {
        OK,
        ERROR,
        WARNING
    }
}
