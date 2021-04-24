/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : A.cpp
   * Creation Date : 20-04-2021
   * Last Modified : Sat 24 Apr 2021 09:19:51 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62
   * Points/Time :
   *        =   58m
   * +1h13m = 2h11m :-(
   *     1m = 2h12m
   * +  27m = 2h39m
   *
   * Total/ETA :
   * 60m (BFS <- TS1 TS2)
   *
   * Status :
   * S WA - - :-(
   * S WA - - :-( :-(
   * [editorial]
   * S WA - - :-( :-/
   * -> give up BFS :-/
   *
   ==========================================*/

#include <queue>
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
//   for (const auto & s: vec) os << s << endl;
  for (auto it = vec.rbegin(); it != vec.rend(); ++it) os << *it << endl;
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
//   for (auto it = vec.rbegin(); it != vec.rend(); ++it) os << *it << endl; // TODO uncomment
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

template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& vec) {
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
istream& operator>>(istream& is, vector<T> & vec) {
  for (auto & x: vec) is >> x;
  return is;
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

const vector<int> DX4 = {-1, 0, 1,  0};
const vector<int> DY4 = { 0, 1, 0, -1};
const vector<pair<int,int>> DXY4 = { {-1,0}, {0,1}, {1,0}, {0,-1} };
// const string dues="NESW";
const string dues="WNES";

// const vector<int> DX4 = {-1, 0, 1,  0};
// const vector<int> DY4 = { 0, 1, 0, -1};
// const vector<pair<int,int>> DXY4 = { {-1,0}, {0,1}, {1,0}, {0,-1} };
// const string dues="SENW";

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

#ifdef MATHEMAGE_DEBUG
  const int MAX_DIST=99;
#else
  const int MAX_DIST=1e9;
#endif

void solve() {
  int X,Y; cin >> X >> Y;

  int dim = abs(X)+abs(Y);
  if (dim > 1e4) {
    exit(1); // TODO
  }
//   dim *= 2;
  dim *= 8;
  dim++;

  vector<vector<int>> dist(dim, vector<int>(dim, MAX_DIST));
  vector<string> prevMove(dim, string(dim, '_'));

  queue<pair<int, int>> q;
  int origin=dim/2;
  int x=origin, y=origin;

  dist[y][x]=0;
  prevMove[y][x]='o';
  q.push({y,x});

  while (!q.empty()) {
    pair<int, int> yx=q.front();
    q.pop();

    y=yx.F, x=yx.S;
    if (y==origin+Y && x==origin+X) {
      break;
    }

    int jumpLen=1<<dist[y][x];
    REP(di,4) {
      int dy=jumpLen*DY4[di], dx=jumpLen*DX4[di];
      int yy=y+dy, xx=x+dx;
      if (bounded(yy,dim) && bounded(xx,dim) && dist[y][x]+1<dist[yy][xx]) {
        dist[yy][xx]=dist[y][x]+1;
        prevMove[yy][xx]=dues[di];
        q.push({yy,xx});
      }
    }
  }
  MSG_VEC_VEC(dist); // TODO
  MSG(prevMove); // TODO

  y=origin+Y, x=origin+X;
  if (dist[y][x]!=MAX_DIST) {
    string result;

    MSG(origin);
    while (y!=origin || x!=origin) {
      char due=prevMove[y][x];
      result+=due;
      MSG(due);

      prevMove[y][x]='0'+dist[y][x]; // for debugging
      MSG(prevMove);

      int jumpLen=1<<(dist[y][x]-1);
      int di=dues.find(due);
      int dy=jumpLen*DY4[di], dx=jumpLen*DX4[di];
      MSG(jumpLen); MSG(di);

      MSG(r);  MSG(c);
      MSG(dr); MSG(dc);
      MSG(r-dr); MSG(c-dc);
      assert(dist[y][x]==dist[y-dy][x-dx]+1);
      y-=dy, x-=dx;

      LINESEP1;
    }

    reverse(ALL(result));
    cout << result << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
