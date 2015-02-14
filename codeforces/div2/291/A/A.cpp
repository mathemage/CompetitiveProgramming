/* ========================================

   * File Name : A.cpp

   * Creation Date : 14-02-2015

   * Last Modified : Sat 14 Feb 2015 07:55:30 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/514/problem/A

   * Points Gained (in case of online contest) : failed systests

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()

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
  string s, res;
  int d;
  cin >> s;
  bool nz = false;
  for (auto & x : s) {
    d = (x-'0');
    if (d != 9 || nz) {
      nz = true;
      res += ('0' + min(d, 9-d));
    } else {
      res += x;
    }
  }
  if (res == "0") cout << s;
  else cout << res;

  return 0;
}
