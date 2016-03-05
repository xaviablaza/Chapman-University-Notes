package edu.chapman.ablaz101.models;

import java.util.Collection;
import java.util.LinkedList;
import java.util.PriorityQueue;

import edu.chapman.ablaz101.enums.AreaStatus;
import edu.chapman.ablaz101.helpers.NodeComparator;
import edu.chapman.ablaz101.interfaces.Fringe;

public class DFSFringe implements Fringe<Object> {
	private PriorityQueue<Node> queue;
	private LinkedList<Node> en;
	public DFSFringe(Node initialNode) {
		queue = new PriorityQueue<Node>(10, new NodeComparator());
		en = new LinkedList<Node>();
		queue.add(initialNode);
	}
	
	public LinkedList<Node> getCurrentPath() {
		return en;
	}
	
	/**
	 * Prints the results after RobotGrid has searched
	 * @param RobotGrid rg
	 * @param Node goalNode
	 */
	void printResults(RobotGrid rg, Node goalNode) {
		double cost = 0.0;
		Node prevNode = goalNode;
		Node[][] nodes = rg.getNodes();
		while ((prevNode = prevNode.getParent()) != null) {
			CoordinatePair cp = prevNode.getState().getCoordinatePair();
			if (prevNode.getParent() != null) {
				nodes[cp.getFirstIndex()][cp.getSecondIndex()].getState().setAreaStatus(AreaStatus.FINAL_PATH);
			} else break;
		}
		for (int i=0; i<nodes.length; ++i) {
			for (int j=0; j<nodes[i].length; ++j) {
				AreaStatus as = nodes[i][j].getState().getAreaStatus();
				if (as.equals(AreaStatus.FINAL_PATH)) {
					System.out.print('o');
					cost += nodes[i][j].getHCost();
				} else if (as.equals(AreaStatus.TRAVERSABLE)) {
					System.out.print('.');
				} else if (as.equals(AreaStatus.OBSTACLE)) {
					System.out.print('+');
				} else if (as.equals(AreaStatus.GOAL)) {
					System.out.print('g');
				} else if (as.equals(AreaStatus.INITIAL)) {
					System.out.print('i');
				}
			}
			System.out.println();
		}
		System.out.println("Path cost from initial to goal: " + cost);
		int genNodes = en.size()+1;
		System.out.println("Nodes generated: " + genNodes);
	}

	/**
     * Inserts the specified element into this priority queue.
     *
     * @return {@code true} (as specified by {@link Collection#add})
     * @throws ClassCastException if the specified element cannot be
     *         compared with elements currently in this priority queue
     *         according to the priority queue's ordering
     * @throws NullPointerException if the specified element is null
     */
	@Override
	public boolean add(Object e) {
		return queue.add((Node) e);
	}

	/**
     * Removes all of the elements from this priority queue.
     * The queue will be empty after this call returns.
     */
	@Override
	public void clear() {
		queue.clear();
	}

	/**
     * Returns {@code true} if this queue contains the specified element.
     * More formally, returns {@code true} if and only if this queue contains
     * at least one element {@code e} such that {@code o.equals(e)}.
     *
     * @param o object to be checked for containment in this queue
     * @return {@code true} if this queue contains the specified element
     */
	@Override
	public boolean contains(Object o) {
		return queue.contains(o);
	}

	@Override
	public Object peek() {
		return queue.peek();
	}

	@Override
	public Object poll() {
		return queue.poll();
	}

	/**
     * Removes a single instance of the specified element from this queue,
     * if it is present.  More formally, removes an element {@code e} such
     * that {@code o.equals(e)}, if this queue contains one or more such
     * elements.  Returns {@code true} if and only if this queue contained
     * the specified element (or equivalently, if this queue changed as a
     * result of the call).
     *
     * @param o element to be removed from this queue, if present
     * @return {@code true} if this queue changed as a result of the call
     */
	@Override
	public Node remove() {
		return queue.remove();
	}

	@Override
	public int size() {
		return queue.size();
	}

	@Override
	public boolean isEmpty() {
		return queue.isEmpty();
	}
	
}