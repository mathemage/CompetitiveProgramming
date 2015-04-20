/* ========================================

   * File Name : B.cpp

   * Creation Date : 02-02-2015

   * Last Modified : Mon 02 Feb 2015 07:34:11 PM CET

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
  int n;
  cin >> n;
  vector<long long> l(n);
  vector<int> c(n);
  REP(i,n) { cin >> l[i]; }
  REP(i,n) { cin >> c[i]; }

  const long long sz = accumulate(ALL(c),0) + 2;
  vector<set<long long > > costs(sz);
  long long g;
  int m = sz+1;
  REP(i,n) {
    FOR(k,sz-c[i]+1,0) {
      if (costs[k].empty()) continue;
      for (auto & x : costs[k]) {
        if ( (g = __gcd(x, l[i])) < x ) {
          if (g == 1) m = min(m, k+c[i]);
          else costs[k+c[i]].insert(g);
        }
      }
      costs[c[i]].insert(c[i]);
      if (c[i] == 1) m = min(m, c[i]);
    }
  }
  cout << (m == sz+1 ? -1 : m) << endl;
  return 0;
}
