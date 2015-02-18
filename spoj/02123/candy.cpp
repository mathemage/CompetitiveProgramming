/* ========================================

   * File Name : candy.cpp

   * Creation Date : 18-02-2015

   * Last Modified : Wed 18 Feb 2015 07:40:50 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/CANDY/

   * Duration : 11 min

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
  int n, pack;
  vector<int> x(10000);
  while(1) {
    pack = 0;
    cin >> n;
    if (n == -1) return 0;

    REP(i,n) {
      cin >> x[i];
      pack += x[i];
    }

    if (pack % n) {
      cout << -1 << endl;
      continue;
    }
    pack /= n;

    int res = 0;
    REP(i,n) {
      res += max(0, pack - x[i]);
    }
    cout << res << endl;
  };
  return 0;
}
