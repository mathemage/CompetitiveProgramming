/* ========================================

   * File Name : B.cpp

   * Creation Date : 14-02-2015

   * Last Modified : Sat 14 Feb 2015 07:58:07 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/514/problem/B

   * Points Gained (in case of online contest) : 718 / 1000

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
  int n, x0, y0;
  double x, y;
  cin >> n >> x0 >> y0;
  vector<double> angl;
  bool horiz = false;
  REP(i,n) {
    cin >> x >> y;
    x -= x0;
    y -= y0;
    if (y != 0) angl.emplace_back(x / y);
    else horiz = true;
    //ERR(i, x, y, horiz);
  }

  int res = 0;
  if (horiz) res++;

  if (angl.empty()) {
    cout << res << endl;
    return 0;
  }

  //ERR(res)
  sort(ALL(angl));

  double prec = 0.000000000000000000001;
  double cur = angl[0];
  FOR(j,1,n) {
    if (angl[j] - cur > prec) {
      res++;
      cur = angl[j];
    }
  }
  cout << res+1 << endl;
  return 0;
}
