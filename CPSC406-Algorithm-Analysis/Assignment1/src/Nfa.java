import java.util.*;

public class Nfa {
    private Map<String, NfaState> states;
    private String[] symbols;
    private final NfaState startState;
    private Map<NfaState, DfaState> closures;

    public Nfa(Map<String, NfaState> states, String[] symbols, NfaState startState) {
        this.states = states;
        this.symbols = symbols;
        this.startState = startState;
        this.closures = new HashMap<>();
    }

    /**
     * Converts the NFA to DFA
     * @return List result of converted NFA
     */
    public List<String> convert() {
        List<String> output = new LinkedList<>();
        output.add(printPowerSet());
        output.add(printAlphabet());

        // Calculate all epsilon transitions before printing transitions
        calculateEpsilonClosures();

        // Print the start state, which is the epsilon closure of the nfa's start state
        output.add(printStartState());

        // Print the accept states (all subsets that have the accept state)
        output.add(printAcceptStates());

        // Print the transitions
        output.add(printTransitions());

        return output;
    }

    /**
     * Calculates epsilon closure of every state in NFA
     */
    private void calculateEpsilonClosures() {
        for (NfaState nfaState : states.values()) {
            closures.put(nfaState, eclosure(nfaState));
        }
    }

    /**
     * Creates power set of NFA states
     * @return edu.chapman.ablaz101.DfaState[] all subsets of NFA states
     */
    private DfaState[] createPowerSet() {
        // Convert keyset of nfa-states to array
        String[] array = new String[states.size()];
        int k = 0;
        for (String s : states.keySet()) {
            array[k++] = s;
        }

        // Init array of dfa-states
        int psetSize = (int)Math.pow(2, array.length);
        DfaState[] subsets = new DfaState[psetSize];

        // Bit-wise method to generate power set
        for (int i = 0; i<psetSize; ++i) {
            Set<NfaState> nfaStates = new HashSet<>();
            for (int j = 0; j<states.size(); ++j) {
                if ((i & (1 << j)) > 0) {
                    nfaStates.add(states.get(array[j]));
                }
            }
            subsets[i] = new DfaState(nfaStates);
        }
        return subsets;
    }

    /**
     * @return String the power set of NFA states
     */
    private String printPowerSet() {
        StringBuilder powerSet = new StringBuilder();
        for (DfaState dfaState : createPowerSet()) {
            powerSet.append(dfaState.toString());
            powerSet.append("\t");
        }
        return powerSet.toString();
    }

    /**
     * @return String the alphabet the DFA takes in
     */
    private String printAlphabet() {
        StringBuilder alphabet = new StringBuilder();
        for (String s : symbols) {
            alphabet.append(s);
            alphabet.append("\t");
        }
        return alphabet.toString();
    }

    /**
     * @return String the start state of DFA
     */
    private String printStartState() {
        DfaState dfaState = closures.get(startState);
        return dfaState.toString();
    }

    /**
     * @return List<edu.chapman.ablaz101.DfaState> of all DFA accept states; all states containing the NFA accept state
     */
    private List<DfaState> createDFAAcceptStates() {
        // Get the accepted states
        List<String> nfaAcceptStates = new ArrayList<>();
        for (String state : states.keySet()) {
            if (states.get(state).isAccept()) {
                nfaAcceptStates.add(state);
            }
        }

        List<DfaState> acceptStates = new LinkedList<>();
        for (DfaState dfaState : createPowerSet()) {
            for (String nfaState : nfaAcceptStates) {
                if (dfaState.contains(states.get(nfaState))) {
                    acceptStates.add(dfaState);
                }
            }
        }
        return acceptStates;
    }

    /**
     * @return String the accept states of the DFA
     */
    private String printAcceptStates() {
        StringBuilder acceptStates = new StringBuilder();
        for (DfaState dfaAcceptState : createDFAAcceptStates()) {
            acceptStates.append(dfaAcceptState.toString());
            acceptStates.append("\t");
        }
        return acceptStates.toString();
    }

