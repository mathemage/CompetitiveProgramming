/* ========================================
   * File Name : B.cpp
   * Creation Date : 23-03-2021
   * Last Modified : Wed 24 Mar 2021 04:34:38 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da
   * Points/Time :
   *   4m10s
   * +36m30s = 40m40s
   * +14m30s
   *
   * Total/ETA :
   * Status :
   * TLE #3
   *
   ==========================================*/

#include <algorithm>
#include <bits/stdc++.h>
#include <sys/ucontext.h>

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
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
  #define MSG_VEC_STR(v) print_vector_string((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define MSG_VEC_VEC(v)
  #define MSG_VEC_STR(v)
  #define LINESEP1
  #define LINESEP2
#endif

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
void print_vector_string(const vector<T> & vec, const string & name) {
  cerr << "> " << name << ": " << endl;
  for (const auto & s: vec) cerr << s << endl;
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
const vector<pair<int,int>> DXY2 = { {0,1}, {1,0} };
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

int n;
string dfs(const vector<vector<bool>> & marked) {
  string result;
  vector<vector<bool>> vis(n, vector<bool>(n));
  stack<pair<int, int>> st;

  st.push(MP(0,0));
  vis[0][0] = true;

  while (!st.empty()) {
    pair<int, int> at=st.top();
    int r=at.F, c=at.S;
    st.pop();

    if (r==n-1 && c==n-1) {
      break;
    }

    for (auto & drc: DXY2) {
      int rr=r+drc.F, cc=c+drc.S;
      if (bounded(rr,n) && bounded(cc,n) && !vis[rr][cc]) {
        if (marked[r][c] && marked[rr][cc]) {
          continue;
        }

        st.push(MP(rr,cc));
        vis[rr][cc] = true;
      }
    }
  }

  while (!st.empty()) {

  }

  reverse(ALL(result));
  return result;
}

void solve() {
  cin >> n;
  string p;
  cin >> p;

  vector<vector<bool>> marked(n, vector<bool>(n));
  int rr=0,cc=0;
  marked[rr][cc] = true;
  for (auto & c: p) {
    if (c=='E') cc++;
    else if (c=='S') rr++;
    marked[rr][cc] = true;
  }
  MSG_VEC_VEC(marked);

  cout << dfs(marked) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  REP(i,cases) {
    cout << "Case #" << i+1 << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
