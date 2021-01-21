 
/* ========================================
   * File Name : schedule.cpp
   * Creation Date : 20-01-2021
   * Last Modified : Čt 21. ledna 2021, 21:05:17
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/schedule
   * Points/Time : 46 m - 1h 2m 30s - 1h 5m 30s
   * Total :
   * Status : WA (almost ALL) - WA (#0) - AC (:-) !!!)
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
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  int N;
  cin >> N;
  vector<double> T(N);
  vector<double> P(N);
  vector<pair<double, int>> fail_rates(N);
  REP(i,N) {
    cin >> T[i] >> P[i];
    fail_rates[i] = MP((1.0-P[i]) /T[i], i);
  }

  sort(ALL(fail_rates));
//   REP(i,N) {
//     cerr << fail_rates[i].F << "\t" << fail_rates[i].S << endl;
//   }

  double result = 0.0;
  for (auto & fr : fail_rates) {
    int i = fr.S;
    result = T[i] + P[i] * result;
  }
  cout.precision(16);
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
