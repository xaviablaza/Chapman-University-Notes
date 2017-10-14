namespace WinForms_MultipleForms
{
    partial class Form1
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
            this.btnOpenForm2 = new System.Windows.Forms.Button();
            this.labelForm2Response = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnOpenForm2
            // 
            this.btnOpenForm2.Location = new System.Drawing.Point(15, 12);
            this.btnOpenForm2.Name = "btnOpenForm2";
            this.btnOpenForm2.Size = new System.Drawing.Size(75, 23);
            this.btnOpenForm2.TabIndex = 0;
            this.btnOpenForm2.Text = "Open Form2";
            this.btnOpenForm2.UseVisualStyleBackColor = true;
            this.btnOpenForm2.Click += new System.EventHandler(this.btnOpenForm2_Click);
            // 
            // labelForm2Response
            // 
            this.labelForm2Response.AutoSize = true;
            this.labelForm2Response.Location = new System.Drawing.Point(12, 52);
            this.labelForm2Response.Name = "labelForm2Response";
            this.labelForm2Response.Size = new System.Drawing.Size(0, 13);
            this.labelForm2Response.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 87);
            this.Controls.Add(this.labelForm2Response);
            this.Controls.Add(this.btnOpenForm2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnOpenForm2;
        public System.Windows.Forms.Label labelForm2Response;
    }
}

