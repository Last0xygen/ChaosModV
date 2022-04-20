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

        private void createCss()
        {
            string appDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string cssPath = Path.Combine(appDir, "Resources\\testBase.css");

            String css = File.ReadAllText(cssPath);


            bool borderEnabled = false;


            //css = css.Replace("##text-color##", "#ffffff");
            //css = css.Replace("##text-font-family##", "'Arial'");
            //css = css.Replace("##text-font-weight##", "600");
            //css = css.Replace("##text-outline-color##", "#000000");
            //css = css.Replace("##text-outline-thickness##", "1.3");
            //css = css.Replace("##text-size##", "22");
            //css = css.Replace("##bar-background-disabled##", "#afafaf");
            //css = css.Replace("##bar-background##", "#727272");
            //css = css.Replace("##bar-font-size##", "14");
            //css = css.Replace("##bar-font-weight##", "600");
            //css = css.Replace("##bar-font##", "'Arial'");
            //css = css.Replace("##bar-height##", "35");
            //css = css.Replace("##bar-width##", "450");
            //css = css.Replace("##bar-progression-disabled##", "#8d8d8d");
            //css = css.Replace("##bar-progression##", "#238beb");
            //css = css.Replace("##bar-text-color-disabled##", "#f3f3f3");
            //css = css.Replace("##bar-text-color##", "#f1f1f1");
            //css = css.Replace("##bar-text-outline-color##", "#000000");
            //css = css.Replace("##bar-text-outline-thickness##", "0");
            //css = css.Replace("##bar-border-radius##", "0");
            //css = css.Replace("##bar-progression-border-radius##", "0");
            //css = css.Replace("##bar-border-color##", "#00B4FFf0");
            //css = css.Replace("##border-type##", borderEnabled ? "solid" : "none");

            CssSettings settings = (CssSettings)this.propGrid.SelectedObject;

            css = css.Replace("##text-color##", settings.TextColor);
            css = css.Replace("##text-font-family##", settings.TextFontFamily);
            css = css.Replace("##text-font-weight##", settings.TextFontWeight.ToString());
            css = css.Replace("##text-outline-color##", settings.TextOutlineColor);
            css = css.Replace("##text-outline-thickness##", string.Format("{0:N3}", settings.TextOutlineThickness));
            css = css.Replace("##text-size##", settings.TextSize.ToString());
            css = css.Replace("##bar-background-disabled##", settings.BarBackgroundDisabledColor);
            css = css.Replace("##bar-background##", settings.BarBackgroundColor);
            css = css.Replace("##bar-font-size##", settings.BarFontSize);
            css = css.Replace("##bar-font-weight##", settings.BarFontWeight);
            css = css.Replace("##bar-font##", settings.BarFont);
            css = css.Replace("##bar-height##", settings.BarHeight);
            css = css.Replace("##bar-width##", settings.BarWidth);
            css = css.Replace("##bar-progression-disabled##", settings.BarProgressionDisabledColor);
            css = css.Replace("##bar-progression##", settings.BarProgressionColor);
            css = css.Replace("##bar-text-color-disabled##", settings.BarTextColorDisabled);
            css = css.Replace("##bar-text-color##", settings.BarTextColor);
            css = css.Replace("##bar-text-outline-color##", settings.BarTextOutlineColor);
            css = css.Replace("##bar-text-outline-thickness##", settings.BarTextOutlineThickness.ToString());
            css = css.Replace("##bar-border-radius##", settings.BarBorderRadius.ToString());
            css = css.Replace("##bar-progression-border-radius##", settings.BarProgressionBorderRadius.ToString());
            css = css.Replace("##bar-border-color##", settings.BarBorderColor);
            css = css.Replace("##border-type##", settings.BarBorderEnabled ? "solid" : "none");

            string testPath = Path.Combine(appDir, "Resources\\test.css");

            File.WriteAllText(testPath, css);



        }

    }
}
