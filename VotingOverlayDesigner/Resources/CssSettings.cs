using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VotingOverlayDesigner.Resources
{
    internal class CssSettings
    {

        private string textFontFamily = "Arial";
        private string textColor = "#ffffff";
        private int textFontWeight = 600;
        private string textOutlineColor = "#000000";
        private float textOutlineThickness = 1.3f;
        private int textSize = 22;

        private string barBackgroundDisabledColor = "#afafaf";
        private string barBackgroundColor = "#727272";
        private string barFontSize = "14";
        private string barFontWeight = "600";
        private string barFont = "Arial";
        private string barHeight = "35";
        private string barWidth = "450";
        private int barBorderRadius = 0;
        private string barTextColorDisabled = "#f3f3f3";
        private string barTextColor = "#f1f1f1";
        private string barTextOutlineColor = "#000000";
        private int barTextOutlineThickness = 0;
        private string barBorderColor = "#00B4FFf0";
        private bool barBorderEnabled = false;

        private string barProgressionDisabledColor = "#8d8d8d";
        private string barProgressionColor = "#238beb";
        private int barProgressionBorderRadius = 0;


        #region Total Votes

        [CategoryAttribute("Total Votes Text Settings"), DescriptionAttribute("The font family to be used, has to be installed on the computer")]
        public string TextFontFamily
        {
            get { return textFontFamily; }
            set { textFontFamily = value; }
        }

        [CategoryAttribute("Total Votes Text Settings"), DescriptionAttribute("The color to use for the text")]
        public string TextColor
        {
            get { return textColor; }
            set { textColor = value; }
        }

        [CategoryAttribute("Total Votes Text Settings"), DescriptionAttribute("The text font weight")]
        public int TextFontWeight
        {
            get { return textFontWeight; }
            set { textFontWeight = value; }
        }

        [CategoryAttribute("Total Votes Text Settings"), DescriptionAttribute("The color to use for the text outline")]
        public string TextOutlineColor
        {
            get { return textOutlineColor; }
            set { textOutlineColor = value; }
        }

        [CategoryAttribute("Text Settings"), DescriptionAttribute("The thickness of text outline")]
        public float TextOutlineThickness
        {
            get { return textOutlineThickness; }
            set { textOutlineThickness = value; }
        }

        [CategoryAttribute("Text Settings"), DescriptionAttribute("The text size... you know, the size of the text.")]
        public int TextSize
        {
            get { return textSize; }
            set { textSize = value; }
        }

        #endregion

        #region Bar

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The color to use for a disabled bar")]
        public string BarBackgroundDisabledColor
        {
            get { return barBackgroundDisabledColor; }
            set { barBackgroundDisabledColor = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The color to use for the bar background")]
        public string BarBackgroundColor
        {
            get { return barBackgroundColor; }
            set { barBackgroundColor = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The font size used within the bars")]
        public string BarFontSize
        {
            get { return barFontSize; }
            set { barFontSize = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The font weight used within the bars")]
        public string BarFontWeight
        {
            get { return barFontWeight; }
            set { barFontWeight = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The font family to be used, has to be installed on the computer")]
        public string BarFont
        {
            get { return barFont; }
            set { barFont = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The height of each bar")]
        public string BarHeight
        {
            get { return barHeight; }
            set { barHeight = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The width of all bars")]
        public string BarWidth
        {
            get { return barWidth; }
            set { barWidth = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The border radius to use for all bars")]
        public int BarBorderRadius
        {
            get { return barBorderRadius; }
            set { barBorderRadius = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The text color if bar is disabled")]
        public string BarTextColorDisabled
        {
            get { return barTextColorDisabled; }
            set { barTextColorDisabled = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The text color within the bars")]
        public string BarTextColor
        {
            get { return barTextColor; }
            set { barTextColor = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The outline color for text within the bars")]
        public string BarTextOutlineColor
        {
            get { return barTextOutlineColor; }
            set { barTextOutlineColor = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The outline thickness for text within the bars")]
        public int BarTextOutlineThickness
        {
            get { return barTextOutlineThickness; }
            set { barTextOutlineThickness = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The border color for the bars")]
        public string BarBorderColor
        {
            get { return barBorderColor; }
            set { barBorderColor = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("Enabled Borders for the bars")]
        public bool BarBorderEnabled
        {
            get { return barBorderEnabled; }
            set { barBorderEnabled = value; }
        }
        #endregion

        #region Progress Bar


        [CategoryAttribute("Progress Bar Settings"), DescriptionAttribute("The color to use for a disabled progress bar")]
        public string BarProgressionDisabledColor
        {
            get { return barProgressionDisabledColor; }
            set { barProgressionDisabledColor = value; }
        }

        [CategoryAttribute("Progress Bar Settings"), DescriptionAttribute("The color to use for a progress bar")]
        public string BarProgressionColor
        {
            get { return barProgressionColor; }
            set { barProgressionColor = value; }
        }

        [CategoryAttribute("Progress Bar Settings"), DescriptionAttribute("The border radius to use for a progress bar")]
        public int BarProgressionBorderRadius
        {
            get { return barProgressionBorderRadius; }
            set { barProgressionBorderRadius = value; }
        }

        #endregion
    }
}
