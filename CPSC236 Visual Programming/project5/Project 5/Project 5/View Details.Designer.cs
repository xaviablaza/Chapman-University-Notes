namespace Project_5
{
    partial class View_Details
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
            this.label1 = new System.Windows.Forms.Label();
            this.firstNameText = new System.Windows.Forms.Label();
            this.lastNameText = new System.Windows.Forms.Label();
            this.addressText = new System.Windows.Forms.Label();
            this.birthDateText = new System.Windows.Forms.Label();
            this.bloodTypeText = new System.Windows.Forms.Label();
            this.goBacktoForm1 = new System.Windows.Forms.Button();
            this.phoneNumText = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F);
            this.label1.Location = new System.Drawing.Point(6, 14);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(224, 39);
            this.label1.TabIndex = 0;
            this.label1.Text = "Donor Details";
            // 
            // firstNameText
            // 
            this.firstNameText.AutoSize = true;
            this.firstNameText.Location = new System.Drawing.Point(76, 59);
            this.firstNameText.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.firstNameText.Name = "firstNameText";
            this.firstNameText.Size = new System.Drawing.Size(57, 13);
            this.firstNameText.TabIndex = 1;
            this.firstNameText.Text = "First Name";
            // 
            // lastNameText
            // 
            this.lastNameText.AutoSize = true;
            this.lastNameText.Location = new System.Drawing.Point(10, 59);
            this.lastNameText.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lastNameText.Name = "lastNameText";
            this.lastNameText.Size = new System.Drawing.Size(58, 13);
            this.lastNameText.TabIndex = 2;
            this.lastNameText.Text = "Last Name";
            // 
            // addressText
            // 
            this.addressText.AutoSize = true;
            this.addressText.Location = new System.Drawing.Point(10, 82);
            this.addressText.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.addressText.Name = "addressText";
            this.addressText.Size = new System.Drawing.Size(48, 13);
            this.addressText.TabIndex = 3;
            this.addressText.Text = "Address ";
            // 
            // birthDateText
            // 
            this.birthDateText.AutoSize = true;
            this.birthDateText.Location = new System.Drawing.Point(10, 106);
            this.birthDateText.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.birthDateText.Name = "birthDateText";
            this.birthDateText.Size = new System.Drawing.Size(45, 13);
            this.birthDateText.TabIndex = 4;
            this.birthDateText.Text = "Birthday";
            // 
            // bloodTypeText
            // 
            this.bloodTypeText.AutoSize = true;
            this.bloodTypeText.Font = new System.Drawing.Font("Microsoft Sans Serif", 30F);
            this.bloodTypeText.Location = new System.Drawing.Point(302, 72);
            this.bloodTypeText.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.bloodTypeText.Name = "bloodTypeText";
            this.bloodTypeText.Size = new System.Drawing.Size(234, 46);
            this.bloodTypeText.TabIndex = 5;
            this.bloodTypeText.Text = "Blood Type ";
            // 
            // goBacktoForm1
            // 
            this.goBacktoForm1.Location = new System.Drawing.Point(188, 208);
            this.goBacktoForm1.Margin = new System.Windows.Forms.Padding(2);
            this.goBacktoForm1.Name = "goBacktoForm1";
            this.goBacktoForm1.Size = new System.Drawing.Size(170, 25);
            this.goBacktoForm1.TabIndex = 6;
            this.goBacktoForm1.Text = "Go Back";
            this.goBacktoForm1.UseVisualStyleBackColor = true;
            this.goBacktoForm1.Click += new System.EventHandler(this.goBacktoForm1_Click);
            // 
            // phoneNumText
            // 
            this.phoneNumText.AutoSize = true;
            this.phoneNumText.Location = new System.Drawing.Point(13, 133);
            this.phoneNumText.Name = "phoneNumText";
            this.phoneNumText.Size = new System.Drawing.Size(35, 13);
            this.phoneNumText.TabIndex = 7;
            this.phoneNumText.Text = "label2";
            // 
            // View_Details
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(554, 249);
            this.Controls.Add(this.phoneNumText);
            this.Controls.Add(this.goBacktoForm1);
            this.Controls.Add(this.bloodTypeText);
            this.Controls.Add(this.birthDateText);
            this.Controls.Add(this.addressText);
            this.Controls.Add(this.lastNameText);
            this.Controls.Add(this.firstNameText);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "View_Details";
            this.Text = "View_Details";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label firstNameText;
        private System.Windows.Forms.Label lastNameText;
        private System.Windows.Forms.Label addressText;
        private System.Windows.Forms.Label birthDateText;
        private System.Windows.Forms.Label bloodTypeText;
        private System.Windows.Forms.Button goBacktoForm1;
        private System.Windows.Forms.Label phoneNumText;
    }
}