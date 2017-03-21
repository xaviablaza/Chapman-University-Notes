package assignment4.problem10;

import java.util.Scanner;

/**
 * Created by Xavi on 3/20/2017.
 */
public class TicTacToeBoard {
    private String[][] board = new String[3][3];

    public TicTacToeBoard() {
        int k = 1;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                board[i][j] = String.valueOf(k++);
            }
        }
    }

    public void printBoard() {
        int k = 1;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                System.out.print(board[i][j]);
            }
            System.out.print('\n');
        }
    }

    public void startGame() {
        Scanner scanner = new Scanner(System.in);
        String inp = "X";
        for (int k=0; k<9; ++k) {
            System.out.println(inp+ "'s turn. Type in the space you'd like to place an " + inp + " in:");
            int xInput = scanner.nextInt();
            if (xInput > 0 && xInput < 10) {
                int i = 0, j = 0;
                switch (xInput) {
                    case 2:
                        j = 1;
                        break;
                    case 3:
                        j = 2;
                        break;
                    case 4:
                        i = 1;
                        break;
                    case 5:
                        i = 1;
                        j = 1;
                        break;
                    case 6:
                        i = 1;
                        j = 2;
                        break;
                    case 7:
                        i = 2;
                        break;
                    case 8:
                        i = 2;
                        j = 1;
                        break;
                    case 9:
                        i = 2;
                        j = 2;
                        break;
                }
                if (!board[i][j].equalsIgnoreCase("O") && !board[i][j].equalsIgnoreCase("X")) {
                    board[i][j] = inp;
                    printBoard();
                } else {
                    System.out.println("There is an O or X and the position inputted. Exiting...");
                }
            } else {
                System.out.println("Input needs to be from 1 to 9. Exiting...");
            }
            if (inp.equals("X")) {
                inp = "O";
            } else inp = "X";
        }

    }

}
