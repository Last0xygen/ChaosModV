using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VotingOverlayDesigner.Resources
{
    internal class AppSettCssSettingsings
    {


        private bool saveOnClose = true;
        private string greetingText = "Welcome to your application!";
        private int itemsInMRU = 4;
        private int maxRepeatRate = 10;
        private bool settingsChanged = false;
        private string appVersion = "1.0";

        public bool SaveOnClose
        {
            get { return saveOnClose; }
            set { saveOnClose = value; }
        }
        public string GreetingText
        {
            get { return greetingText; }
            set { greetingText = value; }
        }
        public int MaxRepeatRate
        {
            get { return maxRepeatRate; }
            set { maxRepeatRate = value; }
        }
        public int ItemsInMRUList
        {
            get { return itemsInMRU; }
            set { itemsInMRU = value; }
        }
        public bool SettingsChanged
        {
            get { return settingsChanged; }
            set { settingsChanged = value; }
        }
        public string AppVersion
        {
            get { return appVersion; }
            set { appVersion = value; }
        }
    }
}
