#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void readAndStoreCalories(vector<int> *calories) {
    fstream file;
    file.open("../input.txt", ios::in);

    if (file.is_open()) {
        string line;
        int sum = 0;
        while (getline(file, line)) {
            if (line.empty()) {
                calories->push_back(sum);
                sum = 0;
            } else {
                int count = stoi(line);
                sum += count;
            }
        }
        calories->push_back(sum);
    }
    file.close();
};

int getTheHeightCal(vector<int> calories) {
    int heightCal = calories.front();
    for (int cal : calories) {
        if (cal > heightCal) {
            heightCal = cal;
        }
    }
    return heightCal;
};

int main() {
    vector<int> calories;
    readAndStoreCalories(&calories);
    int heightCal = getTheHeightCal(calories);
    cout << "Height Cal is " << heightCal;
    return 0;
};