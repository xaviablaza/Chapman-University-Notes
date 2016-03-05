package edu.chapman.ablaz101.models;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

import edu.chapman.ablaz101.enums.AreaStatus;
import edu.chapman.ablaz101.exceptions.MalformedFileException;

public class FileHandler {
	/**
	 * Prompts for the file name from user input
	 * @return File file
	 */
	public File promptFileName() {
		// Read in the map file
		Scanner inputReader = new Scanner(System.in);
		System.out.print("Enter map file: ");
		String input = inputReader.nextLine();
		inputReader.close();
		return new File(input);
	}
	
	/**
	 * Parses the file into a RobotGrid
	 * @param File file
	 * @return RobotGrid robotGrid
	 */
	public RobotGrid parseFile(File file) {
		RobotGrid rg = null;
		if (file.isFile() && file.exists()) {
			BufferedReader bufferedReader = null;
			try {
				FileReader fileReader = new FileReader(file);
				bufferedReader = new BufferedReader(fileReader);
				String line;
				
				// Read the dimension on the first line
				line = bufferedReader.readLine();
				line = line.trim();
				int dim = Integer.valueOf(line);
				
				// Init grid
				rg = new RobotGrid(dim);
				
				// Parse file into grid
				int row = 0;
				int initial = 0;
				while ((line = bufferedReader.readLine()) != null) {
					line = line.trim();
					if (line.length() < dim) throw new MalformedFileException("Malformed file: too little chars on line " + row + ". Exiting...");
					if (line.length() > dim) throw new MalformedFileException("Malformed file: too many chars on line " + row + ". Exiting...");
					if (row >= dim) throw new MalformedFileException("Malformed file: too many rows. Exiting...");
					for (int i=0; i<line.length(); ++i) {
						char c = line.charAt(i);
						CoordinatePair cp = new CoordinatePair(row, i);
						if (c == '.') {
							NodeState state = new NodeState(cp, AreaStatus.TRAVERSABLE);
							rg.getNodes()[row][i] = new Node(state);
						} else if (c == '+') {
							NodeState state = new NodeState(cp, AreaStatus.OBSTACLE);
							rg.getNodes()[row][i] = new Node(state);
						} else if (c == 'i') {
							NodeState state = new NodeState(cp, AreaStatus.INITIAL);
							Node initialNode = new Node(state, null, 0);
							rg.setInitialNode(initialNode);
							rg.getNodes()[row][i] = initialNode;
							initial++;
						} else if (c == 'g') {
							rg.setGoalNodeCp(cp);
							NodeState state = new NodeState(cp, AreaStatus.GOAL);
							rg.getNodes()[row][i] = new Node(state);
						} else throw new MalformedFileException("" + c + " on line " + row+1 + ", col " + i+1 + " was not recognized. Exiting...");
					}
					row++;
				}
				if (row != dim) throw new MalformedFileException("Malformed file: too little rows. Exiting...");
				if (initial != 1) throw new MalformedFileException("Malformed file: " + initial + " initial states present. "
						+ "File must have 1 initial state and at least 1 goal state.");
				bufferedReader.close();
			} catch (NumberFormatException nfe) {
				System.out.println("Malformed integer at line 0. Exiting...");
				return null;
			} catch (IOException e) {
				System.out.println("IOException occurred. Exiting...");
				return null;
			} catch (MalformedFileException mfe) {
				return null;
			}
		} else {
			System.out.println("File does not exist. Exiting...");
			return null;
		}
		return rg;
	}

}
