/* ========================================

   ID: mathema6
   TASK: A
   LANG: C++14

   * File Name : A.cpp
   * Creation Date : 25-04-2021
   * Last Modified : Sun 25 Apr 2021 08:13:38 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae694
   * Points/Time :
   * Total/ETA :
   * Status :
   * S AC WA - !!
   *
   ==========================================*/

#define PROBLEMNAME "A"

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

ll A, B, C;
ll h,m,s,n;
ll Tnsec;

const ll SEC_IN_DAY = 12 * 60 * 60;
const ll NSEC_IN_SEC=1e9;

void solve() {
  cin >> A >> B >> C;
  vector<ll> angles = {A,B,C};
  sort(ALL(angles));
  vector<long long> diffs={
    angles[1]-angles[0], 
    angles[2]-angles[1], 
    angles[0]-angles[2]
  };

  h=m=s=n=UNDEF;

//   map<string, ll> remNSec;
  map<string, ll> remSec;
  map<string, ll> phiTicks;

  for (ll Tsec = 0LL; Tsec < SEC_IN_DAY; Tsec += 1) {
    MSG(Tsec); MSG(Tnsec);

    remSec["s"]=Tsec%60;
    remSec["m"]=Tsec%3600;
    remSec["h"]=Tsec;
    MSG(remSec);

    phiTicks["s"]=remSec["s"]*720*NSEC_IN_SEC;
    phiTicks["m"]=remSec["m"]*12*NSEC_IN_SEC;
    phiTicks["h"]=remSec["h"]*NSEC_IN_SEC;

    vector<ll> angles2 = {phiTicks["s"], phiTicks["m"], phiTicks["h"]};
    sort(ALL(angles2));

    vector<long long> diffs={
      angles2[1]-angles2[0], 
      angles2[2]-angles2[1], 
      angles2[0]-angles2[2]
    };

    if (angles==angles2) {
      h=Tsec/3600;
      Tsec%=3600;

      m=Tsec/60;
      s=Tsec%60;

      n=0;  // TODO
      break;
    }

    LINESEP1;
  }

  cout << h << " " << m << " " << s << " " <<  n << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifndef MATHEMAGE_LOCAL
//   setIO(PROBLEMNAME);
#endif

  int cases = 1;
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
