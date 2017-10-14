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
    public partial class Form1 : Form
    {
        Form2 form2; // A way to control Form2 from Form1

        public Form1()
        {
            form2 = new Form2(this); // Create a new instance of Form2, to manage from Form1, 
            //that can reference Form1 by passing it in as a parameter
            InitializeComponent();
        }

        private void btnOpenForm2_Click(object sender, EventArgs e)
        {
            this.form2.ShowDialog(); // Show the Form2 window
        }
    }
}
