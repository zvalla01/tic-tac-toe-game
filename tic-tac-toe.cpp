/*
My first ever C++ Game Made
Took about 5 Days :)
*/

#include <iostream>
#include <string>
using namespace std;

char box[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
bool isTie = false;

string s1 = "";
string s2 = "";

void board() {
    cout << "    |     |   \n";
    cout << " " << box[0][0] << "  |  " << box[0][1] << "  |  " << box[0][2] << "\n";
    cout << "____|_____|____\n";
    cout << "    |     |   \n";
    cout << " " << box[1][0] << "  |  " << box[1][1] << "  |  " << box[1][2] << "\n";
    cout << "____|_____|____\n";
    cout << "    |     |   \n";
    cout << " " << box[2][0] << "  |  " << box[2][1] << "  |  " << box[2][2] << "\n";
    cout << "    |     |   \n";
}

void playerInput() {
    int digit;
    if (token == 'X') {
        cout << s1 << ", please enter a number: ";
    } else {
        cout << s2 << ", please enter a number: ";
    }
    cin >> digit;

    if (digit >= 1 && digit <= 9) {
        int index = digit - 1;
        row = index / 3;
        column = index % 3;

        if (box[row][column] != 'X' && box[row][column] != 'O') {
            box[row][column] = token;
            token = (token == 'X') ? 'O' : 'X';
        } else {
            cout << "Position already taken. Try again.\n";
            playerInput();
        }
    } else {
        cout << "Invalid input. Try again.\n";
        playerInput();
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (box[i][0] == box[i][1] && box[i][1] == box[i][2]) {
            return true;
        }
        if (box[0][i] == box[1][i] && box[1][i] == box[2][i]) {
            return true;
        }
    }
    if (box[0][0] == box[1][1] && box[1][1] == box[2][2]) {
        return true;
    }
    if (box[0][2] == box[1][1] && box[1][1] == box[2][0]) {
        return true;
    }
    return false;
}

bool checkisTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (box[i][j] != 'X' && box[i][j] != 'O') {
                return false;
            }
        }
    }
    isTie = true;
    return true;
}

int main() {
    cout << "Enter the name of the FIRST PLAYER: \n";
    getline(cin, s1);

    cout << "Enter the name of the SECOND PLAYER: \n";
    getline(cin, s2);

    cout << s1 << " is PLAYER_1 and will play FIRST\n";
    cout << s2 << " is PLAYER_2 and will play SECOND\n";

    while (!checkWin() && !checkisTie()) {
        board();
        playerInput();
    }

    board();

    if (checkWin()) {
        if (token == 'X') {
            cout << s2 << " WON!!!\n";
        } else {
            cout << s1 << " WON!!!\n";
        }
    } else if (isTie) {
        cout << "IT'S A DRAW!\n";
    }

    return 0;
}
