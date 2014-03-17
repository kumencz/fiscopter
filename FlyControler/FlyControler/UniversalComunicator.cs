using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FlyControler
{
    class UniversalComunicator
    {
        public RxParser SSH_RX = new RxParser();
        public TxSender SSH_TX = new TxSender(); 

        public UniversalComunicator()
        {
        }

        public void  Connect(string connecting_text)
        {
            if (String.Compare(connecting_text.Substring(0, 3), "COM") == 0) //Srerial port connection
            {
            }
            else // IP connection
            {
                this.SSH_RX.SSH_Connect(connecting_text);
                this.SSH_TX.SSH_Connect(connecting_text);
            }
        }

        public void Disconect()
        {
        }
    }
}
