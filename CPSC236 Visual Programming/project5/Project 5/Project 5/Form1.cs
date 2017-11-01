using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project_5
{
    public partial class Form1 : Form
    {
        BindingList<Donor> donorList;
        const string FILENAME = "donors.txt";
        const string SERIES_NAME = "BBR";
        string[] BLOOD_TYPES = new string[8];
        int[] records = new int[8];

        public Form1()
        {
            InitializeComponent();

            // Declare new Binding List of type Donor
            donorList = new BindingList<Donor>();

            // Load the donor file if it exists
            loadFile(donorList, FILENAME);

            // Chart setup code
            setupChart();

            // Set the datasource of the donor list
            donorListBox.DataSource = donorList;

            // Set the display member to have the first name and the last name of the donor
            donorListBox.DisplayMember = "FullName";
        }

        private void setupChart()
        {
            BLOOD_TYPES[0] = "O+";
            BLOOD_TYPES[1] = "O-";
            BLOOD_TYPES[2] = "A+";
            BLOOD_TYPES[3] = "A-";
            BLOOD_TYPES[4] = "B+";
            BLOOD_TYPES[5] = "B-";
            BLOOD_TYPES[6] = "AB+";
            BLOOD_TYPES[7] = "AB-";
            for (int i = 0; i < 8; ++i)
            {
                records[i] = 0;
            }
            foreach (Donor donor in donorList)
            {
                updateChartPlusOne(donor.Blood.ToFormattedString());
            }
            chart1.Series[SERIES_NAME].Points.DataBindXY(BLOOD_TYPES, records);
        }

        private void updateChartPlusOne(string bloodType)
        {
            switch (bloodType)
            {
                case "O+":
                    records[0] += 1;
                    break;
                case "O-":
                    records[1] += 1;
                    break;
                case "A+":
                    records[2] += 1;
                    break;
                case "A-":
                    records[3] += 1;
                    break;
                case "B+":
                    records[4] += 1;
                    break;
                case "B-":
                    records[5] += 1;
                    break;
                case "AB+":
                    records[6] += 1;
                    break;
                case "AB-":
                    records[7] += 1;
                    break;
            }
            chart1.Series[SERIES_NAME].Points.DataBindXY(BLOOD_TYPES, records);
        }

        private void updateChartMinusOne(string bloodType)
        {
            switch (bloodType)
            {
                case "O+":
                    records[0] -= 1;
                    break;
                case "O-":
                    records[1] -= 1;
                    break;
                case "A+":
                    records[2] -= 1;
                    break;
                case "A-":
                    records[3] -= 1;
                    break;
                case "B+":
                    records[4] -= 1;
                    break;
                case "B-":
                    records[5] -= 1;
                    break;
                case "AB+":
                    records[6] -= 1;
                    break;
                case "AB-":
                    records[7] -= 1;
                    break;
            }
            chart1.Series[SERIES_NAME].Points.DataBindXY(BLOOD_TYPES, records);
        }

        public void updateChart(string oldType, string newType)
        {
            updateChartMinusOne(oldType);
            updateChartPlusOne(newType);
        }

        /*
         * Writes the donor list to a file
         */
        private void saveFile(BindingList<Donor> donors, string filename)
        {
            using (StreamWriter sw = new StreamWriter(filename, false))
            {
                foreach (Donor donor in donors)
                {
                    sw.WriteLine(donor.ToString());
                }
            }
        }

        /*
         * Loads the donor list the file
         */
        private bool loadFile(BindingList<Donor> donors, string fileName)
        {
            // If file exists, then attempt to load it
            if (File.Exists(fileName))
            {
                try
                {   // Open the text file using a stream reader.
                    using (StreamReader sr = new StreamReader(fileName))
                    {
                        // Read the stream to a string
                        String line = sr.ReadToEnd();

                        // Add it to the donor list
                        String[] v = line.Split(',');
                        donors.Add(new Donor(v[0], v[1], v[2], v[3], DateTime.Parse(v[4]), new Blood(v[5])));
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("The file could not be read:");
                    Console.WriteLine(e.Message);
                    return false;
                }
                Console.WriteLine("Successfully loaded " + fileName);
                return true;
            }
            else
            {
                return false;
            }
        }

        private void addButton_Click(object sender, EventArgs e)
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

                // Add the donor to the list
                donorList.Add(new Donor(firstName, lastName, address, phoneNum, birthdate, new Blood(bloodType)));

                // Update the graph
                updateChartPlusOne(bloodType);
            }
        }

        private void viewData_Click(object sender, EventArgs e)
        {
            // Open up the View Details Form
            if (donorListBox.SelectedIndex > -1)
            {
                Donor record = (Donor)donorListBox.Items[donorListBox.SelectedIndex];
                View_Details viewForm = new View_Details(this, record);
                viewForm.ShowDialog();
            }
        }

        private void changeDataOpen_Click(object sender, EventArgs e)
        {
            // Open up the Change Form
            if (donorListBox.SelectedIndex > -1)
            {
                Donor record = (Donor)donorListBox.Items[donorListBox.SelectedIndex];
                Change_Details editForm = new Change_Details(this, record);
                editForm.ShowDialog();
            }
        }

        private void delete_Click(object sender, EventArgs e)
        {
            // Delete the Donor Record
            // The selected item in your ListBox is referenced by the SelectedIndex. It's a 0-based index.
            // If no item is selected, the index is -1, which doesn't exist, so make sure to not try to delete it
            if (donorListBox.SelectedIndex > -1)
            {
                // Update the graph
                Donor donor = (Donor)donorList[donorListBox.SelectedIndex];
                updateChartMinusOne(donor.Blood.ToFormattedString());

                // Remove from the the ListBox Items at the particular index that was selected
                donorList.RemoveAt(donorListBox.SelectedIndex);
            }
        }

        private void Form1_FormClosing_1(object sender, FormClosingEventArgs e)
        {
            saveFile(donorList, FILENAME);
        }

        public void updateDonorRecord(Donor donor)
        {
            donorList[donorListBox.SelectedIndex] = donor;
        }
    }
}
