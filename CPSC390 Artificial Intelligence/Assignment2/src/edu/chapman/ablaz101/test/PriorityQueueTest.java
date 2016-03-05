package edu.chapman.ablaz101.test;

import java.util.Comparator;
import java.util.PriorityQueue;

public class PriorityQueueTest {

	public static void main(String[] args) {
		TestElement te1 = new TestElement(7);
		TestElement te2 = new TestElement(3);
		TestElement te3 = new TestElement(8);
		TestElement te4 = new TestElement(9);
		TestElement te5 = new TestElement(10);
		TestElement te6 = new TestElement(2);
		TestElement te7 = new TestElement(5);
		TestElement te8 = new TestElement(4);
		TestElement te9 = new TestElement(2);
		TestElement te10 = new TestElement(11);
		TestElement te11 = new TestElement(6);
		PriorityQueue<TestElement> queue = new PriorityQueue<TestElement>(11, new EZComparator());
		queue.add(te1);
		queue.add(te2);
		queue.add(te3);
		queue.add(te4);
		queue.add(te5);
		queue.add(te6);
		queue.add(te7);
		queue.add(te8);
		queue.add(te9);
		queue.add(te10);
		queue.add(te11);
		while (queue.size() != 0) {
			System.out.println(queue.poll().n);
		}
	}
}

class TestElement {
	public int n;
	public TestElement(int n) {
		this.n = n;
	}
}

class EZComparator implements Comparator<TestElement> {

	@Override
	public int compare(TestElement o1, TestElement o2) {
		if (o1.n < o2.n) {
			return -1;
		}
		if (o1.n > o2.n) {
			return 1;
		}
		return 0;
	}
	
}