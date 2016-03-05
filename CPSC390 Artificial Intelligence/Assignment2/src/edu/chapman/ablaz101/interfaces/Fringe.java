package edu.chapman.ablaz101.interfaces;

import edu.chapman.ablaz101.models.Node;

public interface Fringe<E> {
	
	public boolean add(E e);
	public void clear();
	public boolean contains(Object o);
	public E peek();
	public E poll();
	public Node remove();
	public int size();
	public boolean isEmpty();
	
}
