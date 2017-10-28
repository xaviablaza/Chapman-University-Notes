namespace WindowsFormsApp1
{
    public class Blood
    {
        public Blood(BloodType type, RhesusFactor rhFactor)
        {
            BloodType = type;
            RhesusFactor = rhFactor;
        }

        public Blood(string type, string rhFactor)
        {
            switch(type)
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
            switch(rhFactor)
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

        public override string ToString()
        {
            return BloodType.ToString() + "," + RhesusFactor.ToString();
        }
    }

    public enum BloodType { A, O, B, AB }

    public enum RhesusFactor { POSITIVE, NEGATIVE }
}