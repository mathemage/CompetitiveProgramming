 
/* ========================================
   * File Name : A_v2.cpp
   * Creation Date : 13-01-2021
   * Last Modified : St 13. ledna 2021, 00:16:39
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/1004/A
   * Points/Time : 6m 30s
   * Total : 500
   * Status : AC
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  int n,d;
  cin >> n >> d;
  vector<int> x(n);
  for (auto & xi : x) {
    cin >> xi;
  }

  long long result = 2LL;
  REP(i,n-1) {
    int dist = x[i+1]-x[i]-2*d;
    result += (dist >= 0) + (dist > 0);
    MSG(x[i+1]); MSG(x[i]); MSG(dist); MSG(result); cerr << endl;
  }
  cout << result << endl;
}

int main() {
  int cases;
//   cin >> cases;
  cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
