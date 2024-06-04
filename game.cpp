#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your code goes here

}

struct Game2048 {
    int board[4][4];

    void swipe_right(int arr[]) {
        int last_placed = 4;
        int can_merge = 0;
        for (int i = 3; i >= 0; i--) {
            if (arr[i] != 0) {
                if (can_merge) {
                    if (arr[i] == arr[last_placed]) {
                        arr[last_placed] *= 2;
                        if (i != last_placed) {
                            arr[i] = 0;
                        }
                        can_merge = 0;
                    } else {
                        arr[last_placed - 1] = arr[i];
                        last_placed--;
                        if (i != last_placed) {
                            arr[i] = 0;
                        }
                        can_merge = 1;
                    }

                } else {
                    arr[last_placed - 1] = arr[i];
                    last_placed--;
                    if (i != last_placed) {
                        arr[i] = 0;
                    }
                    can_merge = 1;
                }
            }
        }
    }

    bool has_game_ended() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 0) {
                    return false;
                }

            }

        }
        return true;
    }
    void random_populate() {
        while (true) {
            int i = rand() % 4;
            int j = rand() % 4;
            if (board[i][j] == 0) {
                int choice = rand() % 2;
                if (choice) {
                    board[i][j] = 2;
                } else {
                    board[i][j] = 4;
                }
                return;
            }
        }
    }

    void init() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = 0;
            }
        }
        random_populate();
        random_populate();
    }

    bool up() {
        for (int col = 0; col < 4; col++) {
            int arr[4];
            for (int row = 0; row < 4; row++) {
                arr[3 - row] = board[row][col];
            }
            swipe_right(arr);
            for (int row = 0; row < 4; row++) {
                board[row][col] = arr[3 - row];
            }
        }
        return move_end();
    }

    bool down() {
        for (int col = 0; col < 4; col++) {
            int arr[4];
            for (int row = 0; row < 4; row++) {
                arr[row] = board[row][col];
            }
            swipe_right(arr);
            for (int row = 0; row < 4; row++) {
                board[row][col] = arr[row];
            }
        }
        return move_end();
    }

    bool left() {
        for (int row = 0; row < 4; row++) {
            int arr[4];
            for (int col = 0; col < 4; col++) {
                arr[3 - col] = board[row][col];
            }
            swipe_right(arr);
            for (int col = 0; col < 4; col++) {
                board[row][col] = arr[3 - col];
            }
        }
        return move_end();
    }

    bool right() {
        for (int row = 0; row < 4; row++) {
            int arr[4];
            for (int col = 0; col < 4; col++) {
                arr[col] = board[row][col];
            }
            swipe_right(arr);
            for (int col = 0; col < 4; col++) {
                board[row][col] = arr[col];
            }
        }
        return move_end();
    }

    bool move_end() {
        if (has_game_ended()) {
            return true;
        } else {
            random_populate(); return false;
        }
    }
    void print_board() {
        cout << "\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j]) {
                    cout << board[i][j] << "\t";
                } else {
                    cout << "-\t";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    srand(time(0));

    Game2048 myGame;
    myGame.init();

    while (true) {
        myGame.print_board();
        cout << "What move ?(U,D,L,R)\n";
        char ch;
        cin >> ch;
        int ended = 0;
        if (ch == 'U') {
            ended = myGame.up();
        } else if (ch == 'D') {
            ended = myGame.down();
        } else if (ch == 'L') {
            ended = myGame.left();
        } else if (ch == 'R') {
            ended = myGame.right();
        }
        if (ended) {
            myGame.print_board();
            cout << "GAME ENDED !!!";
            return 0;
        }
    }
    
}
