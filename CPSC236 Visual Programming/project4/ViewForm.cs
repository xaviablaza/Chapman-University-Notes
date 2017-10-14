using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms_ListBox
{
    public partial class ViewForm : Form
    {
        Form1 form1ref; // This is a reference to Form1
        public ViewForm(Form1 form1ref)
        {
            this.form1ref = form1ref;
            InitializeComponent();
        }
    }
}
