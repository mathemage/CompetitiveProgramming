/* ========================================

   ID: mathema6
   TASK: E
   LANG: C++14

   * File Name : E.cpp
   * Creation Date : 13-07-2021
   * Last Modified : Wed 14 Jul 2021 12:12:34 AM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * +     2m [reading]
   * + 10-15m [thinking]
   * +     6m
   * +     6m = 24-29m
   * +     4m =    33m
   * +    10m =    43m
   *
   * Total/ETA :
   * [50m ETA]
   *
   * Status :
   * AC x7, TLE x14 :-O :-/ :-(
   * AC x7, TLE x14 :-/ :-/
   * [download testcase 1_04] -> wrong approach, exponential algo!
   *
   ==========================================*/

#include <functional>
#define PROBLEMNAME "E"

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define REPi(i,n) for(int i=0;i<(n);i++)
#define FORi(i,a,b) for(int i=(a);i<=(b);i++)
#define FORDi(i,a,b) for(int i=(a);i>=(b);i--)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MTP make_tuple
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((int) (x).size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define YN(b) cout << ((b)?"YES":"NO") << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define Yn(b) cout << ((b)?"Yes":"No") << endl;

using ll = long long;
using ul = unsigned long long;
using llll = pair<ll, ll>;
using ulul = pair<ul, ul>;
using ld = long double;

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC_VEC(v)
  #define LINESEP1
  #define LINESEP2
#endif

ostream& operator<<(ostream& os, const vector<string> & vec) { os << endl; for (const auto & s: vec) os << s << endl; return os; }

template<typename T> 
ostream& operator<<(ostream& os, const vector<T> & vec) { for (const auto & x: vec) os << x << " "; return os; } 

template<typename T> 
ostream& operator<<(ostream& os, const vector<vector<T>> & vec) { for (const auto & v: vec) os << v << endl; return os; } 

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
ostream& operator<<(ostream& os, const set<T, Compare>& vec) { for (const auto & x: vec) os << x << " "; os << endl; return os; } 

template<typename T, class Compare>
ostream& operator<<(ostream& os, const multiset<T, Compare>& vec) { for (const auto & x: vec) os << x << " "; os << endl; return os; }

template<typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2, std::greater<T1>>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2> 
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.F << ", " << p.S << ")"; }

template<typename T>
istream& operator>>(istream& is, vector<T> & vec) { for (auto & x: vec) is >> x; return is; }

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) { return min(l,u)<=x && x<max(l,u); }

template<class T> bool umin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

inline bool eqDouble(double a, double b) { return fabs(a-b) < 1e-9; }

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = {0, 1,  0, -1};
const vector<int> DY4 = {1, 0, -1,  0};
const vector<pair<int,int>> DXY4 = { {0,1}, {1,0}, {0,-1}, {-1,0} };
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

void solve() {
  ll N,W; cin >> N >> W;

  map<ll, ll, std::greater<ll>> bestVal;
  bestVal[0]=0;

  ll result = 0LL;
  ll w, v;
  REP(i,N) {
    MSG(i);

    cin >> w >> v;
    MSG(w); MSG(v);

//     MSG(bestVal);
    for (auto & wv: bestVal) {
      if (wv.F+w<=W) {
        umax(bestVal[wv.F+w], wv.S+v);
        umax(result, bestVal[wv.F+w]);
//         MSG(result); MSG(bestVal[wv.F+w]);
      }
    }
    MSG(SZ(bestVal));
    MSG(bestVal);

    LINESEP1;
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << std::setprecision(10) << std::fixed;

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
