package edu.chapman.ablaz101.models;

import edu.chapman.ablaz101.enums.AreaStatus;

public class NodeState {
	private CoordinatePair coordinatePair;
	private AreaStatus areaStatus;
	
	public NodeState(){}
	public NodeState(CoordinatePair coordinatePair, AreaStatus areaStatus) {
		this.coordinatePair = coordinatePair;
		this.areaStatus = areaStatus;
	}
	
	/**
	 * Gets the CoordinatePair of the Node
	 * @return CoordinatePair coordinatePair
	 */
	public CoordinatePair getCoordinatePair() {
		return coordinatePair;
	}
	
	/**
	 * Sets the CoordinatePair of the Node
	 * @param CoordinatePair coordinatePair
	 */
	public void setCoordinatePair(CoordinatePair coordinatePair) {
		this.coordinatePair = coordinatePair;
	}
	
	/**
	 * Gets the AreaStatus of the Node
	 * @return AreaStatus areaStatus
	 */
	public AreaStatus getAreaStatus() {
		return areaStatus;
	}
	
	/**
	 * Sets the AreaStatus of the Node
	 * @param AreaStatus areaStatus
	 */
	public void setAreaStatus(AreaStatus areaStatus) {
		this.areaStatus = areaStatus;
	}
	
}
