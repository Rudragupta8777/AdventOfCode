#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> between(string line, vector<int>position, vector<int> posit){
    
}

vector<int> closeBracket(string line){
    vector<int> find_index_again;
    string find = ")";
    int index = 0;

    while ((index = line.find(find, index)) != -1){
        find_index_again.push_back(index);
        index = find.length() + index;
    }
    return find_index_again;
}

vector<int> mul_OpenBracket(string line) {
    vector<int> find_index;
    string find = "mul(";
    int index = 0;

    while ((index = line.find(find, index)) != -1) {
        find_index.push_back(index);
        index = find.length() + index;
    }

    return find_index;
}

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "File not processed" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        vector<int> position = mul_OpenBracket(line);
        vector<int> posit = closeBracket(line);
        for (int pos : position) {
            cout << "Found at index mul(: " << pos << endl;
        }
        for (int pos : posit) {
            cout << "Found at index ): " << pos << endl;
        }
    }
    return 0;
}
