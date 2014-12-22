/* ========================================

   * File Name : onp.cpp

   * Creation Date : 22-12-2014

   * Last Modified : Tue 23 Dec 2014 12:37:04 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL: http://www.spoj.com/problems/ONP/

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

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

//#define DEBUG

class Transformer {
    // returns position of last parsable character
    int infixToRPN(string & infix, int pos, int brackets) {
      if (pos >= infix.size())
        return infix.size()-1;

      int last;
      switch (infix[pos]) {
        case '(':
          return infixToRPN(infix, pos + 1, brackets + 1);
        case ')':
          return pos;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
          last = infixToRPN(infix, pos + 1, brackets);
          cout << infix[pos];
          if (brackets > 0)
            return infixToRPN(infix, last + 1, brackets);
          return last;
        default: // a-z
          cout << infix[pos];
          return infixToRPN(infix, pos + 1, brackets);
      }
    }

  public:
    void infixToRPN(string infix) {
#ifdef DEBUG
      cout << infix << " == ";
#endif
      if (infixToRPN(infix, 0, 0) != infix.size() - 1) {
        cerr << "Wrong infix!" << endl;
      }
    }
};

int main() {
  Transformer tr;

  int N;
  cin >> N;

  string line;
  while (N-- > 0) {
    cin >> line;
    tr.infixToRPN(line);
    cout << endl;
  }
  return 0;
}
