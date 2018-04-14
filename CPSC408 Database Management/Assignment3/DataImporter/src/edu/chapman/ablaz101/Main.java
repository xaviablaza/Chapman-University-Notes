package edu.chapman.ablaz101;

import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {
        if (args.length == 1) {
            DatabaseApp dbApp = new DatabaseApp(args[0]);
            try {
                dbApp.start();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Please specify filename to import into database.");
        }
    }
}
