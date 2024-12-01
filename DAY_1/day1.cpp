#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int max_no_lines = 1000;

int main() {
  ifstream file("input.txt");

  if (!file) {
    cout << "File not processed" << endl;
    return 1;
  }

  string line;
  int left_arr[max_no_lines];
  int right_arr[max_no_lines];
  int count = 0;

  while (getline(file, line) && count < max_no_lines) {
    stringstream ss(line);
    string int1, int2;

    if (ss >> int1 >> int2) {
      left_arr[count] = stoi(int1);
      right_arr[count] = stoi(int2);
      count++;
    }
  }
  file.close();

  sort(left_arr, left_arr + count);
  sort(right_arr, right_arr + count);

  int sum_of_difference = 0;
  for (int i = 0; i < count; i++) {
    int difference = abs(left_arr[i] - right_arr[i]);
    sum_of_difference = sum_of_difference + difference;
  }
  cout << sum_of_difference << endl;
  return 0;
}