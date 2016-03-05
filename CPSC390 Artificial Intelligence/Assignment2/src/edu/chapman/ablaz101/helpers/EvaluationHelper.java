package edu.chapman.ablaz101.helpers;

import edu.chapman.ablaz101.models.CoordinatePair;

public class EvaluationHelper {
	
	/**
	 * Gets the Euclidean Distance from start to finish, avoiding obstacles
	 * @param CoordinatePair start
	 * @param CoordinatePair finish
	 * @return double distance
	 */
	public static double euclideanDistance(CoordinatePair start, CoordinatePair finish) {
		double d = Math.sqrt(Math.pow(start.getFirstIndex()-finish.getFirstIndex(), 2)
				+ Math.pow(start.getSecondIndex()-finish.getSecondIndex(), 2));
		return d;
	}
	
	/**
	 * Gets the Manhattan Distance from start to finish, avoiding obstacles
	 * @param CoordinatePair start
	 * @param CoordinatePair finish
	 * @return int distance
	 */
	public static int manhattanDistance(CoordinatePair start, CoordinatePair finish) {
		int d = Math.abs(start.getFirstIndex()-finish.getFirstIndex())
				+ Math.abs(start.getSecondIndex()-finish.getSecondIndex());
		return d;
	}
}
