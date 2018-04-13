package edu.chapman.ablaz101;

public class Student {
    private int studentId;
    private String firstName;
    private String lastName;
    private double gpa;
    private String major;
    private String facultyAdvisor;

    public Student(int studentId, String firstName, String lastName, double gpa, String major, String facultyAdvisor) {
        this.studentId = studentId;
        this.firstName = firstName;
        this.lastName = lastName;
        this.gpa = gpa;
        this.major = major;
        this.facultyAdvisor = facultyAdvisor;
    }

    public int getStudentId() {
        return studentId;
    }

    public void setStudentId(int studentId) {
        this.studentId = studentId;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public double getGpa() {
        return gpa;
    }

    public void setGpa(double gpa) {
        this.gpa = gpa;
    }

    public String getMajor() {
        return major;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    public String getFacultyAdvisor() {
        return facultyAdvisor;
    }

    public void setFacultyAdvisor(String facultyAdvisor) {
        this.facultyAdvisor = facultyAdvisor;
    }
}
