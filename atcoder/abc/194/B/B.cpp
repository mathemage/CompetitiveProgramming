 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 12-03-2021
   * Last Modified : Pá 12. března 2021, 23:56:33
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://atcoder.jp/contests/abc194/tasks/abc194_b
   * Points/Time : 16m 30s
   * Total/ETA : 200 (7m)
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

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
#else
  #define MSG(a)
#endif

template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
#ifdef MATHEMAGE_DEBUG
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
#endif
}

template<typename T>
void print_vector_pairs(const vector<pair<T, T>> & vec, const string & name) {
#ifdef MATHEMAGE_DEBUG
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  cerr << endl;
#endif
}

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
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

  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(n);
  int result = INF;
  REP(i,n) {
    cin >> a[i].F >> b[i].F;
    a[i].S = b[i].S = i+1;
    MINUPDATE(result, a[i].F + b[i].F);
  }

  sort(ALL(a));
  sort(ALL(b));
  if (a[0].S != b[0].S) {
    MINUPDATE(result, max(a[0].F, b[0].F));
  } else {
    MINUPDATE(result, max(a[1].F, b[0].F));
    MINUPDATE(result, max(a[0].F, b[1].F));
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
