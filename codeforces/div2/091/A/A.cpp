/* ========================================

   * File Name : A.cpp

   * Creation Date : 24-03-2015

   * Last Modified : Tue 24 Mar 2015 10:34:24 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/122/A

   * Duration :

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
  int n;
  cin >> n;
  FOR(i,1,n+1) {
    if (n % i == 0) {
      string s = to_string(i);
      for (auto & x : s) {
        if (x != '4' && x != '7') {
          s = "";
          break;
        }
      }
      if (s.size()) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
