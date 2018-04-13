package edu.chapman.ablaz101;

import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {
        DatabaseApp dbApp = new DatabaseApp();
        try {
            dbApp.start();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
