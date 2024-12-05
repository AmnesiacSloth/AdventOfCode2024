#include <stdio.h>

#include <fstream>
#include <iostream>
#include <stack>
// Datatypes
#include <regex>
#include <string>
using namespace std;

void tokenize(stack<int>& tokens, string& text, string& delimiter) {
  bool isEnabled = true;
  while (text.find(delimiter) != text.npos) {
    // separate token
    string token = text.substr(0, text.find(delimiter));
    text.erase(0, text.find(delimiter) + delimiter.length());
    // erase token + delimiter from string
    if (token == "Z") {
      isEnabled = false;
    } else if (token == "X") {
      isEnabled = true;
    } else {
    }
    if (isEnabled && token != "X") {
      // cout << "here" << endl;
      tokens.push(stoi(token));  // add token to report
    } else {
      continue;
    }
  }
  return;
}

void createString(string& text, ifstream& input) {
  string line;
  while (getline(input, line)) {
    text += line;
  }
  input.close();
}

void replaceAll(string& input, string findThis, string replacewith) {
  size_t startposition = 0;

  // from the start position , which is the beginning of what we are trying to
  // replace, take the replaced strings length so we capture it all, and replace
  // it with the new string.
  while ((startposition = input.find(findThis, startposition)) !=
         string::npos) {
    input.replace(startposition, findThis.length(),
                  replacewith);  // comment above
    startposition +=
        replacewith.length();  // move the start position forwards since we deal
                               // with the previous occurence already
  }
}
int main() {
  ifstream boi("input");
  string totalText;
  string onlyMul;
  createString(totalText, boi);  // parse input file
  regex mulMatch("mul\\([0-9]+,[0-9]+\\)|don\'t\\(\\)|do\\(\\)");
  auto wordsBegin =
      sregex_iterator(totalText.begin(), totalText.end(), mulMatch);
  auto wordsEnd = sregex_iterator();  // ?? idk how this works really well

  while (wordsBegin != wordsEnd) {
    smatch match = *wordsBegin;  // dereference for each match??
    onlyMul += match.str();
    wordsBegin++;
  }
  cout << onlyMul << endl;
  regex dontDetector("don\'t");
  // replaceAll(onlyMul, "don\'t", "#");
  replaceAll(onlyMul, "mul(", "");
  replaceAll(onlyMul, ")", ",");
  // replaceAll(onlyMul, "(", "");
  replaceAll(onlyMul, "don\'t(,", "Z,");
  replaceAll(onlyMul, "do(,", "X,");
  cout << onlyMul << endl;
  stack<int> multiplyboiz;
  string delim = ",";
  tokenize(multiplyboiz, onlyMul, delim);
  int endresult = 0;
  while (!multiplyboiz.empty()) {
    int op1 = multiplyboiz.top();
    multiplyboiz.pop();
    int op2 = multiplyboiz.top();
    multiplyboiz.pop();
    int result = op1 * op2;
    endresult += result;
  }
  cout << endresult << endl;
  return endresult;
}