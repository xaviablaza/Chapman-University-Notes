package edu.chapman.ablaz101;

import java.io.FileReader;
import java.io.Reader;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class Main {

    public static void main(String[] args) {
        // write your code here
        try {
            Reader in = new FileReader("/Users/");
            Iterable<CSVRecord> records = CSVFormat.EXCEL.parse(in);
            for (CSVRecord record : records) {
                String firstName = record.get(0);
                String lastName = record.get(1);
                String age = record.get(2);
                String gender = record.get(3);

                String address = record.get(4);
                String address2 = record.get(5);
                String city = record.get(6);
                String state = record.get(7);
                String zip = record.get(8);


                PreparedStatement st = con.createStatement("INSERT INTO Contacts(FirstName,LastName,Age,Gender)"
                        + "VALUES(?,?,?,?)");
                st.setString(1,firstName);
                st.setString(2,lastName);
                st.setString(3,age);
                st.setString(4,gender);
                st.executeUpdate();

                ResultSet rsKey = st.getGeneratedKeys();
                int c_id = 0;
                if (rsKey.next()) {
                    c_id = rsKey.getInt(1);
                }

                PreparedStatement st2 = con.createStatement("INSERT INTO Contacts(ContactId,Address1,Address2,City,State,Zip)"
                        + "VALUES(?,?,?,?,?,?)", Statement.RETURN_GENERATED_KEYS);
                st2.setInt(1,c_id);
                st2.setString(2,address);
                st2.setString(3,address2);
                st2.setString(4,city);
                st2.setString(5,state);
                st2.setString(6,zip);
                st2.executeUpdate();

            }
        } catch (Exception e) {
            ex.printStackTrace();
        }
    }
}
