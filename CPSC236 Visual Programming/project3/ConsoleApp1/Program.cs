// Xavier Luis Ablaza #2258883 ablaz101@mail.chapman.edu CPSC236-03 F2017 PROJECT03
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to Xavi's record keeping app!");
            Console.WriteLine("Attempting to read records.txt");

            // Make new empty dictionary and load from file if needed
            IDictionary<int, string> dict = new Dictionary<int, string>();
            loadFile(dict, "records.txt");
            
            bool exit = false;
            while (!exit)
            {
                printMenu();
                switch (Console.ReadLine())
                {
                    // Add Student
                    case "1":
                        Console.WriteLine("Enter student ID (only number):");
                        string idstr = Console.ReadLine();
                        int studId;
                        while (!int.TryParse(idstr, out studId))
                        {
                            Console.WriteLine("Student ID could not be parsed because it has letters. Try again:");
                            idstr = Console.ReadLine();
                        }
                        if (dict.ContainsKey(studId))
                        {
                            Console.WriteLine("Student ID is already in records.txt, returning to menu");
                            break;
                        }
                        Console.WriteLine("Enter student name:");
                        string studName = Console.ReadLine();
                        while (!studName.All(char.IsLetter))
                        {
                            Console.WriteLine("Student name has numbers. Try again:");
                            studName = Console.ReadLine();
                        }
                        dict.Add(studId, studName);
                        break;




                    // Remove Student
                    case "2":
                        Console.WriteLine("Enter student ID to remove:");
                        while (!int.TryParse(Console.ReadLine(), out studId))
                        {
                            Console.WriteLine("Student ID could not be parsed. Try again:");
                        }
                        if (dict.ContainsKey(studId))
                        {
                            dict.Remove(studId);
                        }
                        else
                        {
                            Console.WriteLine("Student ID does not exist. Returning to menu.");
                        }
                        break;


                    // View All Students
                    case "3":
                        foreach (KeyValuePair<int, string> entry in dict)
                        {
                            Console.WriteLine(entry.Key + ", " + entry.Value);
                        }
                        break;


                    // Quit and save the file
                    case "4":
                        using (StreamWriter sw = new StreamWriter("records.txt"))
                        {
                            foreach (KeyValuePair<int, string> entry in dict)
                            {
                                sw.WriteLine(entry.Key + "," + entry.Value);
                            }
                            sw.Close();
                        }
                        exit = true;
                        break;
                    default:
                        Console.WriteLine("Input not recognized, returning to menu:");
                        break;
                }
            }
        }

        /*
         * Loads file from the specified fileName or loads a new dictionary if no file exists
         */
        static void loadFile(IDictionary<int, string> dict, string fileName)
        {
            // If file exists, then attempt to load it into dictionary
            if (File.Exists(fileName))
            {
                try
                {   // Open the text file using a stream reader.
                    using (StreamReader sr = new StreamReader(fileName))
                    {
                        // Read the stream to a string, and write the string to the console.
                        String line = sr.ReadToEnd();
                        String[] keyval = line.Split(',');
                        dict.Add(int.Parse(keyval[0]), keyval[1]);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("The file could not be read:");
                    Console.WriteLine(e.Message);
                }
                Console.WriteLine("Successfully loaded " + fileName);
            }
            // If not, print that you are creating a new empty dictionary
            else
            {
                Console.WriteLine(fileName + " does not exist. Creating new dictionary.");
            }
        }

        /* 
         * Prints a menu where user can choose options to pick
         */
        static void printMenu()
        {
            Console.WriteLine("What do you want to do?");
            Console.WriteLine("1. Add new student record");
            Console.WriteLine("2. Delete record");
            Console.WriteLine("3. View all records");
            Console.WriteLine("4. Quit and save records to file");
        }
    }
}
