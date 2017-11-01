namespace Project_5
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.donorListBox = new System.Windows.Forms.ListBox();
            this.viewData = new System.Windows.Forms.Button();
            this.delete = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.firstNameText = new System.Windows.Forms.TextBox();
            this.lastNameText = new System.Windows.Forms.TextBox();
            this.addressLabel = new System.Windows.Forms.Label();
            this.addressText = new System.Windows.Forms.TextBox();
            this.phoneLabel = new System.Windows.Forms.Label();
            this.phoneNumText = new System.Windows.Forms.TextBox();
            this.addButton = new System.Windows.Forms.Button();
            this.changeDataOpen = new System.Windows.Forms.Button();
            this.birthdatePicker = new System.Windows.Forms.DateTimePicker();
            this.bloodTypePicker = new System.Windows.Forms.ComboBox();
            this.errorLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.SuspendLayout();
            // 
            // chart1
            // 
            chartArea1.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea1);
            this.chart1.Location = new System.Drawing.Point(422, 20);
            this.chart1.Margin = new System.Windows.Forms.Padding(2);
            this.chart1.Name = "chart1";
            series1.ChartArea = "ChartArea1";
            series1.Name = "BBR";
            series1.YValueType = System.Windows.Forms.DataVisualization.Charting.ChartValueType.Single;
            this.chart1.Series.Add(series1);
            this.chart1.Size = new System.Drawing.Size(401, 505);
            this.chart1.TabIndex = 0;
            // 
            // donorListBox
            // 
            this.donorListBox.FormattingEnabled = true;
            this.donorListBox.Location = new System.Drawing.Point(7, 209);
            this.donorListBox.Margin = new System.Windows.Forms.Padding(2);
            this.donorListBox.Name = "donorListBox";
            this.donorListBox.Size = new System.Drawing.Size(399, 290);
            this.donorListBox.TabIndex = 1;
            // 
            // viewData
            // 
            this.viewData.Location = new System.Drawing.Point(21, 506);
            this.viewData.Margin = new System.Windows.Forms.Padding(2);
            this.viewData.Name = "viewData";
            this.viewData.Size = new System.Drawing.Size(109, 27);
            this.viewData.TabIndex = 2;
            this.viewData.Text = "View Data";
            this.viewData.UseVisualStyleBackColor = true;
            this.viewData.Click += new System.EventHandler(this.viewData_Click);
            // 
            // delete
            // 
            this.delete.Location = new System.Drawing.Point(287, 506);
            this.delete.Margin = new System.Windows.Forms.Padding(2);
            this.delete.Name = "delete";
            this.delete.Size = new System.Drawing.Size(105, 28);
            this.delete.TabIndex = 3;
            this.delete.Text = "Delete ";
            this.delete.UseVisualStyleBackColor = true;
            this.delete.Click += new System.EventHandler(this.delete_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 136);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 13);
            this.label1.TabIndex = 9;
            this.label1.Text = "Date of Birth";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(236, 94);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 13);
            this.label2.TabIndex = 10;
            this.label2.Text = "Blood Type";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 11);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(57, 13);
            this.label3.TabIndex = 11;
            this.label3.Text = "First Name";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(236, 11);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(58, 13);
            this.label4.TabIndex = 12;
            this.label4.Text = "Last Name";
            // 
            // firstNameText
            // 
            this.firstNameText.Location = new System.Drawing.Point(7, 27);
            this.firstNameText.Margin = new System.Windows.Forms.Padding(2);
            this.firstNameText.Name = "firstNameText";
            this.firstNameText.Size = new System.Drawing.Size(164, 20);
            this.firstNameText.TabIndex = 13;
            // 
            // lastNameText
            // 
            this.lastNameText.Location = new System.Drawing.Point(238, 27);
            this.lastNameText.Margin = new System.Windows.Forms.Padding(2);
            this.lastNameText.Name = "lastNameText";
            this.lastNameText.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.lastNameText.Size = new System.Drawing.Size(167, 20);
            this.lastNameText.TabIndex = 14;
            // 
            // addressLabel
            // 
            this.addressLabel.AutoSize = true;
            this.addressLabel.Location = new System.Drawing.Point(6, 50);
            this.addressLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.addressLabel.Name = "addressLabel";
            this.addressLabel.Size = new System.Drawing.Size(45, 13);
            this.addressLabel.TabIndex = 15;
            this.addressLabel.Text = "Address";
            // 
            // addressText
            // 
            this.addressText.Location = new System.Drawing.Point(7, 70);
            this.addressText.Margin = new System.Windows.Forms.Padding(2);
            this.addressText.Name = "addressText";
            this.addressText.Size = new System.Drawing.Size(399, 20);
            this.addressText.TabIndex = 16;
            // 
            // phoneLabel
            // 
            this.phoneLabel.AutoSize = true;
            this.phoneLabel.Location = new System.Drawing.Point(6, 94);
            this.phoneLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.phoneLabel.Name = "phoneLabel";
            this.phoneLabel.Size = new System.Drawing.Size(78, 13);
            this.phoneLabel.TabIndex = 17;
            this.phoneLabel.Text = "Phone Number";
            // 
            // phoneNumText
            // 
            this.phoneNumText.Location = new System.Drawing.Point(8, 108);
            this.phoneNumText.Margin = new System.Windows.Forms.Padding(2);
            this.phoneNumText.Name = "phoneNumText";
            this.phoneNumText.Size = new System.Drawing.Size(162, 20);
            this.phoneNumText.TabIndex = 18;
            // 
            // addButton
            // 
            this.addButton.Location = new System.Drawing.Point(238, 152);
            this.addButton.Margin = new System.Windows.Forms.Padding(2);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(166, 20);
            this.addButton.TabIndex = 19;
            this.addButton.Text = "Add";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // changeDataOpen
            // 
            this.changeDataOpen.Location = new System.Drawing.Point(154, 507);
            this.changeDataOpen.Margin = new System.Windows.Forms.Padding(2);
            this.changeDataOpen.Name = "changeDataOpen";
            this.changeDataOpen.Size = new System.Drawing.Size(104, 27);
            this.changeDataOpen.TabIndex = 21;
            this.changeDataOpen.Text = "Change Data";
            this.changeDataOpen.UseVisualStyleBackColor = true;
            this.changeDataOpen.Click += new System.EventHandler(this.changeDataOpen_Click);
            // 
            // birthdatePicker
            // 
            this.birthdatePicker.Location = new System.Drawing.Point(7, 152);
            this.birthdatePicker.Name = "birthdatePicker";
            this.birthdatePicker.Size = new System.Drawing.Size(200, 20);
            this.birthdatePicker.TabIndex = 22;
            // 
            // bloodTypePicker
            // 
            this.bloodTypePicker.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.bloodTypePicker.FormattingEnabled = true;
            this.bloodTypePicker.Items.AddRange(new object[] {
            "O+",
            "O-",
            "A+",
            "A-",
            "B+",
            "B-",
            "AB+",
            "AB-"});
            this.bloodTypePicker.Location = new System.Drawing.Point(239, 110);
            this.bloodTypePicker.Name = "bloodTypePicker";
            this.bloodTypePicker.Size = new System.Drawing.Size(167, 21);
            this.bloodTypePicker.TabIndex = 23;
            // 
            // errorLabel
            // 
            this.errorLabel.AutoSize = true;
            this.errorLabel.Location = new System.Drawing.Point(8, 184);
            this.errorLabel.Name = "errorLabel";
            this.errorLabel.Size = new System.Drawing.Size(0, 13);
            this.errorLabel.TabIndex = 24;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(835, 545);
            this.Controls.Add(this.errorLabel);
            this.Controls.Add(this.bloodTypePicker);
            this.Controls.Add(this.birthdatePicker);
            this.Controls.Add(this.changeDataOpen);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.phoneNumText);
            this.Controls.Add(this.phoneLabel);
            this.Controls.Add(this.addressText);
            this.Controls.Add(this.addressLabel);
            this.Controls.Add(this.lastNameText);
            this.Controls.Add(this.firstNameText);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.delete);
            this.Controls.Add(this.viewData);
            this.Controls.Add(this.donorListBox);
            this.Controls.Add(this.chart1);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Blood Bank Tracker";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing_1);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.ListBox donorListBox;
        private System.Windows.Forms.Button viewData;
        private System.Windows.Forms.Button delete;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox firstNameText;
        private System.Windows.Forms.TextBox lastNameText;
        private System.Windows.Forms.Label addressLabel;
        private System.Windows.Forms.TextBox addressText;
        private System.Windows.Forms.Label phoneLabel;
        private System.Windows.Forms.TextBox phoneNumText;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button changeDataOpen;
        private System.Windows.Forms.DateTimePicker birthdatePicker;
        private System.Windows.Forms.ComboBox bloodTypePicker;
        private System.Windows.Forms.Label errorLabel;
    }
}

