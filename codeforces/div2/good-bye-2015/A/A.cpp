/* ========================================

   * File Name : A.cpp

   * Creation Date : 30-12-2015

   * Last Modified : Wed 30 Dec 2015 08:42:46 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/611/problem/0

   * Points Gained (in case of online contest) : 388 / 500 (hacked-AC)

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
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

int main() {
  int d, res;
  string type;

  cin >> d;
  cin >> type >> type;

  if (type == "month") {
    if (d <= 29) {
      res = 12;
    } else if (d == 30) {
      res = 11;
    } else {
      res = 7;
    }
  } else {
    if (d == 5 || d == 6) {
      res = 53;
    } else {
      res = 52;
    }
  }
  cout << res << endl;
  return 0;
}
