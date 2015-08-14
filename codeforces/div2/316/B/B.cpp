 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 13-08-2015

   * Last Modified : Fri 14 Aug 2015 01:33:42 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/570/problem/B

   * Points Gained (in case of online contest) : 828 / 1000

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
  int n, m;
  cin >> n >> m;
  if (m == n) {
    cout << max(1,n-1) << endl;
    return 0;
  }

  if (m == 1) {
    cout << 2 << endl;
    return 0;
  }

  int a1 = m-1;
  int a2 = m+1;
  if (a1 < n - a2 + 1) {
    cout << a2 << endl;
  } else {
    cout << a1 << endl;
  }
  return 0;
}
