#include <fstream>
#include <iostream>
#include <unordered_set>
using namespace std;

void calcPower(const char &character, int *sum) {
    if (character >= 'a' && character <= 'z') {
        *sum += (character - 'a' + 1);
    } else if (character >= 'A' && character <= 'Z') {
        *sum += (character - 'A' + 27);
    }
};

void findAndGetSumOfCommonCharacters(int *sum, const string &string1, const string &string2) {
    unordered_set<char> charSet;
    std::unordered_set<char> commonChars;

    for (char s1 : string1) {
        charSet.insert(s1);
    };

    for (char s2 : string2) {
        if (charSet.count(s2) > 0 && commonChars.count(s2) == 0) {
            commonChars.insert(s2);
            calcPower(s2, sum);
        };
    };
};

int main() {
    fstream file;
    file.open("../input.txt");

    if (file.is_open()) {
        string line;
        int sum = 0;

        while (getline(file, line)) {
            size_t len = line.length();

            string firstHalf = line.substr(0, len / 2);
            string lastHalf = line.substr(len / 2, len);

            findAndGetSumOfCommonCharacters(&sum, firstHalf, lastHalf);
        };

        cout << "sum = " << sum << endl;
    };

    return 0;
};
