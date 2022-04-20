namespace VotingOverlayDesigner
{
    partial class DesignerOverview
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DesignerOverview));
            this.previewWindow = new System.Windows.Forms.WebBrowser();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.propGrid = new System.Windows.Forms.PropertyGrid();
            this.SuspendLayout();
            // 
            // previewWindow
            // 
            this.previewWindow.Dock = System.Windows.Forms.DockStyle.Right;
            this.previewWindow.Location = new System.Drawing.Point(610, 0);
            this.previewWindow.MaximumSize = new System.Drawing.Size(450, 0);
            this.previewWindow.MinimumSize = new System.Drawing.Size(450, 0);
            this.previewWindow.Name = "previewWindow";
            this.previewWindow.ScrollBarsEnabled = false;
            this.previewWindow.Size = new System.Drawing.Size(450, 491);
            this.previewWindow.TabIndex = 0;
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(458, 441);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(126, 38);
            this.btnRefresh.TabIndex = 1;
            this.btnRefresh.Text = "Refresh Preview";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.btnRefresh_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(326, 441);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(126, 38);
            this.btnSave.TabIndex = 1;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            // 
            // propGrid
            // 
            this.propGrid.CommandsVisibleIfAvailable = false;
            this.propGrid.Location = new System.Drawing.Point(12, 12);
            this.propGrid.Name = "propGrid";
            this.propGrid.PropertySort = System.Windows.Forms.PropertySort.Categorized;
            this.propGrid.Size = new System.Drawing.Size(572, 423);
            this.propGrid.TabIndex = 2;
            // 
            // DesignerOverview
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1060, 491);
            this.Controls.Add(this.propGrid);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.previewWindow);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximumSize = new System.Drawing.Size(1076, 530);
            this.MinimumSize = new System.Drawing.Size(1076, 530);
            this.Name = "DesignerOverview";
            this.Text = "Voting Designer";
            this.Load += new System.EventHandler(this.DesignerOverview_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.WebBrowser previewWindow;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.PropertyGrid propGrid;
    }
}

