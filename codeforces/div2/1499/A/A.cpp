/* ========================================
   * File Name : A.cpp
   * Creation Date : 18-03-2021
   * Last Modified : Thu 18 Mar 2021 05:24:35 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1499/problem/A
   * Points/Time :
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

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC(v) print_vector((v), (#v));
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2
#endif

template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

template<typename T1, typename T2>
void print_vector_pairs(const vector<pair<T1, T2>> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  cerr << endl;
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
  int n,k1,k2;
  cin >> n >> k1 >> k2;
  int w,b;
  cin >> w >> b;

  int cw = min(k1,k2);
  int bicol = max(k1,k2)-cw;
  int cb = n-cw-bicol;
  cw+=bicol/2;
  cb+=bicol/2;
  bool result = w<=cw && b<=cb;
  cout << (result?"YES":"NO") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}
