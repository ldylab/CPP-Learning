//
// Created by Henry on 2021/12/10.
//

#ifndef BSTREE_TOOLS_H
#define BSTREE_TOOLS_H
#include "string"
using namespace std;

void split(const string &s, vector<string> &tokens,
           const string &delimiters = " ");

// string分割函数

void split(const string &s, vector<string> &tokens,
           const string &delimiters) {
  string::size_type lastPos = s.find_first_not_of(delimiters, 0);
  string::size_type pos = s.find_first_of(delimiters, lastPos);
  while (string::npos != pos || string::npos != lastPos) {
    tokens.push_back(
        s.substr(lastPos, pos - lastPos)); // use emplace_back after C++11
    lastPos = s.find_first_not_of(delimiters, pos);
    pos = s.find_first_of(delimiters, lastPos);
  }
}

#endif // BSTREE_TOOLS_H
