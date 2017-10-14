namespace WinForms_MultipleForms
{
    partial class Form2
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
            this.textForm2 = new System.Windows.Forms.TextBox();
            this.buttonCloseForm2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textForm2
            // 
            this.textForm2.Location = new System.Drawing.Point(12, 12);
            this.textForm2.Name = "textForm2";
            this.textForm2.Size = new System.Drawing.Size(100, 20);
            this.textForm2.TabIndex = 0;
            // 
            // buttonCloseForm2
            // 
            this.buttonCloseForm2.Location = new System.Drawing.Point(12, 38);
            this.buttonCloseForm2.Name = "buttonCloseForm2";
            this.buttonCloseForm2.Size = new System.Drawing.Size(100, 23);
            this.buttonCloseForm2.TabIndex = 1;
            this.buttonCloseForm2.Text = "Update Form1";
            this.buttonCloseForm2.UseVisualStyleBackColor = true;
            this.buttonCloseForm2.Click += new System.EventHandler(this.buttonCloseForm2_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(194, 81);
            this.Controls.Add(this.buttonCloseForm2);
            this.Controls.Add(this.textForm2);
            this.Name = "Form2";
            this.Text = "Form2";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form2_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textForm2;
        private System.Windows.Forms.Button buttonCloseForm2;
    }
}