/* ========================================

   * File Name : A.cpp

   * Creation Date : 05-03-2015

   * Last Modified : Thu 05 Mar 2015 07:18:33 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/58/problem/A

   * Duration : 16 min

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
  string s;
  cin >> s;
  string h = "hello";
  int i = 0;
  for (auto & c : s) {
    if (c == h[i]) {
      i++;
    }
    if (i == h.size()) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
