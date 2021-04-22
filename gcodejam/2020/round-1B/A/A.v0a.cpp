/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : A.cpp
   * Creation Date : 20-04-2021
   * Last Modified : Tue 20 Apr 2021 11:50:27 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62
   * Points/Time :
   *  58m
   * +
   *
   * Total/ETA :
   * 60m (BFS <- TS1 TS2)
   *
   * Status :
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
const string dues="NESW";
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
  dim *= 2; // TODO
  dim++;

  vector<vector<int>> dist(dim, vector<int>(dim, MAX_DIST));
  vector<string> prev(dim, string(dim, '_'));

  queue<pair<int, int>> q;
  pair<int, int> origin={dim/2, dim/2};
  int x=origin.F, y=origin.S;

  dist[x][y]=0;
  prev[x][y]='o';
  q.push({x,y});

  while (!q.empty()) {
    pair<int, int> xy=q.front();
    q.pop();

    x=xy.F, y=xy.S;
    if (x==origin.F+X && y==origin.S+Y) {
      break;
    }

    int jumpLen=1<<dist[x][y];
    REP(di,4) {
      int dx=jumpLen*DX4[di], dy=jumpLen*DY4[di];
      int xx=x+dx, yy=y+dy;
      if (bounded(xx,dim) && bounded(yy,dim) && dist[x][y]+1<dist[xx][yy]) {
        dist[xx][yy]=dist[x][y]+1;
        prev[xx][yy]=dues[di];
        q.push({xx,yy});
      }
    }
  }
  MSG_VEC_VEC(dist);
  MSG(prev);

  x=origin.F+X, y=origin.S+Y;
  if (dist[x][y]!=MAX_DIST) {
    string result;

    while (x!=origin.F && y!=origin.S) {
      char due=prev[x][y];
      result+=due;
      MSG(due);

      prev[x][y]='0'+dist[x][y];
      MSG(prev);

      int di=dues.find(due);
      int jumpLen=1<<(dist[x][y]-1);
      int dx=jumpLen*DX4[di], dy=jumpLen*DY4[di];
      MSG(jumpLen); MSG(di);

      MSG(x);  MSG(y);
      MSG(dx); MSG(dy);
      assert(dist[x][y]==dist[x-dx][y-dy]+1);
      x-=dx, y-=dy;

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
