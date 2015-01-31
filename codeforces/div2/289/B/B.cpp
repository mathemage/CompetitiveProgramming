/* ========================================

   * File Name : B.cpp

   * Creation Date : 31-01-2015

   * Last Modified : Sat 31 Jan 2015 09:39:59 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/509/problem/B

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
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int x = *min_element(ALL(a));
  int y = *max_element(ALL(a));
  if (y-x > k) {
    cout << "NO";
  } else {
    cout << "YES\n";
    REP(i,n) {
      REP(j,x) cout << "1 ";
      FOR(j,x,a[i]) cout << j-x+1<< " ";
      cout << endl;
    }
  }
  return 0;
}
