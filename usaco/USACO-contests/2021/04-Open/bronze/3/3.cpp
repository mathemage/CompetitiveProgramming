/* ========================================
   * File Name : 3.cpp
   * Creation Date : 02-04-2021
   * Last Modified : Fri 02 Apr 2021 06:20:39 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem&cpid=1121
   * Points/Time :
   *  29m
   * +51m ~ 1h20m
   *
   * Total/ETA : 60m
   * Status :
   * AC !!!!!!!!!!!!!!!!!!!!!
   *
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


void solve() {
  int N,M;
  cin >> N >> M;

  vector<string> grid(N); 
  for (auto & line: grid) { cin >> line; }
  MSG(grid); LINESEP1;

  map<int, vector<pair<int, int>> > q;
  REP(r,N) {
    REP(c,M) {
      if (grid[r][c]=='G') {
        int nNeigh=0;
        for (auto & drc: DXY4) {
          int rr=r+drc.F, cc=c+drc.S;
          if (bounded(rr,N) && bounded(cc,M) && grid[rr][cc]=='C') { nNeigh++; }
        }

        if (nNeigh<=1) { grid[r][c]='.'; }
        else { q[nNeigh].PB(MP(r,c)); }
      }
    }
  }
  MSG(grid);
  MSG(q.size()); MSG_VEC_PAIRS(q[2]); MSG_VEC_PAIRS(q[3]); MSG_VEC_PAIRS(q[4]);
  LINESEP1;

  set<pair<int, int>> used;
  long long result = 0LL;
  for (auto & nNeigh: {2,3,4}) {
    MSG_VEC_PAIRS(q[nNeigh]);
    for (auto & pos: q[nNeigh]) {
      int r=pos.F, c=pos.S;

      bool ok=false;
      FOR(i1,0,3) {
        FOR(i2,i1+1,3) {
          int rr1=r+DXY4[i1].F, cc1=c+DXY4[i1].S;
          int rr2=r+DXY4[i2].F, cc2=c+DXY4[i2].S;

          if (bounded(rr1,N) && bounded(cc1,M) && grid[rr1][cc1]=='C'
              && bounded(rr2,N) && bounded(cc2,M) && grid[rr2][cc2]=='C') {
            int nPos1=rr1*M+cc1, nPos2=rr2*M+cc2;
            if (nPos1>nPos2) { swap(nPos1,nPos2); }

            if ( !CONTAINS(used, MP(nPos1,nPos2)) ) {
              used.insert( MP(nPos1,nPos2) );
              result++;
              ok=true;

              grid[r][c]='#';
              MSG(r) MSG(c);
              MSG(result); MSG(grid); LINESEP1;

              break;
            }
          }
        }
        if (ok) {
          break;
        }
      }
    }
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}
