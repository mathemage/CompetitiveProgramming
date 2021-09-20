 
/* ========================================

   ID: mathema6
   TASK: A
   LANG: C++14

   * File Name : A.cpp
   * Creation Date : 20-09-2021
   * Last Modified : Po 20. září 2021, 21:30:58
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2020/round-2/problems/A
   * Points/Time :
   * =50m
   *
   * Total/ETA : 12/100 pts
   * Status :
   * AC! Yesss!
   *
   ==========================================*/

#define PROBLEMNAME "A"

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

inline bool eqDouble(double a, double b) { return fabs(a-b) < 1e-9; }

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
  ll N,K; cin >> N >> K;
  vector<ll> S(K); cin >> S;
  ll As,Bs,Cs,Ds; cin >> As >> Bs >> Cs >> Ds;
  vector<ll> X(K); cin >> X;
  ll Ax,Bx,Cx,Dx; cin >> Ax >> Bx >> Cx >> Dx;
  vector<ll> Y(K); cin >> Y;
  ll Ay,By,Cy,Dy; cin >> Ay >> By >> Cy >> Dy;
  MSG(N);

  FOR(i,K,N-1) {
    S.PB( (As*S[i-2] + Bs*S[i-1] + Cs) % Ds) ;
    X.PB( (Ax*X[i-2] + Bx*X[i-1] + Cx) % Dx) ;
    Y.PB( (Ay*Y[i-2] + By*Y[i-1] + Cy) % Dy) ;
  }
  MSG(S); MSG(X); MSG(Y); LINESEP1;

  ll under=0;
  ll over=0;
  REP(i,N) {
    if (S[i]<X[i]) {
      under+=X[i]-S[i];
    }
    if (S[i]>X[i]+Y[i]) {
      over+=S[i]-X[i]-Y[i];
    }
  }
  MSG(under); MSG(over); LINESEP1;

  ll result = 0LL;
  ll delta;
  if (over>=under) {
    over-=under;
    result+=under;
    MSG(over); MSG(result); LINESEP1;

    REP(i,N) {
      if (S[i]<X[i]) {
        S[i]=X[i];
      }

      if (S[i]<X[i]+Y[i]) {
        delta=min(over, X[i]+Y[i]-S[i]);
        over-=delta;
        result+=delta;
        MSG(delta); MSG(over); MSG(result); LINESEP1;
      }
    }

    if (over>0) {
      result=-1;
    }
  } else if (over<under) {
    under-=over;
    result+=over;

    REP(i,N) {
      if (S[i]>X[i]+Y[i]) {
        S[i]=X[i]+Y[i];
      }

      if (S[i]>X[i]) {
        delta=min(under, S[i]-X[i]);
        under-=delta;
        result+=delta;
      }
    }

    if (under>0) {
      result=-1;
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
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
