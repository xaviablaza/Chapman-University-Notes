package assignment5.problem4;

/**
 * Created by Xavi on 4/5/2017.
 */

public class Date {

    private int day;
    private int month;
    private int year;

    public Date(){
        this(1, 1, 1000);
    }

    public Date(int day, int month, int year){
        this.day = day;
        if (this.setMonth(month) == false){
            this.month = 1;
        };
        this.year = year;
    }

    //copy constructor
    public Date(Date original)
    {
        this.day = original.day;
        this.month = original.month;
        this.year = original.year;
    }

    //equals method
    public boolean equals(Date otherDate){
        return (this.day == otherDate.day && this.month == otherDate.month && this.year == otherDate.year);
    }

    //toString method
    public String toString(){
        return (month + "/" + day + "/" + year);
    }


    //Accessor methods
    public int getDay(){
        return day;
    }
    public int getMonth(){
        return month;
    }
    public int getYear(){
        return year;
    }

    //Mutator methods
    public void setDay(int day){
        this.day = day;
    }
    public boolean setMonth(int month){
        if (month <= 12 && month >= 1){
            this.month = month;
            return true;
        }
        else{
            return false;
        }
    }
    public void setYear(int year){
        this.year = year;
    }

    public static int zero(){
        return 0;
    }

    public boolean precedes(Date otherDate)
    {
        if (this.year < otherDate.year)
        {
            return true;
        }
        else if (this.year == otherDate.year && this.month < otherDate.month)
        {
            return true;
        }
        else if (this.year == otherDate.year && this.month == otherDate.month && this.day < otherDate.day)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static boolean datesMatch(Date date1, Date date2)
    {
        if (date1 == null){
            return (date2 == null);
        }
        else if (date2 == null){
            return false;
        }
        else{
            return date1.equals(date2);
        }
    }

}