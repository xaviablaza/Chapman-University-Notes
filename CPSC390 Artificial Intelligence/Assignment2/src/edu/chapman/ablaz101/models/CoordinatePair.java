package edu.chapman.ablaz101.models;

public class CoordinatePair {
	private final int i;
	private final int j;
	
	public CoordinatePair(){
		i = -1;
		j = -1;
	}
	
	public CoordinatePair(int i, int j) {
		this.i = i;
		this.j = j;
	}
	
	/**
	 * Gets the i index to be used as [i][j]
	 * @return int i
	 */
	public int getFirstIndex() {
		return i;
	}
	
	/**
	 * Gets the j index to be used as [i][j]
	 * @return int j
	 */
	public int getSecondIndex() {
		return j;
	}
	
	/**
	 * Gets the CoordinatePair that is north of this CoordinatePair
	 * @param int numSteps
	 * @return CoordinatePair northCoordinatePair
	 */
	public CoordinatePair moveNorth(int numSteps) {
		return new CoordinatePair(i-numSteps, j);
	}
	
	/**
	 * Gets the CoordinatePair that is east of this CoordinatePair
	 * @param int numSteps
	 * @return CoordinatePair eastCoordinatePair
	 */
	public CoordinatePair moveEast(int numSteps) {
		return new CoordinatePair(i, j+numSteps);
	}
	
	/**
	 * Gets the CoordinatePair that is north of this CoordinatePair
	 * @param int numSteps
	 * @return CoordinatePair southCoordinatePair
	 */
	public CoordinatePair moveSouth(int numSteps) {
		return new CoordinatePair(i+numSteps, j);
	}
	
	/**
	 * Gets the CoordinatePair that is north of this CoordinatePair
	 * @param int numSteps
	 * @return CoordinatePair westCoordinatePair
	 */
	public CoordinatePair moveWest(int numSteps) {
		return new CoordinatePair(i, j-1);
	}
	
	/**
	 * @param m the height of the 2D array
	 * @param n the width of the 2D array
	 * @return true if coordinate pair is out of bounds
	 */
	public boolean isOutOfBounds(int m, int n) {
		return (!(i>=0 && j>=0 && i<m && j<n));
	}

}
