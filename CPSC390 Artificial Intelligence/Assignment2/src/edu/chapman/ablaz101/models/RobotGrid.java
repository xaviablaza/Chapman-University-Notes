package edu.chapman.ablaz101.models;

import edu.chapman.ablaz101.enums.AreaStatus;
import edu.chapman.ablaz101.enums.EvaluationType;
import edu.chapman.ablaz101.helpers.EvaluationHelper;

public class RobotGrid {
	private Node[][] nodes;
	private Node initialNode;
	private CoordinatePair goalNodeCp;
	
	public RobotGrid(int dim) {
		nodes = new Node[dim][dim];
	}
	
	Node[][] getNodes() {
		return nodes;
	}

	Node getInitialNode() {
		return initialNode;
	}

	void setInitialNode(Node initialNode) {
		this.initialNode = initialNode;
	}

	CoordinatePair getGoalNodeCp() {
		return goalNodeCp;
	}

	void setGoalNodeCp(CoordinatePair goalNodeCp) {
		this.goalNodeCp = goalNodeCp;
	}

	public void search(boolean DEBUG) {
		EvaluationType[] evalTypes = {EvaluationType.EUCLIDEAN, EvaluationType.MANHATTAN, EvaluationType.EUCLIDEAN, EvaluationType.MANHATTAN};
		boolean addPathCost[] = {false, false, true, true};
		
		boolean empty = false;
		for (int m=0; m<4; ++m) {
			empty = false;
			DFSFringe dfsFringe = new DFSFringe(initialNode);
			int depth = 1;
			while (true) {
				if (dfsFringe.isEmpty()) {
					empty = true;
					break;
				}
				Node n = (Node) dfsFringe.poll();			
				AreaStatus as = n.getState().getAreaStatus();
				if (as.equals(AreaStatus.GOAL)) {
					n.setParent(dfsFringe.getCurrentPath().getLast());
					char c = 'f';
					if (addPathCost[m]) {
						System.out.println("f(N) = g(N) + h(N)");
						System.out.println("g(N) = cost of path found so far from initial to N");
						c = 'h';
					}
					if (evalTypes[m].equals(EvaluationType.EUCLIDEAN)) {
						System.out.println(""+c+"(N) = Euclidean distance from N to goal");
					} else if (evalTypes[m].equals(EvaluationType.MANHATTAN)) {
						System.out.println(""+c+"(N) = Manhattan distance to the goal");
					}
					dfsFringe.printResults(this, n);
					break;
				} else if (as.equals(AreaStatus.OBSTACLE)) continue;
				
				// DEBUG
				if (DEBUG) this.getNodes()[n.getState().getCoordinatePair().getFirstIndex()][n.getState().getCoordinatePair().getSecondIndex()].getState().setAreaStatus(AreaStatus.FINAL_PATH);
				
				CoordinatePair[] ec = n.expand();
				for (int i=0; i<ec.length; ++i) {
					if (ec[i].isOutOfBounds(this.getNodes().length, this.getNodes().length)) continue;
					else {
						Node child = this.getNodes()[ec[i].getFirstIndex()][ec[i].getSecondIndex()];
						// Avoid repeated states
						if (!dfsFringe.getCurrentPath().contains(child)) {
							child.setParent(n);
							child.setDepth(depth);
							
							// Step cost could vary according to the state of the successor node, but in this case, all steps have a cost of 1
							child.setTotalStepCost(depth);
							
							double hCost = -1.0;
							if (evalTypes[m].equals(EvaluationType.EUCLIDEAN)) {
								hCost = EvaluationHelper.euclideanDistance(child.getState().getCoordinatePair(), goalNodeCp);
								if (addPathCost[m]) {
									hCost += child.getTotalStepCost();
								}
							} else if (evalTypes[m].equals(EvaluationType.MANHATTAN)) {
								hCost = EvaluationHelper.manhattanDistance(child.getState().getCoordinatePair(), goalNodeCp);
								if (addPathCost[m]) {
									hCost += child.getTotalStepCost();
								}
							}
							child.setHCost(hCost);
													
							// BEGIN DEBUG
							if (DEBUG) {
								if (!(child.getState().getAreaStatus().equals(AreaStatus.OBSTACLE) || child.getState().getAreaStatus().equals(AreaStatus.GOAL))) {
									child.getState().setAreaStatus(AreaStatus.TMP);
								}
							}
							// END DEBUG
							
							dfsFringe.add(child);
						}
					}
				}
				
				// BEGIN DEBUG
				if (DEBUG) {
					for (int i=0; i<this.getNodes().length; ++i) {
						for (int j=0; j<this.getNodes()[i].length; ++j) {
							AreaStatus asm = this.getNodes()[i][j].getState().getAreaStatus();
							if (asm.equals(AreaStatus.FINAL_PATH)) {
								System.out.print('o');
							} else if (asm.equals(AreaStatus.TRAVERSABLE)) {
								System.out.print('.');
							} else if (asm.equals(AreaStatus.OBSTACLE)) {
								System.out.print('+');
							} else if (asm.equals(AreaStatus.GOAL)) {
								System.out.print('g');
							} else if (asm.equals(AreaStatus.INITIAL)) {
								System.out.print('i');
							} else if (DEBUG && asm.equals(AreaStatus.TMP)) {
								System.out.print('T');
							}
						}
						System.out.println();
					}
					System.out.println();
				}
				// END DEBUG
				
				dfsFringe.getCurrentPath().add(n);
				depth++;
			}
			if (empty) System.out.println("No solution found.");
		}
		
	}
}
