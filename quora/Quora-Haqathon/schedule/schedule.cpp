 
/* ========================================
   * File Name : schedule.cpp
   * Creation Date : 20-01-2021
   * Last Modified : St 20. ledna 2021, 15:52:56
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/schedule
   * Points/Time : 46 m + 
   * Total :
   * Status : WA (almost ALL)
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
  vector<pair<double, double>> PT(N);
  REP(i,N) {
    cin >> PT[i].S >> PT[i].F;
  }

  sort(ALL(PT));
//   REP(i,N) {
//     cerr << PT[i].F << "\t" << PT[i].S << endl;
//   }

  double sum_time = 0.0;
  double prod_prob = 1.0;
  for (auto & pt: PT) {
    prod_prob *= pt.F;
    sum_time += pt.S;
  }
  double result = prod_prob * sum_time;

  sum_time = 0.0;
  prod_prob = 1.0;
  for (auto & pt: PT) {
    sum_time += pt.S;
    result += (1 - pt.F) * prod_prob * sum_time;
    prod_prob *= pt.F;
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
