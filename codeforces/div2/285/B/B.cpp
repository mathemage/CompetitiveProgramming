/* ========================================

   ID: mathema6
   TASK: B
   LANG: C++11
   (...for USACO solutions)

   * File Name : B.cpp

   * Creation Date : 12-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/501/problem/B

   * Points Gained (in case of online contest) : 466 / 500

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

int n;
string old, ne;
unordered_map<string, string> f, b;
vector<string> ch;
int main() {
  cin >> n;
  REP(i,n) {
    cin >> old >> ne;
    if (b.find(old) == b.end()) {
      ch.push_back(old);
      f[old] = ne;
      b[ne] = old;
    } else {
      f[b[old]] = ne;
      b[ne] = b[old];
    }
  }

  cout << ch.size() << endl;
  for (string o : ch) {
    cout << o << " " << f[o] << endl;
  }
  return 0;
}
