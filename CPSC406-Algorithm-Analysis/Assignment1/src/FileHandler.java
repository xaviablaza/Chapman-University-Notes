import java.io.*;
import java.util.*;

public class FileHandler {
    /**
     * Prompts for the file name from user input
     * @return File file
     */
    public File promptFileName() {
        // Read in the map file
        Scanner inputReader = new Scanner(System.in);
        System.out.print("Enter nfa file: ");
        String input = inputReader.nextLine();
        inputReader.close();
        return new File(input);
    }

    /**
     * Parses the file into a NFA
     * EPS is an epsilon transition
     * @param File file
     * @return edu.chapman.ablaz101.Nfa nfa
     */
    public Nfa parseFile(File file) {
        Nfa nfa = null;
        if (file.isFile() && file.exists()) {
            BufferedReader bufferedReader = null;
            try {
                FileReader fileReader = new FileReader(file);
                bufferedReader = new BufferedReader(fileReader);
                String line;

                // Read the states on the first line
                line = bufferedReader.readLine();

                // Convert rawStates into states
                Map<String, NfaState> states = new HashMap<>();
                String[] rawStates = line.split("\\t");
                for (String s : rawStates) {
                    states.put(s, new NfaState(s));
                }

                // Read the alphabet on the second line
                line = bufferedReader.readLine();
                String[] alphabet = line.split("\\t");

                // Read the start state on the third line
                line = bufferedReader.readLine();

                // Find the startState in states and set start:true
                states.get(line).setStart(true);
                NfaState startState = states.get(line);

                // Read the accept states on the fourth line
                line = bufferedReader.readLine();

                // Find acceptStates in states and set accepted:true
                String[] rawAcceptStates = line.split("\\t");
                for (String s: rawAcceptStates) {
                    states.get(s).setAccept(true);
                }

                // Read each transition and encode it
                while ((line = bufferedReader.readLine()) != null) {
                    NfaTransition t = new NfaTransition();
                    String[] s = line.split(",");
                    t.setStartState(states.get(s[0]));
                    String[] s2 = s[1].split("=");
                    t.setSymbol(s2[0]);
                    t.setEndState(states.get(s2[1]));
                    String[] s3 = line.split("=");
                    states.get(t.getStartState().toString()).addTransition(t);
                }

                bufferedReader.close();
                nfa = new Nfa(states, alphabet, startState);

            } catch (IOException e) {
                System.out.println("IOException occurred. Exiting...");
                return null;
            }
        } else {
            System.out.println("File does not exist. Exiting...");
            return null;
        }

        return nfa;
    }

    /**
     * Writes the output to a file
     * @param output DFA output
     * @param fileName DFA filename
     * @throws IOException
     */
    public void writeToFile(List<String> output, String fileName) throws IOException {
        FileWriter fileWriter = new FileWriter(fileName);
        PrintWriter printWriter = new PrintWriter(fileWriter);
        for (String s : output) {
            printWriter.println(s);
        }
        printWriter.close();
        fileWriter.close();
    }

}