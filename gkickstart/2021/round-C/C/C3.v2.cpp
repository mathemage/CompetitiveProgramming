/* ========================================

   ID: mathema6
   TASK: C3
   LANG: C++14

   * File Name : C3.cpp
   * Creation Date : 12-08-2021
   * Last Modified : Thu 12 Aug 2021 12:42:27 AM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ec28e#problem
   * Points/Time :
   *      = 22m
   * + 6m = 28m
   *
   * Total/ETA : 25m
   * Status :
   * S AC WA - :-/
   * S AC AC AC Yeeeeesssssssssssssssssssssss!!!
   *
   ==========================================*/

#define PROBLEMNAME "C3"

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
#define SZi(x) ((int) (x).size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define YN(b) cout << ((b)?"YES":"NO") << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define Yn(b) cout << ((b)?"Yes":"No") << endl;

using ll = long long;
using ul = unsigned long long;
// using llll = pair<ll, ll>;
using ulul = pair<ul, ul>;
using ld = long double;
using graph_umap = unordered_map<ll, vector<ll>>;
using graph_map  = unordered_map<ll, vector<ll>>;
using graph_t    = graph_umap;

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

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

string optimalMoves;
const int MX=60;

string getOptMoves(ll W, ll E) {
  ld bestVal[5+MX][5+MX][5+MX]{};
//   bestVal[0][0][0]=0.0;
  char bestMove[5+MX][5+MX][5+MX]{};

  ld bestExpVal=0.0;
  ll bestR=UNDEF;
  ll bestP=UNDEF;
  ll bestS=UNDEF;
  FOR(sum,1,MX) {
    FOR(ri,0,MX) {
      FOR(pi,0,sum-ri) {
        ll si=sum-ri-pi;

        // opponent's probs
        ld probR = (sum==1) ? 1/3.0 : si/(sum-1.0);
        ld probP = (sum==1) ? 1/3.0 : ri/(sum-1.0);
        ld probS = (sum==1) ? 1/3.0 : pi/(sum-1.0);

        if (ri-1>=0 && umax(bestVal[ri][pi][si], bestVal[ri-1][pi][si] + probS*W + probR*E)) {
          bestMove[ri][pi][si]='R';
        }
        if (pi-1>=0 && umax(bestVal[ri][pi][si], bestVal[ri][pi-1][si] + probR*W + probP*E)) {
          bestMove[ri][pi][si]='P';
        }
        if (si-1>=0 && umax(bestVal[ri][pi][si], bestVal[ri][pi][si-1] + probP*W + probS*E)) {
          bestMove[ri][pi][si]='S';
        }

        if (sum==MX && umax(bestExpVal, bestVal[ri][pi][si])) {
          bestR=ri;
          bestP=pi;
          bestS=si;
          MSG(bestExpVal);
        }
      }
    }
  }

  string ans;
  while (max({bestR, bestP, bestS}) > 0) {
    char move=bestMove[bestR][bestP][bestS];
    ans+=move;
    
    switch (move) {
      case 'R':
        bestR--;
        break;
      case 'P':
        bestP--;
        break;
      case 'S':
        bestS--;
        break;
    }
  }
  assert(bestR>=0);
  assert(bestP>=0);
  assert(bestS>=0);

  std::reverse(ALL(ans));
  return ans;
}

void solve() {
  ll W,E; cin >> W >> E;
  cout << getOptMoves(W,E) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << std::setprecision(10) << std::fixed;

#ifndef MATHEMAGE_LOCAL
//   setIO(PROBLEMNAME);
#endif

//   optimalMoves=getOptMoves();

  int cases = 1;
  cin >> cases;
  ll X; cin >> X;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
