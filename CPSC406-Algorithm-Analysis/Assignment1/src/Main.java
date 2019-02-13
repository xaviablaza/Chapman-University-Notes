import java.io.File;
import java.io.IOException;
import java.util.UUID;

public class Main {

    public static void main(String[] args) throws IOException {
        FileHandler fileHandler = new FileHandler();
        Nfa nfa = fileHandler.parseFile(new File(args[0]));
        if (nfa != null) {
            fileHandler.writeToFile(nfa.convert(), UUID.randomUUID().toString() + ".dfa");
        }
    }
}
