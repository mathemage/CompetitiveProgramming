/* ========================================
   * Created By : mathemage
   * Points/Time : 499.60
   * Total/ETA : 500
   * Status : AC
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

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
  #define _D(a) cerr << "> " << (#a) << ": "; cerr <<= (a); cerr << endl;
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n"; (print_vector_vector(cerr, (v))) << endl;
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;

  #define MSG_VEC(v) cerr << "> " << (#v) << ": "; (print_vector(cerr, (v))) << endl;
  #define MSG_VEC_STR(v) cerr << "> " << (#v) << ": "; (print_vector_string(cerr, (v))) << endl;
#else
  #define MSG(a)
  #define _D(a)
  #define MSG_VEC_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2

  #define MSG_VEC(v)
  #define MSG_VEC_STR(v)
#endif

inline ostream& operator<<=(ostream& os, const vector<string> & vec) { os << endl; for (const auto & s: vec) cerr << s << endl; return os; }
inline ostream& print_vector_string(ostream& os, const vector<string> & vec) { os << endl; for (const auto & s: vec) cerr << s << endl; return os; }

template<typename T>
inline ostream& operator<<=(ostream& os, const vector<T> & vec) { for (const auto & x: vec) os << x << " "; return os; }
template<typename T> 
inline ostream& print_vector(ostream& os, const vector<T> & vec) { for (const auto & x: vec) os << x << " "; return os; } 

template<typename T>
inline ostream& print_vector_vector(ostream& os, const vector<vector<T>> & vec) {
  for (const auto & line: vec) {
    for (const auto & it: line) {
      os << it << " ";
    }
    os << endl;
  }
  return os;
}

template<typename T, class Compare>
inline ostream& operator<<=(ostream& os, const set<T, Compare>& vec) { for (const auto & x: vec) os << x << " "; os << endl; return os; }

template<typename T, class Compare>
inline ostream& operator<<=(ostream& os, const multiset<T, Compare>& vec) { for (const auto & x: vec) os << x << " "; os << endl; return os; }

template<typename T1, typename T2>
inline ostream& operator<<=(ostream& os, const map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2>
inline ostream& operator<<=(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.F << ", " << p.S << ")"; }

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) { return min(l,u)<=x && x<max(l,u); }

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

class LimitedDifferences {
public:
  vector <int> arrange(int N, int V) {
    LINESEP2;

    vector <int> result(N);
    iota(ALL(result), 1);
    FOR(v,1,V-1) {
      reverse(result.begin()+v,result.end());
    }
    return result;
  }
};

/*
Remember:
1) (RE-)COMPILE LAST VERSION BEFORE SUBMITTING!!!!!
2) CHECK ADDITIONALLY IN THE ROOM SUMMARY (whether CORRECT source code was submitted)!!!!
  - Or `vimdiff solutionName*` should produce no diffs!
3) Never submit brute-force/inferior solution when it might be too slow!!
  - Or always re-compile again!
*/
