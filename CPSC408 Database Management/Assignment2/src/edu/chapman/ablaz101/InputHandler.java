package edu.chapman.ablaz101;

import java.util.Scanner;

public class InputHandler {
    Scanner inputReader;
    public InputHandler() {
        inputReader = new Scanner(System.in);
    }

    public int promptOption() {
        System.out.println("Please select an option:");
        System.out.println("[1]: Display all students");
        System.out.println("[2]: Create a new student");
        System.out.println("[3]: Update a student's major");
        System.out.println("[4]: Update a student's advisor");
        System.out.println("[5]: Delete a student");
        System.out.println("[6]: Display students by major");
        System.out.println("[7]: Display students by GPA");
        System.out.println("[8]: Display students by advisor");
        System.out.println("[9]: Exit app");

        String input = inputReader.nextLine();
        int choice = 0;
        try {
            choice = Integer.parseInt(input);
            if (!(choice >=1 && choice <= 9)) throw new NumberFormatException();
        } catch (Exception e) {
            System.out.println("Could not parse integer option. Try again.");
            return promptOption();
        }
        return choice;
    }

    public Student promptStudentInfo() {
        boolean notValidated = true;
        int studID = 0;

        while (notValidated) {
            System.out.println("Enter student ID:");
            String studentId = inputReader.nextLine();
            try {
                studID = Integer.parseUnsignedInt(studentId);
                notValidated = false;
            } catch (Exception e) {
                System.out.println("Could not read integer. Try again.");
            }
        }

        notValidated = true;
        String firstName = "";
        while (notValidated) {
            System.out.println("Enter first name:");
            firstName = inputReader.nextLine();
            firstName = firstName.trim();
            if (firstName.isEmpty()) {
                System.out.println("String is invalid. Try again.");
            } else {
                notValidated = false;
            }
        }

        notValidated = true;
        String lastName = "";
        while (notValidated) {
            System.out.println("Enter last name:");
            lastName = inputReader.nextLine();
            lastName = lastName.trim();
            if (lastName.isEmpty()) {
                System.out.println("String is invalid. Try again.");
            } else {
                notValidated = false;
            }
        }

        notValidated = true;
        double gpa = 0;
        while (notValidated) {
            System.out.println("Enter GPA:");
            String gpastr = inputReader.nextLine();
            try {
                gpa = Double.parseDouble(gpastr);
            } catch (Exception e) {
                System.out.println("GPA not parseable. Try again.");
                continue;
            }
            notValidated = false;
        }

        notValidated = true;
        String major = "";
        while (notValidated) {
            System.out.println("Enter major:");
            major = inputReader.nextLine();
            major = major.trim();
            if (major.isEmpty()) {
                System.out.println("String is invalid. Try again.");
            } else {
                notValidated = false;
            }
        }

        notValidated = true;
        String advisor = "";
        while (notValidated) {
            System.out.println("Enter faculty advisor:");
            advisor = inputReader.nextLine();
            advisor = advisor.trim();
            if (advisor.isEmpty()) {
                System.out.println("String is invalid. Try again.");
            } else {
                notValidated = false;
            }
        }
        return new Student(studID, firstName, lastName, gpa, major, advisor);
    }


}
