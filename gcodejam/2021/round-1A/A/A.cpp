/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : A.cpp
   * Creation Date : 10-04-2021
   * Last Modified : Tue 13 Apr 2021 11:12:59 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007549e5
   * Points/Time :
   * ~2h20m
   * 2h30m -> practice mode already :-( :-( :-(
   *
   * upsolve:
   * +  7m20s =    7m20s
   * +  1m20s =    8m40s
   * +  2m30s =   11m10s
   * +~80m10s = 1h31m20s
   *
   * Total/ETA :
   * 15m :-/ :-(
   * 15m (upsolve)
   *
   * Status :
   * S WA - :-(
   * S AC WA :-/
   * S AC TLE :-O
   * S AC TLE :-/
   * S AC RE (probed while-loop with exit code -> RE)
   * S AC AC YESSSSSSSSSSSSSSSSS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   *
   ==========================================*/

#include <string>
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

string atLeast, newNum;

void solve() {
  int N;
  cin >> N;
  MSG(N);

  vector<string> X(N);
  REP(i,N) {
    MSG(i);
    cin >> X[i];
  }
  MSG(X); cerr.flush();

  int result = 0;
  FOR(i,1,N-1) {
    MSG(i); cerr.flush();
    if (SZ(X[i-1])<SZ(X[i])) { continue; }
    if (SZ(X[i-1])==SZ(X[i]) && X[i-1]<X[i]) { continue; }

    atLeast=X[i-1];
    bool only9s=true;
    FORD(pos,SZ(atLeast)-1,0) {
      if (atLeast[pos]=='9') {
        atLeast[pos]='0';
      } else {
        atLeast[pos]++;
        only9s=false;
        break;
      }
    }
//     if (count(ALL(atLeast), '0')==SZ(atLeast)) {
    if (only9s) {
      atLeast='1'+atLeast;
    }
    MSG(X[i-1]); MSG(atLeast); cerr.flush();

    newNum=X[i];
    if (atLeast.substr(0,SZ(X[i])) == X[i]) {  // it's a prefix
      newNum = atLeast;
    } else {
      while (SZ(newNum)<SZ(atLeast)) {
        newNum+='0';
      }
      if (newNum<atLeast) { newNum+='0'; }
    }

    result+=SZ(newNum) - SZ(X[i]);
    MSG(X[i]); MSG(newNum); MSG(result); cerr.flush();

    X[i]=newNum;
    newNum.clear();
    atLeast.clear();
    LINESEP1;
  }
  MSG(X); cerr.flush();

  cout << result << endl;
  X.clear();
  MSG(X); cerr.flush();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    cout.flush(); cerr.flush();
    solve();
    LINESEP2; cout.flush(); cerr.flush();
  }
  return 0;
}
