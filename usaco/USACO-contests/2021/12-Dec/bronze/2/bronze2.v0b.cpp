/* ========================================

   ID: mathema6
   TASK: bronze2
   LANG: C++14

   * File Name : bronze2.cpp
   * Creation Date : 18-12-2021
   * Last Modified : Sat 18 Dec 2021 06:32:07 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem&cpid=1144
   * Points/Time :
   * Total/ETA :
   * Status :
   * not submitted :-(
   *
   ==========================================*/

#include <algorithm>
#define PROBLEMNAME "bronze2"

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
#define OP first
#define CL second
#define PB push_back
#define MP make_pair
#define MTP make_tuple
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((ll) (x).size())
// #define SZi(x) ((int) (x).size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define YN(b) cout << ((b)?"YES":"NO") << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define Yn(b) cout << ((b)?"Yes":"No") << endl;
#define Imp cout << "Impossible" << endl;
#define IMP cout << "IMPOSSIBLE" << endl;

using ll = long long;
using ul = unsigned long long;
// using ulul = pair<ul, ul>;
using ld = long double;
using graph_unord = unordered_map<ll, vector<ll>>;
using graph_ord  = map<ll, set<ll>>;
using graph_t    = graph_unord;

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
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.F << ", " << p.S << ")"; }

template<typename T>
istream& operator>>(istream& is, vector<T> & vec) { for (auto & x: vec) is >> x; return is; }

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) { return min(l,u)<=x && x<max(l,u); }

template<class T> bool umin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// inline bool eqDouble(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool eqDouble(ld a, ld b) { return fabs(a-b) < 1e-9; }
inline bool isCollinear(ld x, ld y, ld x1, ld y1, ld x2, ld y2) {
  // (x-x1)/(y-y1) == (x-x2)/(y-y2)
  // (x-x1)*(y-y2) == (x-x2)*(y-y1)
  return eqDouble((x-x1)*(y-y2), (x-x2)*(y-y1));
}
inline bool isBetween(ld x, ld y, ld x1, ld y1, ld x2, ld y2) {
  return min(x1,x2)<=x && x<=max(x1,x2)
      && min(y1,y2)<=y && y<=max(y1,y2);
}
inline bool onLine(ld x, ld y, ld x1, ld y1, ld x2, ld y2) {
  return isCollinear(x, y, x1, y1, x2, y2) && isBetween(x, y, x1, y1, x2, y2);
}


#ifndef MATHEMAGE_LOCAL
void setIO(string filename) {    // the argument is the filename without the extension
	freopen((filename+".in").c_str(), "r", stdin);
	freopen((filename+".out").c_str(), "w", stdout);
  MSG(filename);
}
#endif

const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

const vector<int> DX4 = {0, 1,  0, -1};
const vector<int> DY4 = {1, 0, -1,  0};
const vector<pair<int,int>> DXY4 = { {0,1}, {1,0}, {0,-1}, {-1,0} };
const string dues="NESW";

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;
const ld PI = acos((ld)-1);

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;


void solve() {
  ll N; cin >> N;
  vector<ll> p(N); cin >> p;
  vector<ll> t(N); cin >> t;
  MSG(p); MSG(t); LINESEP1;

  vector<ll> deltas(N);
  unordered_map<ll, vector<ll>> val2pos;
  REP(i,N) {
    deltas[i] = p[i]-t[i];
  }
  deltas.PB(0);   // dummy
  MSG(deltas); LINESEP1;

  for (ll i = 0; i < SZ(deltas); i += 1) {
    val2pos[deltas[i]].PB(i);
  }
  MSG(val2pos); LINESEP1;

  auto queryMin = [&](ll left, ll right) {
    ll ans=INF_LL;
    FOR(pos,left,right) {
      umin(ans, deltas[pos]);
    }
    return ans;
  };

  unordered_map<ll, unordered_map<ll, unordered_map<ll, ll>>> memo;
  function<ll(ll,ll,ll)> calculateOpt = [&](ll left, ll right, ll baseHeight) {
    LINESEP1;
    MSG(left); MSG(right); MSG(baseHeight);

    if (left>right) { return 0LL; }
    if (left==right) { return deltas[left]-baseHeight; }

    if (CONTAINS(memo, left) && CONTAINS(memo[left], right) && CONTAINS(memo[left][right], baseHeight)) {
      return memo[left][right][baseHeight];
    }

    ll mn=queryMin(left, right);
    ll ans = mn-baseHeight;
    MSG(mn);
    MSG(val2pos[mn]);

    auto it = std::lower_bound(ALL(val2pos[mn]), left);
    vector<ll> posOfInterest{left};
    while (*it<=right) {
      if (it!=val2pos[mn].end()) {
        posOfInterest.PB(*it);
      }
      it++;
    }
    posOfInterest.PB(right);
    MSG(posOfInterest);

    for (ll i = 1; i < SZ(posOfInterest); i += 1) {
      ans += calculateOpt(posOfInterest[i-1], posOfInterest[i], mn);
    }

    return memo[left][right][baseHeight] = ans;
  };

  ll result = 0LL;

  ll prev=0;
  for (ll i = 1; i < N+1; i += 1) {
    if (SGN(deltas[i]) != SGN(deltas[i-1])) {
      if (SGN(deltas[i-1])!=0) {
        result += calculateOpt(prev, i-1, 0);
      }

      prev=i;
    }
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
