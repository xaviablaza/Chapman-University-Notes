JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	edu/chapman/ablaz101/enums/AreaStatus.java \
	edu/chapman/ablaz101/enums/EvaluationType.java \
	edu/chapman/ablaz101/exceptions/MalformedFileException.java \
	edu/chapman/ablaz101/helpers/EvaluationHelper.java \
	edu/chapman/ablaz101/helpers/NodeComparator.java \
	edu/chapman/ablaz101/interfaces/Fringe.java \
	edu/chapman/ablaz101/models/CoordinatePair.java \
	edu/chapman/ablaz101/models/DFSFringe.java \
	edu/chapman/ablaz101/models/FileHandler.java \
	edu/chapman/ablaz101/models/Node.java \
	edu/chapman/ablaz101/models/NodeState.java \
	edu/chapman/ablaz101/models/RobotGrid.java \
	edu/chapman/ablaz101/Main.java

default: classes jar

jar: classes
	jar cmf manifest.txt ../Assignment2.jar edu/chapman/ablaz101/enums/AreaStatus.class edu/chapman/ablaz101/enums/EvaluationType.class edu/chapman/ablaz101/exceptions/MalformedFileException.class edu/chapman/ablaz101/helpers/EvaluationHelper.class edu/chapman/ablaz101/helpers/NodeComparator.class edu/chapman/ablaz101/interfaces/Fringe.class edu/chapman/ablaz101/models/CoordinatePair.class edu/chapman/ablaz101/models/DFSFringe.class edu/chapman/ablaz101/models/FileHandler.class edu/chapman/ablaz101/models/Node.class edu/chapman/ablaz101/models/NodeState.class edu/chapman/ablaz101/models/RobotGrid.class edu/chapman/ablaz101/Main.class

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
