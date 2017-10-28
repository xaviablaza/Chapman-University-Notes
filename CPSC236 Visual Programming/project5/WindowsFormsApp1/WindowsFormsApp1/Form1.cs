using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        BindingList<Donor> donorList;
        const string FILENAME = "donors.txt";

        public Form1()
        {
            donorList = new BindingList<Donor>();
            loadFile(donorList, FILENAME);
            InitializeComponent();
            // TODO: Bind the donor list to the listbox
            
        }

        private void saveFile(BindingList<Donor> donors, string filename)
        {
            using (StreamWriter sw = new StreamWriter(filename, false))
            {
                foreach (Donor donor in donors)
                {
                    //"Firstname,LastName,address,phone,bdaydate,bloodtype,rhfactor"
                    sw.WriteLine(donor.ToString());
                }
            }
        }

        private bool loadFile(BindingList<Donor> donors, string fileName)
        {
            // If file exists, then attempt to load it into dictionary
            if (File.Exists(fileName))
            {
                try
                {   // Open the text file using a stream reader.
                    using (StreamReader sr = new StreamReader(fileName))
                    {
                        // Read the stream to a string
                        String line = sr.ReadToEnd();
                        String[] v = line.Split(',');
                        //"Firstname,LastName,address,phone,bdaydate,bloodtype,rhfactor"
                        donors.Add(new Donor(v[0], v[1], v[2], v[3], DateTime.Parse(v[4]), new Blood(v[5], v[6])));
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

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            saveFile(donorList, FILENAME);
        }
    }
}
