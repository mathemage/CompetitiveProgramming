 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 17-11-2020

   * Last Modified : Út 17. listopadu 2020, 00:58:58

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/34/B

   * Points Gained (in case of online contest) : AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;

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

  vector<int> a(n);
  REP(i,n) {
    cin >> a[i];
  }
  sort(ALL(a));

  int ans = 0;
  REP(i,m) {
    ans -= min(0, a[i]);
  }
  cout << ans << endl;
  return 0;
}
