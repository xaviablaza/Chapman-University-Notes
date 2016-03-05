package edu.chapman.ablaz101.exceptions;

public class MalformedFileException extends Exception {
	private static final long serialVersionUID = -6985372219421973378L;
	public MalformedFileException(){}
	public MalformedFileException(String msg) {
		System.out.println(msg);
	}
}
