public class DfaTransition {
    private DfaState startState;
    private DfaState endState;
    private String symbol;

    public DfaTransition(DfaState startState, DfaState endState, String symbol) {
        this.startState = startState;
        this.endState = endState;
        this.symbol = symbol;
    }

    /**
     * Formats the transition
     * [startState],[symbol]=[endState]
     * example: {1, 2},a={1, 2, 3}
     * @return String output
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(startState.toString());
        sb.append(',');
        sb.append(symbol);
        sb.append('=');
        sb.append(endState.toString());
        return sb.toString();
    }
}
