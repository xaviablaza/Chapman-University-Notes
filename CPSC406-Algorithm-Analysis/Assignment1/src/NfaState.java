import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class NfaState {
    private String state;
    private boolean isStart;
    private boolean isAccept;
    private List<NfaTransition> transitions;

    public NfaState(String state) {
        this.state = state;
        this.isStart = false;
        this.isAccept = false;
        transitions = new ArrayList<>();
    }

    /**
     * Gets the set of nfa states transitioned to when applying a symbol to an NFA-state
     * @param symbol Symbol in the alphabet
     * @return Set of nfa states
     */
    public Set<NfaState> transition(String symbol) {
        Set<NfaState> nfaStates = new HashSet<>();
        for (NfaTransition t : transitions) {
            if (t.getSymbol().equals(symbol)) {
                nfaStates.add(t.getEndState());
            }
        }
        return nfaStates;
    }

    @Override
    public String toString() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public boolean isStart() {
        return isStart;
    }

    public void setStart(boolean start) {
        isStart = start;
    }

    public boolean isAccept() {
        return isAccept;
    }

    public void setAccept(boolean accept) {
        isAccept = accept;
    }

    public void addTransition(NfaTransition t) {
        transitions.add(t);
    }

    public List<NfaTransition> getTransitions() {
        return transitions;
    }
}
