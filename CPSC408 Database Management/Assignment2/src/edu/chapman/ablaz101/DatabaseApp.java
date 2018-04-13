package edu.chapman.ablaz101;

import java.sql.*;
import java.util.Scanner;

public class DatabaseApp {
    public static final String DATABASE_NAME = "replace_me";
    public static final String DATABASE_USER = "replace_me";
    public static final String DATABASE_PASSWORD = "replace_me";

    private final InputHandler inputHandler;
    private Connection connection;
    DatabaseApp() {
        this.inputHandler = new InputHandler();
        connectToDatabase();
        createStudentTable();
    }

    public void start() throws SQLException {
        System.out.println("Welcome to Xavi's database app!");
        boolean returnToMenu = true;
        while (returnToMenu) {
            int option = inputHandler.promptOption();

            switch (option) {
                case 1:
                    displayStudents();
                    break;
                case 2:
                    createStudent();
                    break;
                case 3:
                    updateStudentMajor();
                    break;
                case 4:
                    updateStudentAdvisor();
                    break;
                case 5:
                    deleteStudent();
                    break;
                case 6:
                    displayStudentMajor();
                    break;
                case 7:
                    displayStudentGPA();
                    break;
                case 8:
                    displayStudentAdvisor();
                    break;
                case 9:
                    showExitMessage();
                    returnToMenu = false;
                    break;
                default:
                    showErrorMessage();
                    break;
            }
        }
        connection.close();
    }

    private void displayStudentMajor() throws SQLException {
        PreparedStatement ps1 = connection.prepareStatement("SELECT * FROM Student WHERE Major=?;");
        ps1.clearParameters();
        Scanner inputReader = new Scanner(System.in);
        boolean notValidated = true;
        String major = "";
        while (notValidated) {
            System.out.println("Enter major:");
            major = inputReader.nextLine();
            if (major.trim().isEmpty() || major.trim().length()>10) {
                System.out.println("String is invalid or longer than expected. Try again.");
            } else {
                notValidated = false;
            }
        }
        ps1.setString(1, major);

        ResultSet rs1 = ps1.executeQuery();
        ResultSetMetaData rsmd1 = rs1.getMetaData();
        int numColumns = rsmd1.getColumnCount();
        while (rs1.next()) {
            String row = "";
            for (int i=1; i<=numColumns; ++i) {
                row += rs1.getString(i) + ", ";
            }
            System.out.println(row);
        }
    }

    private void displayStudentGPA() throws SQLException {
        PreparedStatement ps1 = connection.prepareStatement("SELECT * FROM Student WHERE GPA=?;");
        ps1.clearParameters();
        Scanner inputReader = new Scanner(System.in);
        boolean notValidated = true;
        double gpa = 0.0;
        while (notValidated) {
            System.out.println("Enter gpa:");
            try {
                gpa = Double.parseDouble(inputReader.nextLine());
            } catch (Exception e) {
                System.out.println("GPA not parseable. Try again.");
                continue;
            }
            notValidated = false;
        }
        ps1.setDouble(1, gpa);

        ResultSet rs1 = ps1.executeQuery();
        ResultSetMetaData rsmd1 = rs1.getMetaData();
        int numColumns = rsmd1.getColumnCount();
        while (rs1.next()) {
            String row = "";
            for (int i=1; i<=numColumns; ++i) {
                row += rs1.getString(i) + ", ";
            }
            System.out.println(row);
        }
    }

    private void displayStudentAdvisor() throws SQLException {
        PreparedStatement ps1 = connection.prepareStatement("SELECT * FROM Student WHERE FacultyAdvisor=?;");
        ps1.clearParameters();
        Scanner inputReader = new Scanner(System.in);
        boolean notValidated = true;
        String advisor = "";
        while (notValidated) {
            System.out.println("Enter faculty advisor:");
            advisor = inputReader.nextLine();
            if (advisor.trim().isEmpty() || advisor.trim().length()>25) {
                System.out.println("String is invalid or longer than expected. Try again.");
            } else {
                notValidated = false;
            }
        }
        ps1.setString(1, advisor);

        ResultSet rs1 = ps1.executeQuery();
        ResultSetMetaData rsmd1 = rs1.getMetaData();
        int numColumns = rsmd1.getColumnCount();
        while (rs1.next()) {
            String row = "";
            for (int i=1; i<=numColumns; ++i) {
                row += rs1.getString(i) + ", ";
            }
            System.out.println(row);
        }
    }

