/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : C.cpp
   * Creation Date : 13-04-2021
   * Last Modified : Tue 13 Apr 2021 03:44:56 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
   * Points/Time :
   *  31m30s
   * +
   *
   * Total/ETA :
   * Status :
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
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {  // TODO test
  os << p.F << ", " << p.S;
  return os; 
}

template<typename T1, typename T2>
void print_vector_pairs(const vector<pair<T1, T2>> & vec, const string & name) {  // TODO test
  cerr << "> " << name << ": ";
//   for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  for (const auto & x: vec) cerr << "(" << x << ")\t";
  cerr << endl;
}

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

const int CLEAN = -1;
const int UNDEF = -42;
// const long long MOD = 1000000007;
const long long MOD = 1e9;
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

string prog;
string dues="NESW";
int di;

pair<int, int> getShift(int progPos=0) {
  pair<int, int> dwh={0,0};

  if (progPos<SZ(prog)-1) {
    switch (prog[progPos]) {
      case 'N': 
      case 'E': 
      case 'S': 
      case 'W': 
        di=find(ALL(dues),prog[progPos]) - dues.begin();
        MSG(prog[progPos]); MSG(di);

        dwh=getShift(progPos+1);
        dwh.F+=DXY4[di].F, dwh.S+=DXY4[di].S;
        dwh.F%=MOD, dwh.S%=MOD;
        MSG(dwh); // TODO MSG pair

        return dwh;

      case '(': exit(1); // TODO
      case ')': exit(1); // TODO
    }
  }

  return dwh;
}

void solve() {
  cin >> prog;

  pair<int, int> dwh = getShift();
  cout << 1+dwh.F << " " << 1+dwh.S << endl;
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
