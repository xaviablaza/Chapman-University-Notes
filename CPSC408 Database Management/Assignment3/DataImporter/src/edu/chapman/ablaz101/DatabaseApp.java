package edu.chapman.ablaz101;

import org.apache.commons.csv.CSVFormat;
import org.apache.commons.csv.CSVRecord;

import java.io.FileReader;
import java.io.Reader;
import java.sql.*;

public class DatabaseApp {
    private static final String DATABASE_NAME = "my_db";
    private static final String DATABASE_USER = "root";
    private static final String DATABASE_PASSWORD = "root";

    private Connection connection;
    private final String fileName;

    DatabaseApp(String fileName) {
        this.fileName = fileName;
        connectToDatabase();
        createTables();
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

    private void createTables() {
        Statement stmt = null;
        try {
            stmt = connection.createStatement();
            stmt.execute("CREATE TABLE IF NOT EXISTS UserContact (" +
                    "CID int primary key auto_increment," +
                    "Name varchar(255)," +
                    "Gender char(1)," +
                    "Birthday DATETIME," +
                    "Hometown varchar(255)," +
                    "Title varchar(255)" +
                    ");");
            stmt.execute("CREATE TABLE IF NOT EXISTS UserEmail (" +
                    "EmailID int primary key auto_increment," +
                    "CID int," +
                    "Email varchar(255)," +
                    "FOREIGN KEY(CID) REFERENCES UserContact(CID)" +
                    ");");
            stmt.execute("CREATE TABLE IF NOT EXISTS UserBlockstackID (" +
                    "BlockstackID int primary key auto_increment," +
                    "CID int," +
                    "UUID VARCHAR(50)," +
                    "FOREIGN KEY(CID) REFERENCES UserContact(CID)" +
                    ");");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void start() throws SQLException {
        System.out.println("Welcome to Xavi's database importer!");
        parseData();
        connection.close();
        System.out.println("Finished import.");
    }

    public void parseData() {
        try {
            Reader in = new FileReader("./"+fileName);
            Iterable<CSVRecord> records = CSVFormat.EXCEL.parse(in);
            for (CSVRecord record : records) {
                String name = record.get(0);
                String gender = record.get(1);
                String birthday = record.get(2);
                String hometown = record.get(3);
                String title = record.get(4);
                String email = record.get(5);
                String blockstackID = record.get(6);

                PreparedStatement st = connection.prepareStatement("INSERT INTO UserContact(Name,Gender,Birthday,Hometown,Title)"
                        + "VALUES(?,?,?,?,?)", Statement.RETURN_GENERATED_KEYS);
                st.setString(1,name);
                st.setString(2,gender);
                st.setString(3,birthday);
                st.setString(4,hometown);
                st.setString(5,title);
                st.executeUpdate();

                ResultSet rsKey = st.getGeneratedKeys();
                int c_id = 0;
                if (rsKey.next()) {
                    c_id = rsKey.getInt(1);
                }

                PreparedStatement st2 = connection.prepareStatement("INSERT INTO UserEmail(CID,Email)"
                        + "VALUES(?,?)");
                st2.setInt(1,c_id);
                st2.setString(2,email);
                st2.executeUpdate();

                PreparedStatement st3 = connection.prepareStatement("INSERT INTO UserBlockstackID(CID,UUID)"
                        + "VALUES(?,?)");
                st3.setInt(1,c_id);
                st3.setString(2,blockstackID);
                st3.executeUpdate();

            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
