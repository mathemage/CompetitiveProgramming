/* ========================================

   * File Name : A.cpp

   * Creation Date : 04-03-2015

   * Last Modified : Wed 04 Mar 2015 10:59:25 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/118/A

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
  string w;
  cin >> w;
  for (auto & x : w) {
    x = tolower(x);
    bool next = false;
    for (char c : "aoyeui") {
      if (c == x) {
        next = true;
        break;
      }
    }
    if (!next) {
      printf(".%c", x);
    }
  }
  cout << endl;
  return 0;
}
