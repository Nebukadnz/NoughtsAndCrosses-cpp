#include <iostream>
#include <string>

void displayBoard(char board[3][3]) {
    // Outputs the board to the console
    for (int i {0}; i < 3; i++){
        for (int j {0}; j < 3; j++) {
            std::cout << board[i][j];
            if (j != 2) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
}

short turn(char board[3][3],short player) {
    int x,y;
    char playerPiece;
    if (player == 1) {
        playerPiece = 'X';
    } else {
        playerPiece = 'O';
    }
    bool loop = true;
    bool playerWin = false;
    while (loop) {
        displayBoard(board);
        std::cout << playerPiece << "'s turn(x,y): ";
        std::cin >> x >> y;
        std::cout << std::endl;
        if (board[y][x] == '_') {
            board[y][x] = playerPiece;
            for (int i {0}; i<3; i++) {
                if (board[i][i] != '_') {
                    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                        // Check horizontal
                        playerWin = true;
                    } else if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                        // Check vertical
                        playerWin = true;
                    }
                }
            }
            if (board[1][1]!='_') {
                if (board[0][0] == board[1][1] and board[1][1] == board[2][2]) {
                    playerWin = true;
                } else if (board[0][2] == board[1][1] and board[1][1] == board[2][0]) {
                    playerWin = true;
                }
                // Check diagonals
            }
            loop = false;
        } else if (playerWin) {
            loop = false;
        } else {
            std::cout << "Invalid placement, try again\n";
        }
    }
    std::cout << '(' << x << ',' << y << ')' << std::endl;
    displayBoard(board);
    std::cout << std::endl;
    if (playerWin) {
        std::cout << "Player " << playerPiece << " wins!\n";
        return player;
    } else {
        return 0;
    }
}

short playRound() {
    char board[3][3] {
        {'_','_','_'},
        {'_','_','_'},
        {'_','_','_'}
    };
    short player {};
    short result {};
    for (int i {0}; i < 9; i++) {
        player = (i % 2) + 1;
        result = turn(board, player);
        if (result != 0) {
            return result;
        };
    }
    std::cout << "Game Draw!\n";
    return 0;
}

int main() {
    bool running = true;
    short result {};
    short X_Score,O_Score {};
    std::string choice {};
    while (running) {
        std::cout << "(Y/N)Play: ";
        std::cin >> choice;
        std::cout << std::endl;
        if (choice=="Y" || choice=="y") {
            result = playRound();
            if (result == 1) {
                ++X_Score;
            } else if (result == 2) {
                ++O_Score;
            }
            std::cout << "X = " << X_Score << "\nO = " << O_Score << "\n\n";
        } else {
            std::cout << "Thanks for playing!!" << std::endl;
            running = false;
        }
    }
    return 0;
}