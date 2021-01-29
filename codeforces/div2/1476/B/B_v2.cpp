 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 29-01-2021
   * Last Modified : Pá 29. ledna 2021, 17:35:17
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1476/problem/B
   * Points/Time :
   * Total :
   * Status : unsubmitted
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
  double k;
  cin >> n >> k;

  vector<int> p(n);
  REP(i,n) {
    cin >> p[i];
  }

  long long d0 = 0LL;
  long double denom = (1.0 + k/100.0);
  FOR(i,1,n) {
    MSG(i); MSG(p[i]); MSG(denom); MSG(ceil(p[i]/denom));
    MAXUPDATE(d0, (long long)(ceil(p[i]/denom))-p[0]);
    denom *= (2.0 + k/100.0);
  }

  cout << d0 << endl;
  cerr << endl << endl;
}

int main() {
  int cases;
  cin >> cases;
//   cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
