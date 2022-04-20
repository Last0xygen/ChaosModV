using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VotingOverlayDesigner.Resources
{
    internal class CssSettings
    {

        private string textFontFamily = "Arial";
        private Color textColor = Color.White;
        private int textFontWeight = 600;
        private Color textOutlineColor = Color.Black;
        private float textOutlineThickness = 1.3f;
        private int textSize = 22;

        private Color barBackgroundDisabledColor;
        private Color barBackgroundColor;
        private string barFontSize = "14";
        private string barFontWeight = "600";
        private string barFont = "Arial";
        private string barHeight = "35";
        private string barWidth = "450";
        private int barBorderRadius = 0;
        private Color barTextColorDisabled;
        private Color barTextColor;
        private Color barTextOutlineColor = Color.White;
        private int barTextOutlineThickness = 0;
        private Color barBorderColor;
        private bool barBorderEnabled = false;

        private Color barProgressionDisabledColor;
        private Color barProgressionColor;
        private int barProgressionBorderRadius = 0;

        internal CssSettings()
        {
            ColorConverter converter = new ColorConverter();
            this.barBackgroundDisabledColor = (Color)converter.ConvertFromString("#afafaf");

            this.barBackgroundColor = (Color)converter.ConvertFromString("#727272");
            this.barTextColorDisabled = (Color)converter.ConvertFromString("#f3f3f3");
            this.barTextColor = (Color)converter.ConvertFromString("#f1f1f1");
            this.barBorderColor = (Color)converter.ConvertFromString("#00B4FFf0");
            this.barProgressionDisabledColor = (Color)converter.ConvertFromString("#8d8d8d");
            this.barProgressionColor = (Color)converter.ConvertFromString("#238beb");
        }




        #region Total Votes

        [CategoryAttribute("Total Votes Text Settings"), DescriptionAttribute("The font family to be used, has to be installed on the computer")]
        public string TextFontFamily
        {
            get { return textFontFamily; }
            set { textFontFamily = value; }
        }

        [CategoryAttribute("Total Votes Text Settings"), DescriptionAttribute("The color to use for the text")]
        public Color TextColor
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
        public Color TextOutlineColor
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
        public Color BarBackgroundDisabledColor
        {
            get { return barBackgroundDisabledColor; }
            set { barBackgroundDisabledColor = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The color to use for the bar background")]
        public Color BarBackgroundColor
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
        public Color BarTextColorDisabled
        {
            get { return barTextColorDisabled; }
            set { barTextColorDisabled = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The text color within the bars")]
        public Color BarTextColor
        {
            get { return barTextColor; }
            set { barTextColor = value; }
        }

        [CategoryAttribute("Bar Settings"), DescriptionAttribute("The outline color for text within the bars")]
        public Color BarTextOutlineColor
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
        public Color BarBorderColor
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
        public Color BarProgressionDisabledColor
        {
            get { return barProgressionDisabledColor; }
            set { barProgressionDisabledColor = value; }
        }

        [CategoryAttribute("Progress Bar Settings"), DescriptionAttribute("The color to use for a progress bar")]
        public Color BarProgressionColor
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
