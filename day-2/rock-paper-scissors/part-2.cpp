#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream inputFile("../input.txt");
    if (!inputFile) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    int totalScore = 0;
    string line;
    while (getline(inputFile, line)) {

        int delta = (line[2] + line[0] - 128 - 25) % 3;
        if (delta == 0) {
            delta = 3;
        }

        totalScore += delta + ((line[2] - 'X') * 3);
    }
    inputFile.close();

    cout << "Total Score: " << totalScore << endl;

    return 0;
}