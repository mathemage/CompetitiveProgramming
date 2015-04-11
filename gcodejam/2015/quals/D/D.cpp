/* ========================================

   * File Name : D.cpp

   * Creation Date : 11-04-2015

   * Last Modified : Sun 12 Apr 2015 12:48:43 AM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://code.google.com/codejam/contest/6224486/dashboard#s=p3

   * Points Gained (in case of online contest) :

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
  int t, x, r, c;
  cin >> t;
  REP(i,t) {
    cin >> x >> r >> c;
    
    if (r > c) {
      swap(r,c);
    }

    bool win = false;
    if ( (r * c) % x == 0 ) {
      switch (x) {
      case 1:
        win = true;
        break;
      case 2:
        win = true;
        break;
      case 3:
        if (r > 1) {
          win = true;
        }
        break;
      case 4:
        if (c == 4 && r > 2) {
          win = true;
        }
        break;
      }
    }
    printf("Case #%d: %s\n", i+1, (win ? "GABRIEL" : "RICHARD"));
  }
  return 0;
}
