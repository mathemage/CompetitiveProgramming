/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : D.cpp
   * Creation Date : 11-04-2021
   * Last Modified : Sun 11 Apr 2021 03:29:23 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://atcoder.jp/contests/abc198/tasks/abc198_d
   * Points/Time :
   * Total/ETA : 400
   * Status : AC
   ==========================================*/

#include <algorithm>
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

set<char> vars;
string N1,N2,N3;
vector<bool> used;
const string digits = "0123456789";

bool search() {
  if (vars.empty()) {
    LINESEP1; MSG(stoll(N1)+stoll(N2)); MSG(N1); MSG(N2); MSG(N3); LINESEP1;
    return stoll(N1)!=0 && stoll(N2)!=0 && stoll(N3)!=0
      && stoll(N1)+stoll(N2)==stoll(N3);
  }

  char ch=*vars.begin();
  MSG(vars);

  vars.erase(ch);
  for (const char & d: digits) {
    LINESEP1; MSG(ch) MSG(d);

    if (!used[d-'0']) {
      replace(ALL(N1), ch, d);
      replace(ALL(N2), ch, d);
      replace(ALL(N3), ch, d);
      used[d-'0']=true;
      LINESEP1; MSG(N1); MSG(N2); MSG(N3); LINESEP1;

      if (N1[0]!='0' && N2[0]!='0' && N3[0]!='0'
          && search()) {
        return true;
      }

      replace(ALL(N1), d, ch);
      replace(ALL(N2), d, ch);
      replace(ALL(N3), d, ch);
      used[d-'0']=false;
      LINESEP1; MSG(N1); MSG(N2); MSG(N3); LINESEP1;
    }
  }
  MSG("here");
  vars.insert(ch);

  return false;
}

void solve() {
  string S1,S2,S3;
  cin >> S1 >> S2 >> S3;

  for (auto & S: {S1,S2,S3}) {
    for (auto & ch: S) {
      vars.insert(ch);
    }
  }

  if (vars.size()>10) {
    cout << "UNSOLVABLE" << endl;
    return;
  }

  N1=S1; N2=S2; N3=S3;
  LINESEP1; MSG(N1); MSG(N2); MSG(N3); LINESEP1;

//   assigned.assign(26, '_');
//   MSG(assigned);
  used.assign(15, false);
  MSG(used);

  if (search()) {
    cout << N1 << endl;
    cout << N2 << endl;
    cout << N3 << endl;
  } else {
    cout << "UNSOLVABLE" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  FOR(tt,1,cases) {
//     cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
