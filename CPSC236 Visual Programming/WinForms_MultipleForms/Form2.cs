using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms_MultipleForms
{
    public partial class Form2 : Form
    {
        Form1 form1ref; // A reference to Form1 - you just declare it as a global variable for this class

        public Form2(Form1 form1ref)
        {
            this.form1ref = form1ref; // Assign the Form1 parameter passed from Form1 to the Form2 reference variable
            InitializeComponent();
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            // To access Form1's labelForm2Response object, in Form1.Designer.cs, change the object from private to public
            this.form1ref.labelForm2Response.Text = textForm2.Text;
        }

        private void buttonCloseForm2_Click(object sender, EventArgs e)
        {
            // Trigger the Close event for Form2
            this.Close();
        }
    }
}
