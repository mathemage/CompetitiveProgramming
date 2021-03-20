/* ========================================
   * File Name : D.upsolve.cpp
   * Creation Date : 20-03-2021
   * Last Modified : Sat 20 Mar 2021 03:54:01 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://atcoder.jp/contests/abc196/tasks/abc196_d
   * Points/Time :
   *  10m
   * +12m20s = 22m20s
   *
   * Total/ETA : 400
   * Status :
   * AC !!!!
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
  #define MSG_VEC(v) print_vector((v), (#v));
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define MSG_VEC_STR(v) print_vector_string((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define MSG_VEC_STR(v)
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

long long h,w,a,b;
vector<string> room;

long long dfs() {
//   if (h<=0 && w<=0) {
//     return (a==0 && b==0? 1:0);
//   }

  long long result = 0LL;
  REP(r,h) {
    REP(c,w) {
      if (room[r][c]=='_') {
        room[r][c]='#';

        if (b>0) {
          b--;
          result += dfs();
          b++;
        }
        if (a>0 && c+1<w && room[r][c+1]=='_') {
          room[r][c+1]='#';
          a--;
          result += dfs();
          room[r][c+1]='_';
          a++;
        }
        if (a>0 && r+1<h && room[r+1][c]=='_') {
          room[r+1][c]='#';
          a--;
          result += dfs();
          room[r+1][c]='_';
          a++;
        }

        room[r][c]='_';
        return result;
      }
    }
  }
  MSG_VEC_STR(room);

  return 1;
}

void solve() {
  cin >> h >> w >> a >> b;

  room.resize(h);
  REP(r,h) {
    room[r].resize(w);
    REP(c,w) {
      room[r][c]='_';
    }
  }
  MSG_VEC_STR(room);

  cout << dfs() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}
