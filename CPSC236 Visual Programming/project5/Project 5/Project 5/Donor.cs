using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_5
{
    public class Donor
    {
        public Donor(string firstName, string lastName, string address, string phone, DateTime birthDate, Blood blood)
        {
            FirstName = firstName;
            LastName = lastName;
            Address = address;
            Phone = phone;
            Birthdate = birthDate;
            Blood = blood;
        }

        public string FirstName { get; set; }

        public string LastName { get; set; }

        public string FullName
        {
            get
            {
                return FirstName + " " + LastName;
            }
        }

        public string Address { get; set; }

        public string Phone { get; set; }

        public DateTime Birthdate { get; set; }

        public Blood Blood { get; set; }

        public override string ToString()
        {
            return FirstName + "," + LastName + "," + Address + "," + Phone + "," + Birthdate.ToShortDateString() + "," + Blood.ToFormattedString();
        }
    }
}
