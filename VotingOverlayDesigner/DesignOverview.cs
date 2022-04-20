using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Reflection;
using VotingOverlayDesigner.Resources;

namespace VotingOverlayDesigner
{
    public partial class DesignerOverview : Form
    {

        public DesignerOverview()
        {
            InitializeComponent();

            CssSettings sett = new CssSettings();
            propGrid.SelectedObject = sett;
            propGrid.PropertyValueChanged += propertyValueChanged;
        }

        private void propertyValueChanged(object s, PropertyValueChangedEventArgs e)
        {
            this.loadHtml();
        }

        private void DesignerOverview_Load(object sender, EventArgs e)
        {
            this.loadHtml();
        }


        private void btnRefresh_Click(object sender, EventArgs e)
        {
            this.loadHtml();
        }

        private void loadHtml()
        {
            createCss();
            string appDir = Path.GetDirectoryName(
                Assembly.GetExecutingAssembly().GetName().CodeBase);
            this.previewWindow.Url = new Uri(Path.Combine(appDir, @"Resources/test.html"));

        }

        private string getColorString(Color forColor)
        {
            return $"#{forColor.R:X2}{forColor.G:X2}{forColor.B:X2}";
        }

        private void createCss()
        {
            string appDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string cssPath = Path.Combine(appDir, "Resources\\testBase.css");

            String css = File.ReadAllText(cssPath);

            CssSettings settings = (CssSettings)this.propGrid.SelectedObject;

            css = css.Replace("##text-color##", getColorString(settings.TextColor));
            css = css.Replace("##text-font-family##", settings.TextFontFamily);
            css = css.Replace("##text-font-weight##", settings.TextFontWeight.ToString());
            css = css.Replace("##text-outline-color##", getColorString(settings.TextOutlineColor));
            css = css.Replace("##text-outline-thickness##", string.Format("{0:N3}", settings.TextOutlineThickness));
            css = css.Replace("##text-size##", settings.TextSize.ToString());
            css = css.Replace("##bar-background-disabled##", getColorString(settings.BarBackgroundDisabledColor));
            css = css.Replace("##bar-background##", getColorString(settings.BarBackgroundColor));
            css = css.Replace("##bar-font-size##", settings.BarFontSize);
            css = css.Replace("##bar-font-weight##", settings.BarFontWeight);
            css = css.Replace("##bar-font##", settings.BarFont);
            css = css.Replace("##bar-height##", settings.BarHeight);
            css = css.Replace("##bar-width##", settings.BarWidth);
            css = css.Replace("##bar-progression-disabled##", getColorString(settings.BarProgressionDisabledColor));
            css = css.Replace("##bar-progression##", getColorString(settings.BarProgressionColor));
            css = css.Replace("##bar-text-color-disabled##", getColorString(settings.BarTextColorDisabled));
            css = css.Replace("##bar-text-color##", getColorString(settings.BarTextColor));
            css = css.Replace("##bar-text-outline-color##", getColorString(settings.BarTextOutlineColor));
            css = css.Replace("##bar-text-outline-thickness##", settings.BarTextOutlineThickness.ToString());
            css = css.Replace("##bar-border-radius##", settings.BarBorderRadius.ToString());
            css = css.Replace("##bar-progression-border-radius##", settings.BarProgressionBorderRadius.ToString());
            css = css.Replace("##bar-border-color##", getColorString(settings.BarBorderColor));
            css = css.Replace("##border-type##", settings.BarBorderEnabled ? "solid" : "none");

            string testPath = Path.Combine(appDir, "Resources\\test.css");

            File.WriteAllText(testPath, css);



        }

    }
}
