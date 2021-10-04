/* ========================================

   ID: mathema6
   TASK: C
   LANG: C++14

   * File Name : C.cpp
   * Creation Date : 18-09-2021
   * Last Modified : Sat 02 Oct 2021 11:00:07 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000888d45
   * Points/Time :
   *      =    15m
   * + 5m =    20m [refactor only]
   * [testdata]
   * +17m =    37m
   * +~2m
   * +12m ~    51m
   * [testdata]
   * +13m = 1h 4m
   * +12m = 1h16m
   *
   * Total/ETA : 11+12+12pts
   * Status :
   * S WA - - :-/ :-(
   * S WA - - :-( :-(
   * S WA - - :-( :-(
   * S WA - - :-( :-(
   * S WA - - :-( :-( :-(
   * [upsolve]
   * S WA - - :-( :-( :-( :-(
   * S WA - - :-( :-( :-( :-( [refactor only]
   * [testdata]
   * S WA - - :-( :-( :-( :-( :-/
   * S WA - - :-( :-( :-( :-( :-/ :-(
   * [testdata]
   * S WA - - :-( :-( :-( :-( :-/ :-( :-( f*ck already!
   * S AC WA - :-O :-/ ^_^
   *
   ==========================================*/

#include <algorithm>
#include <cmath>
#define PROBLEMNAME "C"

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
// inline bool eqDouble(ld a, ld b) { return fabs(a-b) < 1e-9; }
inline bool eqDouble(ld a, ld b) { return fabs(a-b) < 1e-7; }

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

// const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;


inline ld area(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
  return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool isInside(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x, ld y) {
  ld A  = area(x1, y1, x2, y2, x3, y3);
  ld A1 = area(x, y, x2, y2, x3, y3);
  ld A2 = area(x1, y1, x, y, x3, y3);
  ld A3 = area(x1, y1, x2, y2, x, y);

  return eqDouble(A, A1 + A2 + A3);
//   return A == A1 + A2 + A3;
}

inline ld dist(ld x1, ld y1, ld x2, ld y2) {
  return sqrtl( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
//   return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

inline bool onLine(ld x, ld y, ld x1, ld y1, ld x2, ld y2) {
  return eqDouble(dist(x, y, x1, y1) + dist(x, y, x2, y2), dist(x1, y1, x2, y2));
}

bool onBorder(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x, ld y) {
  ld A1 = area(x, y, x2, y2, x3, y3);
  ld A2 = area(x1, y1, x, y, x3, y3);
  ld A3 = area(x1, y1, x2, y2, x, y);

//   return A1==0 || A2==0 || A3==0;
  return eqDouble(min({A1, A2, A3}), 0.0);
}

const ld INF = 1e15;

void solve() {
  ll N; cin >> N;
  vector<ld> X(N);
  vector<ld> Y(N);
  REP(i,N) {
    cin >> X[i] >> Y[i];
  }
  ld Xs,Ys;
  cin >> Xs >> Ys;
  MSG(N);
  MSG(X); MSG(Y);
  MSG(Xs); MSG(Ys);
  LINESEP1;

  ld result = INF;
//   MSG(result); LINESEP1;

  bool found=false;
  REP(i,N) {
    FOR(j,i+1,N-1) {
      FOR(k,j+1,N-1) {
        if (isInside(X[i], Y[i], X[j], Y[j], X[k], Y[k], Xs, Ys)) {
          if (!onBorder(X[i], Y[i], X[j], Y[j], X[k], Y[k], Xs, Ys)) {
            if (umin(result, dist(X[i], Y[i], X[j], Y[j]) + 
                             dist(X[j], Y[j], X[k], Y[k]) + 
                             dist(X[k], Y[k], X[i], Y[i])) ) {
              MSG(i); MSG(j); MSG(k);
              MSG(result); LINESEP1;
              found=1;
            }
          } else {
            FOR(l,k+1,N-1) {
              vector<ll> ijkl = {i,j,k,l};
              do {
                ll a=ijkl[0];
                ll b=ijkl[1];
                ll c=ijkl[2];
                ll d=ijkl[3];
                // check ijkl is a non-degenerate quadrilateral!
                if (onLine(Xs,Ys, X[a],Y[a], X[c],Y[c])
                 && onLine(Xs,Ys, X[b],Y[b], X[d],Y[d]) 
                 && !eqDouble(area(X[a],Y[a], X[c],Y[c], X[b],Y[b]), 0.0) 
                 && !eqDouble(area(X[a],Y[a], X[c],Y[c], X[d],Y[d]), 0.0) 
                 ) {
                  if ( umin(result, dist(X[a], Y[a], X[b], Y[b]) + 
                                    dist(X[b], Y[b], X[c], Y[c]) + 
                                    dist(X[c], Y[c], X[d], Y[d]) + 
                                    dist(X[a], Y[a], X[d], Y[d])) ) {
                    MSG(a); MSG(b); MSG(c); MSG(d);
                    MSG(result); LINESEP1;
                    found=1;
                  }
                }
              } while (next_permutation(ALL(ijkl)));
            }
          }
        }
      }
    }
  }

  if (!found) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << result << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
//   cout << std::setprecision(10) << std::fixed;
  cout << std::setprecision(9) << std::fixed;
  cerr << std::setprecision(9) << std::fixed;

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
