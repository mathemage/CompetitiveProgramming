 
/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : C.cpp
   * Creation Date : 07-04-2021
   * Last Modified : Čt 8. dubna 2021, 19:48:18
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1355
   * Points/Time :
   *  21m10s
   * +17m    = 38m10s
   * +41m40s
   *
   * Total/ETA :
   *   45m (TS1)
   * 1h45m (TS2)
   *
   * Status :
   * S AC TLE (i.e. passed TS1)
   *
   ==========================================*/

#define PROBLEMNAME "TASK_PLACEHOLDER_FOR_VIM"

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

using ll = long long;
using ul = unsigned long long;
using llll = pair<ll, ll>;
using ulul = pair<ul, ul>;

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
//   #define MSG_VEC_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
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
  for (const auto & s: vec) os << s << endl;
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
inline ostream& operator<<(ostream& os, const vector<vector<vector<T>>> & vec) { 
  for (const auto & row: vec) {
    for (const auto & col: row) {
      os << "[ " << col << "]   ";
    }
    os << endl;
  }
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

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const int CLEAN = -1;

const long long MOD = 1000000007;
const double EPS = 1e-8;

const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {-1,0}, {0,1}, {1,0}, {0,-1} };
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

const int ELIMINATED = 0;
const int UNDEF = -INF;

void solve() {
  int nRows,nCols;
  cin >> nRows >> nCols;
  MSG(nRows); MSG(nCols);

  ll competition = 0LL;
  ll round = 0LL;
  const int U=0, R=1, D=2, L=3; 
  const vector<int> dues{U,R,D,L};
  MSG(dues);
  MSG(U); MSG(R); MSG(D); MSG(L);
  int x,y;

  vector<vector<int>> S(nRows, vector<int>(nCols));
  vector<vector<vector<int>>> neigh(4, vector<vector<int>>(nRows, vector<int>(nCols, UNDEF)));
  REP(i,nRows) {
    REP(j,nCols) {
      cin >> S[i][j];
      round += S[i][j];

      for (auto & due: dues) {
        x=i+DXY4[due].F, y=j+DXY4[due].S;
        if (bounded(x,nRows) && bounded(y,nCols)) { neigh[due][i][j]=1; }
      }
    }
  }
  competition+=round;
  MSG_VEC_VEC(S);
  MSG(round); MSG(competition);
  MSG_VEC_VEC(neigh[U]); MSG_VEC_VEC(neigh[R]); MSG_VEC_VEC(neigh[D]); MSG_VEC_VEC(neigh[L]);

  queue<pair<int, int>> qDel;

  int nSum,nCnt;
  pair<int, int> at;
  do {
    REP(i,nRows) {
      REP(j,nCols) {
        if (S[i][j]!=ELIMINATED) {
          nSum=nCnt=0;
          for (auto & dxy: DXY4) {
            x=i+dxy.F, y=j+dxy.S;
            // TODO use neigh instead
            while (bounded(x,nRows) && bounded(y,nCols) && S[x][y]==ELIMINATED) {
              x+=dxy.F, y+=dxy.S;
            }
            if (bounded(x,nRows) && bounded(y,nCols) && S[x][y]!=ELIMINATED) {
              nSum+=S[x][y];
              nCnt++;
            }
          }

          if (S[i][j]*nCnt < nSum) {
            qDel.push(MP(i,j));
          }
        }
      }
    }

    MSG(qDel.size());
    if (qDel.empty()) { break; }
    while (!qDel.empty()) {   // process qDel
      at = qDel.front();
      x=at.F, y=at.S;
      qDel.pop();

      round -= S[x][y];
      S[x][y]=ELIMINATED;
    }

    competition+=round;
    MSG_VEC_VEC(S); MSG(round); MSG(competition);
  } while (true);

  cout << competition << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  cin >> cases;
  REP(i,cases) {
    cout << "Case #" << i+1 << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
