#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// defining the number of lines as constant variable
const int max_no_lines = 1000;

int main() {
  // Reads input file
  ifstream file("input.txt");

  // Check if it's reading file or not
  if (!file) {
    cout << "File not processed" << endl;
    return 1;
  }

  // create an left and right array of size 1000
  string line;
  int left_arr[max_no_lines];
  int right_arr[max_no_lines];
  int count = 0;

  while (getline(file, line) && count < max_no_lines) {
    stringstream ss(line);
    string int1, int2;

    // splitting the string, changing it to integer & pushing it into array
    if (ss >> int1 >> int2) {
      left_arr[count] = stoi(int1);
      right_arr[count] = stoi(int2);
      count++;
    }
  }
  file.close();

  // sorting array in ascending order
  sort(left_arr, left_arr + count);
  sort(right_arr, right_arr + count);

  // calculating the difference between two array
  int sum_of_difference = 0;
  for (int i = 0; i < count; i++) {
    int difference = abs(left_arr[i] - right_arr[i]);
    sum_of_difference = sum_of_difference + difference;
  }

  // printing the sum of difference between elements in a particular index
  cout << sum_of_difference << endl;
  return 0;
}