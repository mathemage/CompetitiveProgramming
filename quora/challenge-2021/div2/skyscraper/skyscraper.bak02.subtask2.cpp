 
/* ========================================
   * File Name : skyscraper.cpp
   * Creation Date : 07-02-2021
   * Last Modified : Ne 7. února 2021, 06:02:43
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * - 15m 10s
   * - ~20m
   * - ~30m
   *
   * Total/ETA :
   * Status :
   * - 0/100
   * - 11/100
   * - unsubmitted (no idea)
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

int num_visible_skyscrapers(int i, const vector<int> & h, int n, const vector<int> & h_vals) {
//   // brute force
//   int result = 1;
//   for (auto & di: {-1,1}) {
//     int j=i+di;
//     while (1<=j && j<=n && h[j] <= h[i]) {
//       result++;
//       j+=di;
//     }
//   }
//   return result;

  // no setting
  result = n;
  for (auto & height_i: h_vals) {
    if (h[i] != height_i) {
      result--;
    }
  }
}

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> h(n+5);
  vector<pair<int, int>> h_vals;
  FO(i,1,n) {
    cin >> h[i];
    h_vals.PB(MP(h[i],i));
  }
  sort(REVALL(h_vals));

  int query, i, j, x;
  REP(qi,q) {
    cin >> query;
    switch (query) {
      case 1:
        cin >> i;
        cout << num_visible_skyscrapers(i, h, n, h_vals) << endl;
        break;

      case 2:
        cin >> i >> x;
        h[i] = x;
        break;

      case 3:
        cin >> i >> j >> x;
        FO(k,i,j) {
          h[k] = x;
        }
        break;
    }
  }
}

int main() {
  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
