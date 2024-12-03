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
#include <unordered_set> // may be useless 
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

int checkReport(vector<int>& report, unordered_set<int>& positiveIncrements, unordered_set<int>& negativeIncrements){
  // size_t numLevels = report.;
  vector<int>::iterator a;
  vector<int>::iterator b;

  // two pointer approach?
  auto itr = report.begin();
  int difference = *(itr + 1) - *(itr);
  int isIncreasing = (difference > 0) ? true : false;
  int errors = 0; // tracks # of bad level differences
  // early exit for 0 difference 
  if ((!positiveIncrements.count(difference) && isIncreasing ) || (!negativeIncrements.count(difference) && !isIncreasing)) {errors++; }// difference out of range ex 0, -4, 6, 4,-8 
  itr++;
  // checks for valid adjacent levelDifferences based on whether the report intially starts as increasing or decreasing
  while (itr != report.end() - 1) {
    switch (isIncreasing) {
      case 1:
      difference = *(itr + 1) - *(itr); 
      if (positiveIncrements.count(difference) == 0){
        if (errors < 1) {
          errors++;
        }
        else {
          return 0;
        }
      }
      else {
        
        itr++;
      }
      break;
      case 0:
      difference = *(itr + 1) - *(itr); 
      if (negativeIncrements.count(difference) == 0){
        if (errors < 1) {
          errors++;
        }
        else {
          return 0;
        }
      }
      else {
        itr++;
        continue;
      }
      break;
      default:
      return 0;
      break;
    }
  }
  return 1;
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

  unordered_set<int> positiveIncrements = {1,2,3};
  unordered_set<int> negativeIncrements = {-1,-2,-3};
  while (getline(reportsStream, line)) {
    vector<int> reportLine;
    splitReport(reportLine, line, delimiter);
    //cout << reportToString(reportLine) << endl;
    safeReports += checkReport(reportLine,positiveIncrements,negativeIncrements);
  }
  cout << safeReports << endl;
  return safeReports;
}
