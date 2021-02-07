 
/* ========================================
   * File Name : treasure.cpp
   * Creation Date : 07-02-2021
   * Last Modified : Ne 7. února 2021, 03:58:16
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * - 44m 0s
   *
   * Total/ETA : 65m
   * Status :
   * - 100/100 (flash!!!)
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
const long long MOD = 1000000007;

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
  vector<vector<int>> max_treasures(n, vector<int>(n,0));
  char c;
  REP(row,n) REP(col,n) {
    cin >> c;
    if (c=='1') {
      max_treasures[row][col] = 1;
    }
  }

  vector<vector<long long>> max_paths(n, vector<long long>(n,0LL));
  max_paths[0][0] = 1LL;
  int prev_row, prev_col, new_max;
  REP(row,n) REP(col,n) {
    if (row==0 && col==0) {
      continue;
    }

    prev_row = row ? max_treasures[row-1][col] : 0;
    prev_col = col ? max_treasures[row][col-1] : 0;
    new_max = max(prev_row, prev_col);
    max_treasures[row][col] += new_max;

    if (row && prev_row==new_max) {
      max_paths[row][col] += max_paths[row-1][col] % MOD;
      max_paths[row][col] %= MOD;
    }
    if (col && prev_col==new_max) {
      max_paths[row][col] += max_paths[row][col-1] % MOD;
      max_paths[row][col] %= MOD;
    }
  }

  cout << max_treasures[n-1][n-1] << " " << max_paths[n-1][n-1] << endl;
}

int main() {
  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
