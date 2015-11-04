 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 04-11-2015

   * Last Modified : Wed 04 Nov 2015 06:35:49 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/476/A

   * Points Gained (in case of online contest) : WA - AC

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
  int n,m;
  cin >> n >> m;
  int a = (n%2 == 0) ? 0 : 1;
  while (a <= n) {
    if ( (a + (n-a)/2) % m == 0) {
      cout << a + (n-a)/2 << endl;
      return 0;
    }
    a += 2;
  }
  cout << -1 << endl;
  return 0;
}
