 
/* ========================================
   * File Name : C_v2.cpp
   * Creation Date : 07-01-2021
   * Last Modified : Pá 8. ledna 2021, 00:02:13
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1471/problem/C
   * Points :
   * Total : 1000
   * Status : AC
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> k(n);
  for (auto & ki : k) {
    cin >> ki;
  }
  vector<int> c(m);
  for (auto & ci : c) {
    cin >> ci;
  }

  sort(REVALL(k));

  long long min_cost = 0LL;
  int i_c = 1;
  for (auto & ki : k) {
    if (i_c < ki) {
      min_cost += c[i_c-1];
      i_c++;
    } else {
      min_cost += c[ki-1];
    }
  }

  cout << min_cost << endl;
}

int main() {
  int cases;
  cin >> cases;
//  cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