    /**
     * Generates a DFA state, which is the epsilon closure of an NFA state
     * @param state edu.chapman.ablaz101.NfaState
     * @return edu.chapman.ablaz101.DfaState
     */
    private DfaState eclosure(NfaState state) {
        DfaState dfaState = new DfaState();
        List<NfaState> tempList = new ArrayList<>();

        // For every transition in the NFA
        for (NfaTransition t : state.getTransitions()) {
            // If the transition is an epsilon transition
            if (t.getSymbol().equalsIgnoreCase("EPS")) {
                // Add EPS transition to dfa-state if nfa-state is not already there (avoid repeated states)
                NfaState nfaState = t.getEndState();
                if (!dfaState.contains(nfaState)) {
                    tempList.add(t.getEndState());
                }
                dfaState.add(nfaState);
            }
        }

        // If the templist is empty then we are finished
        while (!tempList.isEmpty()) {
            for (NfaTransition t : tempList.get(0).getTransitions()) {
                if (t.getSymbol().equalsIgnoreCase("EPS")) {
                    NfaState nfaState = t.getEndState();
                    if (!dfaState.contains(nfaState)) {
                        tempList.add(t.getEndState());
                    }
                    dfaState.add(nfaState);
                }
            }
            tempList.remove(0);
        }

        // Add the initial state if it's not already there and return
        dfaState.add(state);
        return dfaState;
    }

    /**
     * @return String all transitions of the DFA
     */
    private String printTransitions() {
        // Init a set of dfa-states we have already seen
        Set<Set<NfaState>> seenStates = new HashSet<>();

        // States waiting to be calculated
        List<DfaState> tempDfaStates = new ArrayList<>();

        // List of dfa transitions
        List<DfaTransition> dfaTransitions = new LinkedList<>();

        // This holds the end state of a transition
        DfaState endState;

        // Define the beginning dfa-state
        DfaState currState = closures.get(startState);

        // Add the beginning dfa-state to seenStates; we don't need to calculate the transition where this dfa-state
        // transitions to itself
        seenStates.add(currState.getNfaStates());

        for (String symbol : symbols) {
            endState = new DfaState();
            for (NfaState nfaState : currState.getNfaStates()) {
                // Add to the dfaState the set of nfa-states when applying the transition
                // Take the union of the transition value and the closure of each state
                // if any new state is found, take it as the current state and repeat step 2
                // repeat step 2 and 3 until no new state is present in the DFA transition table
                for (NfaState transitionedState : states.get(nfaState.toString()).transition(symbol)) {
                    endState.add(transitionedState);

                    // For each transitioned nfa-state, we add the epsilon closure of that state
                    for (NfaState epsilonState : closures.get(transitionedState).getNfaStates()) {
                        endState.add(epsilonState);
                    }
                }
            }
            // Check if the dfa-state we created is in seenStates; if not, add it to list of states to-be-calculated
            if (!seenStates.contains(endState.getNfaStates())) {
                tempDfaStates.add(endState);
            }
            dfaTransitions.add(new DfaTransition(currState, endState, symbol));
        }


        while (!tempDfaStates.isEmpty()) {
            currState = tempDfaStates.get(0);
            for (String symbol : symbols) {
                endState = new DfaState();
                for (NfaState nfaState : currState.getNfaStates()) {
                    for (NfaState transitionedState : states.get(nfaState.toString()).transition(symbol)) {
                        endState.add(transitionedState);
                        for (NfaState epsilonState : closures.get(transitionedState).getNfaStates()) {
                            endState.add(epsilonState);
                        }
                    }
                }
                if (!seenStates.contains(endState.getNfaStates())) {
                    tempDfaStates.add(endState);
                    seenStates.add(endState.getNfaStates());
                }
                dfaTransitions.add(new DfaTransition(currState, endState, symbol));
            }
            tempDfaStates.remove(0);
        }

        // Loop through the dfa-transitions and print nicely
        StringBuilder transitions = new StringBuilder();
        for (DfaTransition dfaTransition : dfaTransitions) {
            transitions.append(dfaTransition.toString());
            transitions.append("\n");
        }
        return transitions.toString();
    }
}
