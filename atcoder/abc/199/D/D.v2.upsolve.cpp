/* ========================================

   ID: mathema6
   TASK: D
   LANG: C++14

   * File Name : D.cpp
   * Creation Date : 24-04-2021
   * Last Modified : Sat 24 Apr 2021 11:56:06 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://atcoder.jp/contests/abc199/tasks/abc199_d
   * Points/Time :
   * 29m :-/
   * 
   * Total/ETA : 400
   * 13m [upsolve]
   *
   * Status :
   * [after contest] - too late :-/
   * WAs & TLEs
   * [upsolve]
   * WAs & TLEs
   *
   ==========================================*/

#define PROBLEMNAME "D"

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

template<typename T, class Compare>
ostream& operator<<(ostream& os, const set<T, Compare>& vec) {
  for (const auto & x: vec) os << x << " ";
  os << endl;
  return os;
} 

template<typename T, class Compare>
ostream& operator<<(ostream& os, const multiset<T, Compare>& vec) {
  for (const auto & x: vec) os << x << " ";
  os << endl;
  return os;
}

template<typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& vec) { 
  for (const auto & x: vec) os << x.F << ":" << x.S << " | ";
  return os; 
} 

template<typename T1, typename T2>
void print_vector_pairs(const vector<pair<T1, T2>> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  cerr << endl;
}

template<typename T>
istream& operator>>(istream& is, vector<T> & vec) {
  for (auto & x: vec) is >> x;
  return is;
}

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) { return min(l,u)<=x && x<max(l,u); }

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = {-1, 0, 1,  0};
const vector<int> DY4 = { 0, 1, 0, -1};
const vector<pair<int,int>> DXY4 = { {-1,0}, {0,1}, {1,0}, {0,-1} };
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

ll N,M;
map<ll, vector<long long>> adj;
vector<bool> vis;

// set<map<ll,char>> solutions;
string sol;
set<string> solutions;

ll compSize;
ll df(ll at) {
  vis[at]=true;         // bug #2 was here
//   LINESEP1; MSG(at); MSG(adj[at]); MSG(vis);

//   ll result=0;         // bug #1 was here!
  ll result=1;
  for (auto & neigh: adj[at]) {
    if (!vis[neigh]) {
//       vis[neigh]=true;
      result+=df(neigh);
    }
//     LINESEP1; MSG(at); MSG(neigh); MSG(result);
  }
  return result;
}

string colors="RGB";

ll nColored;
void dfs(ll at) {
  vis[at]=true;
//   nColored++;             // bug #4

  for (auto & neigh: adj[at]) {
    if (sol[neigh]=='_') {
      for (auto & color: colors) {
        if (color!=sol[at]) {
          sol[neigh]=color;
          nColored++;             // bug #4

          dfs(neigh);

          sol[neigh]='_';
          nColored--;             // bug #4
        }
      }
    } else if (sol[neigh]==sol[at]) {
      return;
    }
  }

  if (nColored==compSize) {
    solutions.insert(sol);
    MSG(nColored); MSG(sol); LINESEP1;
    return;
  }
}

void solve() {
  cin >> N >> M;

  vector<ll> A(M); vector<ll> B(M);
  REP(i,M) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    adj[A[i]].PB(B[i]);
    adj[B[i]].PB(A[i]);
  }
  MSG(A); MSG(B);
  MSG(adj);

  ll result = 0LL;

  vis.assign(N, false);
  map<ll,ll> compSizes;
  REP(at,N) {
    if (!vis[at]) {         // -> inefficiency
      compSizes[at]=df(at);
//       MSG(at); MSG(compSizes[at]);
    }
  }
  MSG(compSizes);

  vis.assign(N, false);
  REP(at,N) {
    if (vis[at]) {
      continue;
    }
//     compSize=df(at);     // typo -> inefficiency
    compSize=compSizes[at];
    sol.assign(N,'_');

    sol[at]='R';
    nColored=1;      // bug #3
    vis[at]=true;

    solutions.clear();
//     solutions.insert(sol);  // bug #5 <- stupid mistake!!!
    dfs(at);
    MSG(solutions);

    ll ways=3*solutions.size();
    if (result==0) {
      result=ways;
    } else {
      result*=ways;
    }
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifndef MATHEMAGE_LOCAL
//   setIO(PROBLEMNAME);
#endif

  int cases = 1;
  FOR(tt,1,cases) {
//     cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
