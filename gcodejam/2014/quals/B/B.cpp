/* ========================================

   * File Name : B.cpp

   * Creation Date : 10-04-2015

   * Last Modified : Fri 10 Apr 2015 11:06:50 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

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
  double c,f,x;
  cin >> t;
  REP(i,t) {
    cin >> c >> f >> x;
    double r = 2;
    double mi = x / r;
    double total = 0;

    while (total < mi) {
      mi = min(mi, total + x / r);
      total += c / r;
      r += f;
    }
    printf("Case #%d: %.7f\n",i+1,mi);
  }
  return 0;
}
