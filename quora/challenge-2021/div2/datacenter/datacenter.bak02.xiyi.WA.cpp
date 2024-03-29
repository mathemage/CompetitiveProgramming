 
/* ========================================
   * File Name : datacenter.cpp
   * Creation Date : 07-02-2021
   * Last Modified : Ne 7. února 2021, 05:25:58
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * - 32m 30s
   * - 44m 20s
   *
   * Total/ETA : 35m
   * Status :
   * - 9/100 (brute force)
   * - 0/100 (xi == yi)
   *
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
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

// direction vectors - 4 directions
const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
// direction vectors - 8 directions
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};


void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  int max_gap = 0;
  REP(i,n) {
    cin >> x[i] >> y[i];
    MAXUPDATE(max_gap, abs(x[i]-y[i]));
  }

  int result = 0LL;
  long long dist;

  if (max_gap == 0) {
    vector<pair<int, int>> pos_idx(n);
    REP(i,n) {
      pos_idx.PB( MP(x[i], i) );
    }
    sort(ALL(pos_idx));

    long long min_dist = LLONG_MAX;
    for (auto & mid_i: {n/2-2, n/2-1, n/2, n/2+1, n/2+2}) {
      pair<int, int> mid_pos_idx = pos_idx[mid_i];
      int i = mid_pos_idx.S;

      dist = 0LL;
      REP(j,n) {
        dist += abs(x[i]-x[j]);
      }

      if (dist < min_dist) {
        min_dist = dist;
        result = i+1;
      }
    }
  } else {  // brute force
    vector<long long> D(n,0);
    REP(i,n) REP(j,n) {
      dist = max( abs(x[i]-x[j]), abs(y[i]-y[j]) );
      D[i] += dist;
      D[j] += dist;
    }
    long long min_dist = *min_element(ALL(D));
    REP(i,n) {
      if (D[i] == min_dist) {
        result = i+1;
        break;
      }
    }
  }

  cout << result << endl;
}

int main() {
  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
