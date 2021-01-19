 
/* ========================================
   * File Name : archery.cpp
   * Creation Date : 19-01-2021
   * Last Modified : Út 19. ledna 2021, 00:59:36
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/archery
   * Points/Time : 46m 20s -
   * Total :
   * Status : AC (https://www.hackerrank.com/contests/quora-haqathon/challenges/archery/submissions/code/1329710608)
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
  vector<long long> R_squared(N);
  for (auto & Ri : R_squared) {
    cin >> Ri;
    Ri *= Ri;
  }
  int M, x1, y1, x2, y2;
  cin >> M;
  vector<pair<long long, long long>> arr_dist_squared(M);
  for (auto & a : arr_dist_squared) {
    cin >> x1 >> y1 >> x2 >> y2;
    long long d1 = pow(x1,2) + pow(y1,2);
    long long d2 = pow(x2,2) + pow(y2,2);
    a = MP(min(d1,d2), max(d1,d2));
  }

  sort(ALL(R_squared));
  sort(ALL(arr_dist_squared));
//   for (auto & r : R_squared) {
//     cerr << r << "\t";
//   }
//   cerr << endl;
//   for (auto & a : arr_dist_squared) {
//     cerr << a.F << ", " << a.S << "\t";
//   }
//   cerr << endl;

  long long result = 0LL;

  auto i_R = R_squared.begin();
  for (auto & a : arr_dist_squared) {
//     MSG(a.F); MSG(a.S);
    long long inner_dist = a.F;
    while (*i_R < inner_dist) {
      i_R++;
    }

    long long outer_dist = a.S;
    auto o_R = lower_bound(i_R, R_squared.end(), outer_dist);

//     MSG(*i_R); MSG(*o_R); MSG(distance(i_R, o_R)); cerr << endl;
    result += distance(i_R, o_R);
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
