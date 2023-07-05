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

int getTotalCalOfTop3Elves(vector<int> calories) {
    int heightCal = 0;
    int secondHeightCal = 0;
    int thirdHeightCal = 0;

    for (int cal : calories) {
        if (cal > heightCal) {
            thirdHeightCal = secondHeightCal;
            secondHeightCal = heightCal;
            heightCal = cal;
        } else if (cal <= heightCal && cal > secondHeightCal) {
            thirdHeightCal = secondHeightCal;
            secondHeightCal = cal;
        } else if (cal <= secondHeightCal && cal > thirdHeightCal) {
            thirdHeightCal = cal;
        };
    }
    return heightCal + secondHeightCal + thirdHeightCal;
};

int main() {
    vector<int> calories;
    readAndStoreCalories(&calories);
    int sumOfTop3Elves = getTotalCalOfTop3Elves(calories);
    cout << "Top 3 Elves carrying in total " << sumOfTop3Elves;
    return 0;
};