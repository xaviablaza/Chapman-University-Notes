namespace WinForms_ListBox
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
            this.btnEnterName = new System.Windows.Forms.Button();
            this.listboxName = new System.Windows.Forms.ListBox();
            this.btnDeleteName = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.button4 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.button7 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.textBox12 = new System.Windows.Forms.TextBox();
            this.textBox11 = new System.Windows.Forms.TextBox();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.listBox2 = new System.Windows.Forms.ListBox();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnEnterName
            // 
            this.btnEnterName.Location = new System.Drawing.Point(58, 417);
            this.btnEnterName.Name = "btnEnterName";
            this.btnEnterName.Size = new System.Drawing.Size(75, 40);
            this.btnEnterName.TabIndex = 2;
            this.btnEnterName.Text = "Add";
            this.btnEnterName.UseVisualStyleBackColor = true;
            this.btnEnterName.Click += new System.EventHandler(this.btnEnterName_Click);
            // 
            // listboxName
            // 
            this.listboxName.DisplayMember = "(none)";
            this.listboxName.FormattingEnabled = true;
            this.listboxName.Location = new System.Drawing.Point(0, 183);
            this.listboxName.Name = "listboxName";
            this.listboxName.Size = new System.Drawing.Size(432, 186);
            this.listboxName.TabIndex = 3;
            this.listboxName.SelectedIndexChanged += new System.EventHandler(this.listboxName_SelectedIndexChanged);
            // 
            // btnDeleteName
            // 
            this.btnDeleteName.Location = new System.Drawing.Point(284, 417);
            this.btnDeleteName.Name = "btnDeleteName";
            this.btnDeleteName.Size = new System.Drawing.Size(75, 40);
            this.btnDeleteName.TabIndex = 4;
            this.btnDeleteName.Text = "Delete ";
            this.btnDeleteName.UseVisualStyleBackColor = true;
            this.btnDeleteName.Click += new System.EventHandler(this.btnDeleteName_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(172, 417);
            this.button1.Margin = new System.Windows.Forms.Padding(2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(74, 41);
            this.button1.TabIndex = 5;
            this.button1.Text = "View";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(15, 6);
            this.tabControl1.Margin = new System.Windows.Forms.Padding(2);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(432, 488);
            this.tabControl1.TabIndex = 6;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.btnDeleteName);
            this.tabPage1.Controls.Add(this.button1);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.btnEnterName);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.textBox4);
            this.tabPage1.Controls.Add(this.textBox3);
            this.tabPage1.Controls.Add(this.textBox2);
            this.tabPage1.Controls.Add(this.textBox1);
            this.tabPage1.Controls.Add(this.listboxName);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Margin = new System.Windows.Forms.Padding(2);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(2);
            this.tabPage1.Size = new System.Drawing.Size(424, 462);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Book ";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(248, 121);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "Year";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 121);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 13);
            this.label3.TabIndex = 10;
            this.label3.Text = "Genre";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(248, 33);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "Author";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(27, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Title";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(249, 137);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(170, 20);
            this.textBox4.TabIndex = 7;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(5, 137);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(167, 20);
            this.textBox3.TabIndex = 6;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(248, 49);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(171, 20);
            this.textBox2.TabIndex = 5;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(5, 49);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(167, 20);
            this.textBox1.TabIndex = 4;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.button4);
            this.tabPage2.Controls.Add(this.button3);
            this.tabPage2.Controls.Add(this.button2);
            this.tabPage2.Controls.Add(this.textBox8);
            this.tabPage2.Controls.Add(this.textBox7);
            this.tabPage2.Controls.Add(this.textBox6);
            this.tabPage2.Controls.Add(this.textBox5);
            this.tabPage2.Controls.Add(this.label8);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.listBox1);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Margin = new System.Windows.Forms.Padding(2);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(2);
            this.tabPage2.Size = new System.Drawing.Size(424, 462);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Movie ";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(278, 412);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(94, 44);
            this.button4.TabIndex = 11;
            this.button4.Text = "Delete";
            this.button4.UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(54, 412);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(94, 44);
            this.button3.TabIndex = 10;
            this.button3.Text = "Add";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(165, 412);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(94, 45);
            this.button2.TabIndex = 9;
            this.button2.Text = "View";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // textBox8
            // 
            this.textBox8.Location = new System.Drawing.Point(246, 64);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(173, 20);
            this.textBox8.TabIndex = 8;
            // 
            // textBox7
            // 
            this.textBox7.Location = new System.Drawing.Point(5, 64);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(173, 20);
            this.textBox7.TabIndex = 7;
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(246, 141);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(173, 20);
            this.textBox6.TabIndex = 6;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(5, 141);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(170, 20);
            this.textBox5.TabIndex = 5;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(243, 125);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(29, 13);
            this.label8.TabIndex = 4;
            this.label8.Text = "Year";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(2, 125);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(36, 13);
            this.label7.TabIndex = 3;
            this.label7.Text = "Genre";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(243, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(44, 13);
            this.label6.TabIndex = 2;
            this.label6.Text = "Director";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(2, 48);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(27, 13);
            this.label5.TabIndex = 1;
            this.label5.Text = "Title";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(7, 207);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(405, 186);
            this.listBox1.TabIndex = 0;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.button7);
            this.tabPage3.Controls.Add(this.button6);
            this.tabPage3.Controls.Add(this.button5);
            this.tabPage3.Controls.Add(this.textBox12);
            this.tabPage3.Controls.Add(this.textBox11);
            this.tabPage3.Controls.Add(this.textBox10);
            this.tabPage3.Controls.Add(this.textBox9);
            this.tabPage3.Controls.Add(this.label12);
            this.tabPage3.Controls.Add(this.label11);
            this.tabPage3.Controls.Add(this.label10);
            this.tabPage3.Controls.Add(this.label9);
            this.tabPage3.Controls.Add(this.listBox2);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Margin = new System.Windows.Forms.Padding(2);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(424, 462);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Game";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(272, 414);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(99, 44);
            this.button7.TabIndex = 11;
            this.button7.Text = "Delete";
            this.button7.UseVisualStyleBackColor = true;
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(62, 414);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(99, 44);
            this.button6.TabIndex = 10;
            this.button6.Text = "Add";
            this.button6.UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(167, 414);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(99, 44);
            this.button5.TabIndex = 9;
            this.button5.Text = "View";
            this.button5.UseVisualStyleBackColor = true;
            // 
            // textBox12
            // 
            this.textBox12.Location = new System.Drawing.Point(247, 127);
            this.textBox12.Name = "textBox12";
            this.textBox12.Size = new System.Drawing.Size(174, 20);
            this.textBox12.TabIndex = 8;
            // 
            // textBox11
            // 
            this.textBox11.Location = new System.Drawing.Point(3, 74);
            this.textBox11.Name = "textBox11";
            this.textBox11.Size = new System.Drawing.Size(173, 20);
            this.textBox11.TabIndex = 7;
            // 
            // textBox10
            // 
            this.textBox10.Location = new System.Drawing.Point(3, 127);
            this.textBox10.Name = "textBox10";
            this.textBox10.Size = new System.Drawing.Size(173, 20);
            this.textBox10.TabIndex = 6;
            // 
            // textBox9
            // 
            this.textBox9.Location = new System.Drawing.Point(247, 74);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(174, 20);
            this.textBox9.TabIndex = 5;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(254, 111);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(29, 13);
            this.label12.TabIndex = 4;
            this.label12.Text = "Year";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(6, 111);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(36, 13);
            this.label11.TabIndex = 3;
            this.label11.Text = "Genre";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(254, 58);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(56, 13);
            this.label10.TabIndex = 2;
            this.label10.Text = "Developer";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(6, 58);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(27, 13);
            this.label9.TabIndex = 1;
            this.label9.Text = "Title";
            // 
            // listBox2
            // 
            this.listBox2.FormattingEnabled = true;
            this.listBox2.Location = new System.Drawing.Point(9, 181);
            this.listBox2.Name = "listBox2";
            this.listBox2.Size = new System.Drawing.Size(404, 212);
            this.listBox2.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(470, 505);
            this.Controls.Add(this.tabControl1);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "My ListBox Form";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button btnEnterName;
        private System.Windows.Forms.ListBox listboxName;
        private System.Windows.Forms.Button btnDeleteName;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ListBox listBox2;
        private System.Windows.Forms.TextBox textBox12;
        private System.Windows.Forms.TextBox textBox11;
        private System.Windows.Forms.TextBox textBox10;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button5;
    }
}

