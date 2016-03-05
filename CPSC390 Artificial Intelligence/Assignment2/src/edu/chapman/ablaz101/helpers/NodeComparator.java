package edu.chapman.ablaz101.helpers;

import java.util.Comparator;

import edu.chapman.ablaz101.models.Node;

public class NodeComparator implements Comparator<Node> {
	public NodeComparator(){}

	@Override
	public int compare(Node o1, Node o2) {
		if (o1.getHCost() < o2.getHCost()) {
			return -1;
		}
		if (o1.getHCost() > o2.getHCost()) {
			return 1;
		}
		return 0;
	}
	
}
