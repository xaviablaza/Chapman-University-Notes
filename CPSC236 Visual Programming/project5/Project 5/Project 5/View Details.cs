using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project_5
{
    public partial class View_Details : Form
    {
        Form1 form1ref; // This is a reference to Form1
        public View_Details(Form1 form1ref, Donor donor)
        {
            InitializeComponent();
            this.form1ref = form1ref;

            // Fill out the fields
            lastNameText.Text = donor.LastName + ",";
            firstNameText.Text = donor.FirstName;
            addressText.Text = donor.Address;
            birthDateText.Text = donor.Birthdate.ToShortDateString();
            phoneNumText.Text = donor.Phone.ToString();
            bloodTypeText.Text = donor.Blood.ToFormattedString();
        }

        private void goBacktoForm1_Click(object sender, EventArgs e)
        {
            // Trigger the Close event for the ViewForm
            this.Close();
        }
    }
}
