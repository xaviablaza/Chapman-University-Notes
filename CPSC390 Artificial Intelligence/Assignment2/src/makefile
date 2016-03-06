JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	src/edu/chapman/ablaz101/enums/AreaStatus.java \
	src/edu/chapman/ablaz101/enums/EvaluationType.java \
	src/edu/chapman/ablaz101/exceptions/MalformedFileException.java \
	src/edu/chapman/ablaz101/helpers/EvaluationHelper.java \
	src/edu/chapman/ablaz101/helpers/NodeComparator.java \
	src/edu/chapman/ablaz101/interfaces/Fringe.java \
	src/edu/chapman/ablaz101/models/CoordinatePair.java \
	src/edu/chapman/ablaz101/models/DFSFringe.java \
	src/edu/chapman/ablaz101/models/FileHandler.java \
	src/edu/chapman/ablaz101/models/Node.java \
	src/edu/chapman/ablaz101/models/NodeState.java \
	src/edu/chapman/ablaz101/models/RobotGrid.java \
	src/edu/chapman/ablaz101/Main.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
