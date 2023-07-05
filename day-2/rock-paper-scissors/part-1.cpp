#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

enum PlayerMoves { A,
                   B,
                   C };
enum MyMoves { X,
               Y,
               Z };

PlayerMoves convertPlayeMoveToEnum(const string &word) {
    if (word == "A") {
        return A;
    } else if (word == "B") {
        return B;
    } else if (word == "C") {
        return C;
    }

    throw runtime_error("Invalid Word " + word);
};

MyMoves convertMyMoveToEnum(const string &word) {
    if (word == "X") {
        return X;
    } else if (word == "Y") {
        return Y;
    } else if (word == "Z") {
        return Z;
    }

    throw runtime_error("Invalid Word " + word);
};

void bonusPoints(const MyMoves &myMove, int *points) {
    switch (myMove) {
    case X:
        *points += 1;
        break;
    case Y:
        *points += 2;
        break;
    case Z:
        *points += 3;
        break;
    default:
        break;
    }
};

void gameLogic(const PlayerMoves &playerMove, const MyMoves &myMove, int *points) {
    switch (playerMove) {
    case A:
        switch (myMove) {
        case X:
            *points += 3;
            break;
        case Y:
            *points += 6;
            break;
        default:
            break;
        }
        break;
    case B:
        switch (myMove) {
        case Y:
            *points += 3;
            break;
        case Z:
            *points += 6;
            break;
        default:
            break;
        }
        break;
    case C:
        switch (myMove) {
        case X:
            *points += 6;
            break;
        case Z:
            *points += 3;
        default:
            break;
        }
        break;
    default:
        break;
    }
};

int main() {
    fstream file;
    file.open("../input.txt", ios::in);
    int points = 0;

    if (!file.is_open())
        return 0;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string playerMove, myMove;
        ss >> playerMove >> myMove;

        PlayerMoves playerMoveEnum = convertPlayeMoveToEnum(playerMove);
        MyMoves myMoveEnum = convertMyMoveToEnum(myMove);

        bonusPoints(myMoveEnum, &points);
        gameLogic(playerMoveEnum, myMoveEnum, &points);
    };
    cout << points << endl;
    file.close();
}