/* ========================================

   ID: mathema6
   TASK: A3
   LANG: C++14

   * File Name : A3.cpp
   * Creation Date : 12-09-2021
   * Last Modified : Sun 12 Sep 2021 06:24:56 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * Total/ETA :
   * Status :
   ==========================================*/

#define PROBLEMNAME "A3"

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

// const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;
const ld PI = acos((ld)-1);

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const int CLEAN = -INF;
const char UNDEF = '?';

void solve() {
  ll K; cin >> K;
  string U; cin >> U;
  MSG(U); LINESEP1;

  ll sumPrefixes=0;
  ll sumSuffixes=0;
  ll curLen=0;
  ll curF=0;
  ll curG=0;

  ll prevPos=CLEAN;
  char firstState=UNDEF;
  char lastState=UNDEF;
  
  for (auto & ch: U) {
    MSG(ch);

    if (ch=='.') {
      curG*=2; curG%=MOD;
      curG+=( curLen*(sumPrefixes+sumSuffixes) ) % MOD;   // (*)

      // updates
      sumPrefixes = (2*sumPrefixes + curLen * curF) % MOD;
      sumSuffixes = (2*sumSuffixes + curLen * curF) % MOD;
      curF*=2;
      if (firstState!=lastState) { // extra handswitch in-between the 2 replicates
        assert(firstState!=UNDEF);
        assert(lastState!=UNDEF);
        sumPrefixes += curLen%MOD;
        sumSuffixes += curLen%MOD;
        curF++;
      }
      
      prevPos+=curLen;
      curLen*=2;
    } else {
      // updates
      if (ch!='F') {
        if (firstState==UNDEF) {
          firstState=ch;
        }
        curF += (lastState!=UNDEF && ch!=lastState);
        sumPrefixes+=curF;
        sumSuffixes += ( (lastState!=UNDEF && ch!=lastState) * (prevPos+1) ) % MOD;

        lastState=ch;
        prevPos=curLen;
      }

      curG+=sumSuffixes%MOD;
      curLen++;
    }

    sumPrefixes%=MOD;
    sumSuffixes%=MOD;
    curLen%=MOD;
    curF%=MOD;
    curG%=MOD;
    prevPos%=MOD;

    MSG(curF);
    MSG(curG);
    LINESEP1;
  }

  cout << curG%MOD << endl;
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
