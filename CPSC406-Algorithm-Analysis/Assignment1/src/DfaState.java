import java.util.HashSet;
import java.util.Set;

public class DfaState {
    private Set<NfaState> nfaStates;

    public DfaState() {
        this.nfaStates = new HashSet<>();
    }

    public DfaState(Set<NfaState> nfaStates) {
        this.nfaStates = nfaStates;
    }

    /**
     * Formats the string in set notation
     * Uses EM for {}, the empty set
     * @return
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("{");
        for (NfaState nfaState : nfaStates) {
            sb.append(nfaState.toString());
            sb.append(", ");
        }
        int idx = sb.lastIndexOf(", ");
        if (idx == -1) {
            return "EM";
        } else {
            sb.replace(idx, sb.length(), "}");
        }
        return sb.toString();
    }

    public boolean contains(NfaState nfaState) {
        return nfaStates.contains(nfaState);
    }

    public boolean add(NfaState nfaState) {
        return nfaStates.add(nfaState);
    }

    public Set<NfaState> getNfaStates() {
        return nfaStates;
    }
}
