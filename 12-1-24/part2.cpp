// I/O and file managements
#include <stdio.h>

#include <fstream>
#include <iostream>

// Containers
#include <unordered_map>
#include <vector>
// Datatypes
#include <string>

// Comparators
#include <functional>

using namespace std;

void populateLists(vector<int>& leftList, unordered_map<int, int>& rightList,
                   ifstream& input) {
  string line;
  while (getline(input, line)) {
    int leftElement =
        stoi(line.substr(0, line.find(' ')));  // start to first space
    int rightElement = stoi(
        line.substr(line.find("   ")));  // after 3 spaces (delimiter) to end
    // cout << leftElement << " " << rightElement << endl;
    leftList.push_back(leftElement);

    // if element already is in the list, increment
    if (!rightList.insert(make_pair(rightElement, 1)).second) {
      rightList.find(rightElement)->second++;
    };
  }
  input.close();
}

int main() {
  vector<int> leftList;
  unordered_map<int, int> rightList;
  ifstream inputFile("input");
  int totalSimilarityScore = 0;
  populateLists(leftList, rightList, inputFile);

  for (auto i = leftList.begin(); i != leftList.end(); i++) {
    // handle case where left list element doesnt exist in right
    // unordered_map<int, int>::iterator pairz = rightList.find(*i);
    if (rightList.end() == rightList.find(*i)) {
      totalSimilarityScore += 0;
    } else {
      totalSimilarityScore += *i * rightList.find(*i)->second;
    }
  }
  cout << totalSimilarityScore << endl;
  return totalSimilarityScore;
}