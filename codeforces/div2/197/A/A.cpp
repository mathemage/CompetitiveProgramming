/* ========================================

   * File Name : A.cpp

   * Creation Date : 05-03-2015

   * Last Modified : Thu 05 Mar 2015 03:57:09 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/339/A

   * Duration : 7 min

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
  char c;
  vector<int> cnt(3,0);
  int tot = 0;
  while (cin >> c) {
    if (c != '+') {
      cnt[c-'1']++;
      tot++;
    }
  }

  REP(i,3) {
    REP(j,cnt[i]) {
      cout << i+1;
      if (--tot > 0) {
        cout << "+";
      }
    }
  }
  return 0;
}
