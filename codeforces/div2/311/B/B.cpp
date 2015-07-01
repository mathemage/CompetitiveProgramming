 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 30-06-2015

   * Last Modified : Wed 01 Jul 2015 02:51:01 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/557/problem/B

   * Points Gained (in case of online contest) : 0 / 1000, WA

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
  double w;
  cin >> n >> w;
  vector<int> a(2 * n);
  REP(i,2 * n) {
    cin >> a[i];
  }

  sort(ALL(a));
  double amount = min((double) a[0], 0.5 * a[n]);
  cout << min(3 * n * amount, w) << endl;
  return 0;
}
