/**
 * @file part1.cpp
 * @author Christian Velasquez
 * @brief Advent of Code Solution program for Day 2 Part 1
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

using namespace std;

void splitReport(vector<int>& currReport, string& line, string& delimiter) {
  while (line.find(delimiter) != line.npos) {
    // separate token
    string token = line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());
    // erase token + delimiter from string
    currReport.push_back(stoi(token));  // add token to report
  }
  currReport.push_back(
      stoi(line));  // final level does not have a delimiter at the end
  return;
}

string reportToString(vector<int>& report) {
  string boi = "";
  for (auto it : report) {
    boi += to_string(it) + " ";
  }
  return boi;
}

int checkReport(vector<int>& report) {
  // size_t numLevels = report.;
  vector<int>::iterator a;
  vector<int>::iterator b;

  // two pointer approach?
  for (auto itr = report.begin(); itr != report.end() - 1; itr++) {
    int difference = *(itr + 1) - *(itr);
    cout << difference << "  ";
  }
  cout << endl;
}
/**
 * @brief Day 2 Red-Nosed Reports
 *
 * @return safeReports
 */
int main() {
  ifstream reportsStream("input");
  string line;
  uint16_t safeReports = 0;
  string delimiter = " ";
  while (getline(reportsStream, line)) {
    vector<int> reportLine;
    splitReport(reportLine, line, delimiter);
    cout << reportToString(reportLine) << endl;
    safeReports += checkReport(reportLine);
  }

  cout << safeReports << endl;
  return safeReports;
}
