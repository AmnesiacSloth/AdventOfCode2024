/**
 * @file part1.cpp
 * @author Christian Velasquez
 * @brief Advent of Code Solution program for Day 1
 * @version 0.1
 * @date 2024-12-02
 *
 * @copyright Copyright (c) 2024
 *
 */

// I/O and file managements
#include <stdio.h>

#include <fstream>
#include <iostream>

// Containers
#include <queue>

// Datatypes
#include <string>

// Comparators
#include <functional>
using namespace std;

void populateLists(priority_queue<int, vector<int>, greater<int>>& left,
                   priority_queue<int, vector<int>, greater<int>>& right,
                   ifstream& input) {
  string line;
  while (getline(input, line)) {
    int leftElement =
        stoi(line.substr(0, line.find(' ')));  // start to first space
    int rightElement = stoi(
        line.substr(line.find("   ")));  // after 3 spaces (delimiter) to end
    // cout << leftElement << " " << rightElement << endl;
    left.push(leftElement);
    right.push(rightElement);
  }
  input.close();
}
/**
 * @brief Day 1 Historical Hysteria
 *
 * @return totalDistance, sum off all pairwise distances, always nonnegative
 */
int main() {
  priority_queue<int, vector<int>, greater<int>> leftList;
  priority_queue<int, vector<int>, greater<int>> rightList;
  ifstream inputFile("input");

  populateLists(leftList, rightList, inputFile);

  // calcualte total distance
  int totalDistance = 0;
  while (!leftList.empty()) {
    totalDistance += abs(leftList.top() - rightList.top());
    leftList.pop();
    rightList.pop();
  }
  cout << totalDistance << endl;
  return totalDistance;
}
