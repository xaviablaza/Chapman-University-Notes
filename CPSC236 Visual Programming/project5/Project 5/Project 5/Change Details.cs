using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project_5
{
    public partial class Change_Details : Form
    {
        Form1 form1ref;
        Donor oldDonor;
        public Change_Details(Form1 form1ref, Donor donor)
        {
            InitializeComponent();
            this.form1ref = form1ref;
            oldDonor = donor;
            lastNameText.Text = donor.LastName;
            firstNameText.Text = donor.FirstName;
            addressText.Text = donor.Address;
            birthdatePicker.Value = donor.Birthdate;
            phoneNumText.Text = donor.Phone.ToString();
            bloodTypePicker.Text = donor.Blood.ToFormattedString();
        }

        private void change_Click(object sender, EventArgs e)
        {
            // Get the data from the input fields
            string firstName = firstNameText.Text.ToString().Trim();
            string lastName = lastNameText.Text.ToString().Trim();
            string address = addressText.Text.ToString().Trim();
            string phoneNum = phoneNumText.Text.ToString().Trim();
            string bloodType = bloodTypePicker.Text.ToString();
            DateTime birthdate = birthdatePicker.Value.Date;

            // Check if all fields have been filled out
            if (firstName == "" || lastName == "" || address == "" || phoneNum == "" || bloodType == "")
            {
                errorLabel.Text = "All fields must be filled out before adding new record.";
            }
            // Check if phone number only contains numbers
            else if (Regex.Match(phoneNum, @"[a-zA-Z]").Success)
            {
                errorLabel.Text = "Phone number is not valid.";
            }
            // Add the new donor
            else
            {
                // Reset the input fields
                errorLabel.Text = "";
                firstNameText.Text = "";
                lastNameText.Text = "";
                addressText.Text = "";
                phoneNumText.Text = "";
                bloodTypePicker.Text = "";

                // Update the donor details
                form1ref.updateDonorRecord(oldDonor, new Donor(firstName, lastName, address, phoneNum, birthdate, new Blood(bloodType)));

                // Update the graph
                form1ref.updateChart(oldDonor.Blood.ToFormattedString(), bloodType);

                // Reset the filter
                form1ref.resetFilter();

                // Close the form as changes are already saved
                this.Close();
            }
        }

        private void goBacktoMain_Click(object sender, EventArgs e)
        {
            // Close the form and don't save any changes
            this.Close();
        }
    }
}