    private void deleteStudent() throws SQLException {
        PreparedStatement ps4 = connection.prepareStatement("DELETE FROM Student WHERE StudentId=?;");
        ps4.clearParameters();
        Scanner inputReader = new Scanner(System.in);
        int studID = 0;
        boolean notValidated = true;
        while (notValidated) {
            System.out.println("Enter student ID:");
            String studentId = inputReader.nextLine();
            studentId = studentId.trim();
            try {
                studID = Integer.parseUnsignedInt(studentId);
                notValidated = false;
            } catch (Exception e) {
                System.out.println("Could not read integer. Try again.");
            }
        }
        ps4.setInt(1, studID);
        ps4.executeUpdate();
    }

    private void updateStudentAdvisor() throws SQLException {
        PreparedStatement ps3 = connection.prepareStatement("UPDATE Student SET FacultyAdvisor=? WHERE StudentId=?;");
        ps3.clearParameters();

        Scanner inputReader = new Scanner(System.in);
        int studID = 0;
        boolean notValidated = true;
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
        String advisor = "";
        while (notValidated) {
            System.out.println("Enter faculty advisor:");
            advisor = inputReader.nextLine();
            if (advisor.trim().isEmpty() || advisor.trim().length()>25) {
                System.out.println("String is invalid or longer than expected. Try again.");
            } else {
                notValidated = false;
            }
        }

        ps3.setString(1, advisor);
        ps3.setInt(2, studID);
        ps3.executeUpdate();
    }

    private void updateStudentMajor() throws SQLException {
        PreparedStatement ps3 = connection.prepareStatement("UPDATE Student SET Major=? WHERE StudentId=?;");
        ps3.clearParameters();

        Scanner inputReader = new Scanner(System.in);
        int studID = 0;
        boolean notValidated = true;
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
        String major = "";
        while (notValidated) {
            System.out.println("Enter major name:");
            major = inputReader.nextLine();
            if (major.trim().isEmpty() || major.trim().length()>10) {
                System.out.println("String is invalid or longer than expected. Try again.");
            } else {
                notValidated = false;
            }
        }

        ps3.setString(1, major);
        ps3.setString(2, String.valueOf(studID));
        ps3.executeUpdate();
    }

    private void createStudent() throws SQLException {
        PreparedStatement ps2 = connection.prepareStatement("INSERT INTO Student(StudentId,FirstName,LastName,GPA,Major,FacultyAdvisor) VALUES (?,?,?,?,?,?);");
        ps2.clearParameters();
        Student s = inputHandler.promptStudentInfo();
        ps2.setInt(1,s.getStudentId());
        ps2.setString(2 ,s.getFirstName());
        ps2.setString(3, s.getLastName());
        ps2.setDouble(4,s.getGpa());
        ps2.setString(5,s.getMajor());
        ps2.setString(6,s.getFacultyAdvisor());
        ps2.executeUpdate();
    }

    private void displayStudents() throws SQLException {
        Statement ps1 = connection.createStatement();
        ResultSet rs1 = ps1.executeQuery("SELECT * FROM Student;");
        ResultSetMetaData rsmd1 = rs1.getMetaData();
        int numColumns = rsmd1.getColumnCount();
        while (rs1.next()) {
            String row = "";
            for (int i=1; i<=numColumns; ++i) {
                row += rs1.getString(i) + ", ";
            }
            System.out.println(row);
        }
    }

    private void connectToDatabase() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            this.connection = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/"+DATABASE_NAME, DATABASE_USER, DATABASE_PASSWORD);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    private void createStudentTable() {
        Statement stmt = null;
        try {
            stmt = connection.createStatement();
            stmt.execute("CREATE TABLE IF NOT EXISTS Student (" +
                    "StudentId int primary key," +
                    "FirstName varchar(25)," +
                    "LastName varchar(25)," +
                    "GPA numeric(3,2)," +
                    "Major varchar(10)," +
                    "FacultyAdvisor varchar(25)" +
                    ");");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void showExitMessage() {
        System.out.println("Goodbye!");
    }

    private void showErrorMessage() {
        System.out.println("Option not recognized. Returning to menu.");
    }
}
