#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>  // Add this header for std::find

using namespace std;

class Player {
public:
    string name;
    char symbol;

    Player(string name, char symbol) : name(name), symbol(symbol) {}
};

class Board {
private:
    vector<char> board;

public:
    Board() : board(9, ' ') {}

    void display() {
        cout << "Current board:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i * 3 + j] << " | ";
            }
            cout << endl << "-------------\n";
        }
    }

    bool is_winner(char symbol) {
        int winning_combinations[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // horizontal
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // vertical
            {0, 4, 8}, {2, 4, 6}              // diagonal
        };
        for (auto &combo : winning_combinations) {
            if (board[combo[0]] == symbol && board[combo[1]] == symbol && board[combo[2]] == symbol) {
                return true;
            }
        }
        return false;
    }

    bool is_full() {
        return find(board.begin(), board.end(), ' ') == board.end();
    }

    bool make_move(int position, char symbol) {
        if (board[position] == ' ') {
            board[position] = symbol;
            return true;
        }
        return false;
    }
};

class Game {
private:
    Board board;
    Player player1;
    Player player2;

public:
    Game() : player1("Player", 'X'), player2("AI", 'O') {}

    void play() {
        Player* current_player = &player1;
        while (true) {
            board.display();
            int position;

            if (current_player == &player1) {
                cout << current_player->name << "'s turn (0-8): ";
                cin >> position;
            } else {
                position = ai_move();
                cout << current_player->name << " chose position " << position << endl;
            }

            if (board.make_move(position, current_player->symbol)) {
                if (board.is_winner(current_player->symbol)) {
                    board.display();
                    cout << current_player->name << " wins!" << endl;
                    break;
                }
                if (board.is_full()) {
                    board.display();
                    cout << "It's a draw!" << endl;
                    break;
                }
                current_player = (current_player == &player1) ? &player2 : &player1;
            } else {
                cout << "Invalid move, try again." << endl;
            }
        }
    }

    int ai_move() {
        vector<int> available_moves;
        for (int i = 0; i < 9; ++i) {
            if (board.make_move(i, ' ')) {
                available_moves.push_back(i);
                board.make_move(i, ' '); // Reset the move
            }
        }
        srand(time(0));
        return available_moves[rand() % available_moves.size()];
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
