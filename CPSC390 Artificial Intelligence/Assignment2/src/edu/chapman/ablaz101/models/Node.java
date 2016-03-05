package edu.chapman.ablaz101.models;

public class Node {
	private NodeState state;
	private Node parent;
	private double hCost;
	private double totalStepCost;
	private int depth;
	
	public Node(){}
	public Node(NodeState state) {
		this.state = state;
		this.parent = null;
		this.hCost = -1;
		this.totalStepCost = -1;
		this.depth = -1;
	}
	public Node(NodeState state, Node parent, int depth) {
		this.state = state;
		this.depth = depth;
	}
	
	/**
	 * Gets the Node's state
	 * @return NodeState state
	 */
	public NodeState getState() {
		return state;
	}
	
	/**
	 * Sets the Node's state
	 * @param NodeState state
	 */
	public void setState(NodeState state) {
		this.state = state;
	}
	
	/**
	 * Gets the parent Node that generated this Node
	 * @return Node parent
	 */
	public Node getParent() {
		return parent;
	}
	
	/**
	 * Sets the parent Node that generated this Node
	 * @param Node parent
	 */
	public void setParent(Node parent) {
		this.parent = parent;
	}
	
	/**
	 * Gets the heuristic cost of this node specified by an EvaluationType in RobotGrid
	 * @return double hCost
	 */
	public double getHCost() {
		return hCost;
	}
	
	/**
	 * Sets the heuristic cost of this node specified by an EvaluationType in RobotGrid
	 * @param double hCost
	 */
	public void setHCost(double hCost) {
		this.hCost = hCost;
	}
	
	/**
	 * Gets the total step cost specified by RobotGrid
	 * @return double stepCost
	 */
	public double getTotalStepCost() {
		return totalStepCost;
	}
	
	/**
	 * Sets the total step cost specified by RobotGrid
	 * @param double stepCost
	 */
	public void setTotalStepCost(double stepCost) {
		this.totalStepCost = stepCost;
	}
	
	/**
	 * Gets the depth of the node in the search tree
	 * @return int depth
	 */
	public int getDepth() {
		return depth;
	}
	
	/**
	 * Sets the depth of the node in the search tree
	 * @param depth
	 */
	public void setDepth(int depth) {
		this.depth = depth;
	}
	
	/**
	 * Gets the coordinates adjacent to this node in each cardinal direction.
	 * @return CoordinatePair[] that follows north, east, south, and west in that order
	 */
	public CoordinatePair[] expand() {
		CoordinatePair[] arr = new CoordinatePair[4];
		CoordinatePair cp = state.getCoordinatePair();
		arr[0] = cp.moveNorth(1);
		arr[1] = cp.moveEast(1);
		arr[2] = cp.moveSouth(1);
		arr[3] = cp.moveWest(1);
		return arr;
	}
	
}