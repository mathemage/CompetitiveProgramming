 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 02-03-2021
   * Last Modified : Út 2. března 2021, 16:34:56
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1494/problem/B
   * Points/Time : 49m 35s
   * Total/ETA :
   * Status : AC
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MTP make_tuple
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((int) (x).size())

#define MSG(a) cerr << "> " << #a << ": " << (a) << endl;
template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

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
  int n,u,r,d,l;
  cin >> n >> u >> r >> d >> l;

  bool result = false;
  vector<int> options={0,1};
  for (auto & ur: options) {
    for (auto & dr: options) {
      for (auto & dl: options) {
        for (auto & ul: options) {
          result = ul+ur<=u && dl+dr<=d && ur+dr<=r && dl+ul<=l;
          result &= u-(ul+ur)<=n-2 && r-(dr+ur)<=n-2 && d-(dl+dr)<=n-2 && l-(dl+ul)<=n-2;
          if (result) {
//             MSG(ul) MSG(ur) MSG(dr) MSG(dl)
            cout << (result?"YES":"NO") << endl;
            return;
          }
        }
      }
    }
  }

  cout << (result?"YES":"NO") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}
