public class NfaTransition {
    private NfaState startState;
    private NfaState endState;
    private String symbol;

    public NfaTransition(){}

    public NfaState getStartState() {
        return startState;
    }

    public void setStartState(NfaState startState) {
        this.startState = startState;
    }

    public NfaState getEndState() {
        return endState;
    }

    public void setEndState(NfaState endState) {
        this.endState = endState;
    }

    public String getSymbol() {
        return symbol;
    }

    public void setSymbol(String symbol) {
        this.symbol = symbol;
    }
}
