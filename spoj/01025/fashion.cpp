/* ========================================

   * File Name : fashion.cpp

   * Creation Date : 19-02-2015

   * Last Modified : Thu 19 Feb 2015 05:45:55 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/FASHION/

   * Duration : 6 min

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
  int t,n;
  cin >> t;
  REP(i,t) {
    cin >> n;
    vector<int> m(n);
    REP(i,n) cin >> m[i];
    vector<int> w(n);
    REP(i,n) cin >> w[i];

    sort(ALL(m));
    sort(ALL(w));
    int res = 0;
    REP(i,n) res += m[i] * w[i];
    cout << res << endl;
  }
  return 0;
}
