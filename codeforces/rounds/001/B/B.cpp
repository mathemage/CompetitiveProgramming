/* ========================================

   * File Name : B.cpp

   * Creation Date : 23-12-2014

   * Last Modified : Tue 23 Dec 2014 09:03:42 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/1/problem/B

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <cctype>
#include <regex>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

void excelToRC(string excel) {
  int row = 0, col = 0;
  for (char c : excel) {
    if (isalpha(c)) {
      col = 26 * col + c - 'A' + 1;
    } else {
      row = 10 * row + c - '0';
    }
  }
  cout << "R" << row << "C" << col;
}

void RCToExcel(string rc) {
  int row=0, col=0;
  sscanf(rc.c_str(), "R%dC%d", &row, &col);

  string c;
#ifdef DEBUG
  MSG(col)
#endif
    do {
      int letter = (col%26) ? (col%26) : 26;
      c += 'A'-1 + letter;
      col = (col - letter) / 26;
#ifdef DEBUG
      MSG(col)
      MSG(c)
#endif
    } while (col > 0);

  reverse(ALL(c));

  cout <<  c << row;
}

int main() {
  int n;
  cin >> n;

  string line;
  REP(i,n) {
    cin >> line;
    int j = 0;
    while (isalpha(line[j])) j++;
    while (j < line.size() && isdigit(line[j])) j++;

#ifdef DEBUG
    MSG(line) MSG(j) MSG(line.size())
    //if (std::regex_match(line, std::regex("[A-Z]+[0-9]+", std::regex_constants::basic))) {
#endif
    if (j == line.size()) {
#ifdef DEBUG
      cout << "Exc -> RC: ";
#endif
      excelToRC(line);
    } else {
#ifdef DEBUG
      cout << "RC -> Exc: ";
#endif
      RCToExcel(line);
    }
    cout << endl;
  }

  return 0;
}
