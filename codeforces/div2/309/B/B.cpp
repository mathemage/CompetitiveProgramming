 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 24-06-2015

   * Last Modified : Thu 25 Jun 2015 03:51:08 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/554/problem/B

   * Points Gained (in case of online contest) : 382 / 500, AC

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
  int n;
  cin >> n;
  vector<string> a(n);
  REP(i,n) {
    cin >> a[i];
  }

  int res = 0;
  REP(r,n) {
    vector<string> a2 = a;

    // clean row
    REP(c,n) {
      if (a[r][c] == '0') {
        // sweep
        REP(ri,n) {
          a2[ri][c] = ('1' == a[ri][c]) ? '0' : '1';
        }
      }
    }

    int count = 0;
    REP(i,n) {
      bool clean = true;
      REP(j,n) {
        if (a2[i][j] == '0') {
          clean = false;
          break;
        }
      }

      if (clean) {
        count++;
      }
    }

    res = max(res, count);
  }
  cout << res << endl;
  return 0;
}
