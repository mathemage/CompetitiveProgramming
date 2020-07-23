 
/* ========================================

   * File Name : 25.cpp

   * Creation Date : 23-07-2020

   * Last Modified : Čt 23. července 2020, 20:51:43

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2019/qualification-round/problems/C

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;

template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

// start and end are inclusive positions
int parse(const string & E, int start, int end) {
  if (start == end) {
    return start;
  } else {
    int opened_brackets = 0;
    for (int pos = start + 1; pos <= end - 1; pos++) {
      if (E[pos] == '(') {
        opened_brackets++;
      } else if (E[pos] == ')') {
        opened_brackets--;
      }

      if (opened_brackets == 0) {
        return pos + 1;
      }
    }
  }

  return -2;
}

// shortcut for binary values
#define B00 0
#define B01 1
#define B10 2
#define B11 3
#define B_ERR 4

short eval(const string & E, int start, int end) {
  short result = B_ERR;
  return result; // mock result
}

int get_result(string E) {
  int result = -1;    // mock result

  int split = -1;
  int len = E.size() - 1;
  split = parse(E, 0, len);
//   test split
//   cout << endl; MSG(E) MSG(split) cout << endl;

  short left_vals = eval(E, 0, split - 1);
  short right_vals = eval(E, split + 1, len);
//   MSG(left_vals) MSG(right_vals)

  return result;
}

int main() {
  int T;
  cin >> T;
//   MSG(T)

  string E;
  REP(i,T) {
    cin >> E;
//     MSG(E)

    cout << "Case #" << i + 1 << ": " << get_result(E) << endl;
  }

  return 0;
}
