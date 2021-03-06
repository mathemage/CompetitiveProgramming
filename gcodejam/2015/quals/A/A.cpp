/* ========================================

   * File Name : A.cpp

   * Creation Date : 11-04-2015

   * Last Modified : Sat 11 Apr 2015 04:15:40 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://code.google.com/codejam/contest/6224486/dashboard#s=p0

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
  int t;
  cin >> t;
  REP(i,t) {
    int f = 0, smax, total = 0;
    cin >> smax;
    string s;
    cin >> s;

    REP(k,smax+1) {
      int n = s[k]-'0';
      if (n) {
        f += max(k-total, 0);
        total += max(k-total, 0);
        total += n;
      }
    }
    printf("Case #%d: %d\n", i+1, f);
  }
  return 0;
}
