#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

bool Safe(const vector<int>& levels) {
    // default set as true
    bool valid_difference = true;
    bool increasing = true;
    bool decreasing = true;
    for (size_t i = 1; i < levels.size(); i++) {
        int diff = levels[i] - levels[i - 1];
        // Checking range
        if (diff < -3 || diff > 3 || diff == 0) {
            valid_difference = false;
            break;
        }
        if (diff > 0){
            decreasing = false;
        }
        if (diff < 0){
            increasing = false;
        }
    }
    // If valid mark as safe
    if (valid_difference && (increasing || decreasing)) {
        return true;
    }
    return false;
}

bool SafeRemovOneLevel(const vector<int>& level) {
    for (size_t i = 0; i < level.size(); i++) {
        vector<int> tempLevels = level;
        tempLevels.erase(tempLevels.begin() + i);
        if (Safe(tempLevels)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Reads input file
    ifstream file("input.txt");

    // Check if it's reading file or not
    if (!file.is_open()) {
        cout << "File not processed" << endl;
        return 1;
    }

    string line;
    int safe = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> level;
        int num;
        while (ss >> num) {
            level.push_back(num);
        }
        bool safeReport = false;
        if (Safe(level)) {
            safeReport = true;
        } else {
            if (SafeRemovOneLevel(level)) {
                safeReport = true;
            }
        }
        if (safeReport) {
            safe++;
        }
    }

    file.close();
    cout << safe << endl;
    return 0;
}
