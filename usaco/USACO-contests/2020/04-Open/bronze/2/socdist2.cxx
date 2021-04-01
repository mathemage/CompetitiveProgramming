/* ========================================

   ID: mathema6
   TASK: socdist2
   LANG: C++14

   * File Name : socdist2.cxx
   * Creation Date : 01-04-2021
   * Last Modified : Thu 01 Apr 2021 03:06:01 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem2&cpid=1036
   * Points/Time :
   *   4m50s
   * +14m    = 18m50s
   * +10m
   * + 7m30s = 36m20s
   *
   * Total/ETA : 35m
   * Status :
   * 3/10 WA
   * 10/10 AC -> passed !!
   *
   ==========================================*/

#define PROBLEMNAME "socdist2"

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
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2
#endif

ostream& operator<<(ostream& os, const vector<string> & vec) {
  os << endl;
  for (const auto & s: vec) cerr << s << endl;
  return os;
}

template<typename T> 
ostream& operator<<(ostream& os, const vector<T> & vec) { 
  for (const auto & x: vec) os << x << " ";
  return os; 
} 

template<typename T> 
ostream& operator<<(ostream& os, const vector<vector<T>> & vec) { 
  for (const auto & v: vec) os << v << endl;
  return os; 
} 

template<typename T> 
ostream& operator<<(ostream& os, const set<T>& vec) { 
  os << "{ | ";
  for (const auto & x: vec) os << x << "| ";
  os << "}";
  return os; 
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
const double EPS = 1e-8;

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


#ifndef MATHEMAGE_LOCAL
void setIO(string filename) {    // the argument is the filename without the extension
	freopen((filename+".in").c_str(), "r", stdin);
	freopen((filename+".out").c_str(), "w", stdout);
  MSG(filename);
}
#endif

void solve() {
  int N;
  cin >> N;

  int R=1e7;

  vector<pair<int, int>> xs(1+N);
  xs[0] = MP(-R,UNDEF);
  FOR(i,1,N) {
    cin >> xs[i].F >> xs[i].S;
  }

  sort(ALL(xs), [](auto & a, auto & b) { return a.F < b.F; } );
  xs[0].S=xs[1].S;
  MSG_VEC_PAIRS(xs);

  FOR(i,1,N) {
    if (xs[i].S ^ xs[i-1].S) {
      MSG(R);
      MINUPDATE(R, xs[i].F-xs[i-1].F);
      MSG(i); MSG(R); LINESEP1;
    }
  }

  long long result = 0LL;
  FOR(i,1,N) {
    result += xs[i].S && (xs[i].F-xs[i-1].F)>=R;
    
    MSG(i); MSG(xs[i].S && (xs[i].F-xs[i-1].F)>=R); MSG(result); LINESEP1;
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifndef MATHEMAGE_LOCAL
  setIO(PROBLEMNAME);
#endif

  int cases = 1;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}
