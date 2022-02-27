/* ========================================

   ID: mathema6
   TASK: s2.2
   LANG: C++14

   * File Name : s2.2.cpp
   * Creation Date : 27-02-2022
   * Last Modified : Sun 27 Feb 2022 06:49:09 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem&cpid=1195
   * Points/Time :
   * Total/ETA :
   * Status :
   * 2/16 ACs, 5/16 WAs, 1/16 TLE, 8/16 MLE/TLEs :-/
   * 2/16 ACs, 5/16 WAs, 1/16 TLE, 8/16 MLE/TLEs :-/ :-/
   *
   ==========================================*/

#include <algorithm>
#define PROBLEMNAME "s2.2"

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
// #define endl "\n" << flush  // flush for interactive problems
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
  #define LINESEP2 cerr << "#################################################################" << endl;
  #define LINESEP3 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC_VEC(v)
  #define LINESEP1
  #define LINESEP2
  #define LINESEP3
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
  ll xg,yg; cin >> xg >> yg;
  ll gx=xg, gy=yg;

  vector<ll> xs(N);
  vector<ll> ys(N);
  REP(i,N) {
    cin >> xs[i] >> ys[i];
    gx=__gcd(gx, xs[i]);
    gy=__gcd(gy, ys[i]);
  }
  MSG(xg); MSG(yg);
  MSG(xs); MSG(ys);
  LINESEP2;

  xg/=gx, yg/=gy;
  for (auto & xi: xs) { xi/=gx; }
  for (auto & yi: ys) { yi/=gy; }
  MSG(xg); MSG(yg);
  MSG(xs); MSG(ys);
  LINESEP2;

  unordered_map<ll, unordered_map<ll, unordered_map<ll, unordered_map<ll, ll>>>> ways;
  ways[-1][0][0][0]=1LL;

#ifdef MATHEMAGE_DEBUG
  unordered_map<ll, unordered_map<ll, unordered_map<ll, unordered_map<ll, ll>>>> paths;
  paths[-1][0][0][0].PB({});
#endif

  REP(i,N) {
    MSG(i);
    MSG(xs[i]); MSG(ys[i]);
    LINESEP1;

    for (auto & [last, xykw]: ways) {
      if (last>=i) {
        continue;
      }

      for (auto & [x, ykw]: xykw) {
        for (auto & [y, kw]: ykw) {
          for (auto & [k,w]: kw) {
            ways[i][x+xs[i]][y+ys[i]][k+1] += w;
#ifdef MATHEMAGE_DEBUG
            for (auto p: paths[last][x][y][k]) {
              p.PB(i+1);
              paths[i][x+xs[i]][y+ys[i]][k+1].PB(p);
            }
#endif

            if (k==3 && x+xs[i]==xg && y+ys[i]==yg) {
              MSG(x); MSG(y); MSG(k); MSG(w);
              MSG_VEC_VEC(paths[last][x][y][k]);
              MSG_VEC_VEC(paths[i][x+xs[i]][y+ys[i]][k+1]);
              LINESEP1;
            }
          }
        }
      }
    }
    LINESEP2;
  }

  FOR(k,1,N) {
    ll ans=0;
    FOR(last,0,N) {
      ans+=ways[last][xg][yg][k];
    }
    cout << ans << endl;
  }
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
    LINESEP3;
  }
  return 0;
}
