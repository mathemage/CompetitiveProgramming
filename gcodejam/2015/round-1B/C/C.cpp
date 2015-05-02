 
/* ========================================

   * File Name : C.cpp

   * Creation Date : 02-05-2015

   * Last Modified : Sat 02 May 2015 08:31:58 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://code.google.com/codejam/contest/8224486/dashboard#s=p2

   * Points Gained (in case of online contest) : not submitted (TODO)

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
  int t,n,res;
  cin >> t;
  REP(i,t) {
    cin >> n;
    vector<int> d(n);
    vector<int> h(n);
    vector<int> m(n);
    REP(j,n) {
      cin >> d[i];
      cin >> h[i];
      cin >> m[i];
    }

    if (n == 1) {
      res = 0;
    } else { 
      if (d[0] >= d[1]) {
        swap(d[0], d[1]);
        swap(h[0], h[1]);
        swap(m[0], m[1]);
      }

      if (m[0] == m[1]) {
        res = 0;
      } else if (m[0] > m[1]) {
        double x = d[1] + m[0] * (d[1]-d[0]+360) / (m[1] - m[0]);
        if (0 < x && x < 360) {
          res = 1;
        } else {
          res = 0;
        }
      } else {
        double x = d[0] + m[1] * (d[0]-d[1]+360) / (m[0] - m[1]);
        if (0 < x && x < 360) {
          res = 1;
        } else {
          res = 0;
        }
      }
    }
    printf("Case #%d: %d\n", i+1, res);
  }
  return 0;
}
