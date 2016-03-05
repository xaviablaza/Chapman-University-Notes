package edu.chapman.ablaz101;

import java.io.File;
import edu.chapman.ablaz101.models.FileHandler;
import edu.chapman.ablaz101.models.RobotGrid;

public class Main {
	final static boolean DEBUG = false;
	public static void main(String[] args) {
		FileHandler fileHandler = new FileHandler();
		File file = fileHandler.promptFileName();
		RobotGrid robotGrid = fileHandler.parseFile(file);
		if (robotGrid != null) {
			robotGrid.search(DEBUG);
		}
	}
}
