using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_5
{
    public class Blood
    {
        public Blood(BloodType type, RhesusFactor rhFactor)
        {
            BloodType = type;
            RhesusFactor = rhFactor;
        }

        public Blood(string type)
        {
            switch (type)
            {
                case "O+":
                    BloodType = BloodType.O;
                    RhesusFactor = RhesusFactor.POSITIVE;
                    break;
                case "O-":
                    BloodType = BloodType.O;
                    RhesusFactor = RhesusFactor.NEGATIVE;
                    break;
                case "A+":
                    BloodType = BloodType.A;
                    RhesusFactor = RhesusFactor.POSITIVE;
                    break;
                case "A-":
                    BloodType = BloodType.A;
                    RhesusFactor = RhesusFactor.NEGATIVE;
                    break;
                case "B+":
                    BloodType = BloodType.B;
                    RhesusFactor = RhesusFactor.POSITIVE;
                    break;
                case "B-":
                    BloodType = BloodType.B;
                    RhesusFactor = RhesusFactor.NEGATIVE;
                    break;
                case "AB+":
                    BloodType = BloodType.AB;
                    RhesusFactor = RhesusFactor.POSITIVE;
                    break;
                case "AB-":
                    BloodType = BloodType.AB;
                    RhesusFactor = RhesusFactor.NEGATIVE;
                    break;
            }
        }

        public Blood(string type, string rhFactor)
        {
            switch (type)
            {
                case "A":
                    BloodType = BloodType.A;
                    break;
                case "O":
                    BloodType = BloodType.O;
                    break;
                case "B":
                    BloodType = BloodType.B;
                    break;
                case "AB":
                    BloodType = BloodType.AB;
                    break;
                default:
                    break;
            }
            switch (rhFactor)
            {
                case "POSITIVE":
                    RhesusFactor = RhesusFactor.POSITIVE;
                    break;
                case "NEGATIVE":
                    RhesusFactor = RhesusFactor.NEGATIVE;
                    break;
            }
        }

        public BloodType BloodType { get; set; }

        public RhesusFactor RhesusFactor { get; set; }

        public string ToFormattedString()
        {
            string factor;
            if (RhesusFactor == RhesusFactor.POSITIVE) factor = "+";
            else factor = "-";
            return BloodType.ToString() + factor;
        }

        public override string ToString()
        {
            return BloodType.ToString() + "," + RhesusFactor.ToString();
        }
    }

    public enum BloodType { A, O, B, AB }

    public enum RhesusFactor { POSITIVE, NEGATIVE }
}
