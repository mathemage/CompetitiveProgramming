/* ========================================
   * Created By : mathemage
   * Points/Time :
   * Total/ETA :
   * Status :
   * TLE on sample <- too inefficient
   * unsolved after 2hrs :-( :-(
   *
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
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((int) (x).size())
#define YES return "Possible";
#define NO return "Impossible";
#define YN(b) return ((b)?"Possible":"Impossible");

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

template<typename T>
inline ostream& operator<<=(ostream& os, const T & x) { os << x; return os; }

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

class GCDGraph {
  bool isprime[1005];

  vector<int> eratosthenes_sieve(int LIMIT) {
    memset(isprime, 1, sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<LIMIT;++i)
      if(isprime[i])
        for(int j=i*i;j<LIMIT;j+=i)
          isprime[j]=false;
    vector<int> pr;
    FOR(i,2,LIMIT) if(isprime[i]) pr.push_back(i);
    return pr;
  }

public:
  string possible(int n, int k, int x, int y) {
    vector<int> primes=eratosthenes_sieve(1005);

    LINESEP2;
    if (x==y || k==0) { YES; }
    if (!(k<x && k<y)) { NO; }

    ll lcm=ll(x)*ll(y)/(ll)(__gcd(x,y));
//     MSG(lcm); LINESEP1;
    if (k<lcm && lcm<=n) { YES; }

    queue<int> q;
    vector<bool> vis(n+5);

    q.push(x);
    vis[x]=1;

    auto visitNeigh = [&](int m, int p) {
      for (int mi = p*max(1,k/p); mi <= n; mi += p) {
        if (!vis[mi] && __gcd(mi,m)>k) {
          vis[mi]=1;
          q.push(mi);
        }
      }
    };

    while (!q.empty()) {
      int m=q.front(); q.pop();
      MSG(m);

      if (m==y) {
        YES;
      }

      int mm=m;
      for (auto & p: primes) {           // iterate over neighbors
        if (p*p>mm) { break; }

        if (mm%p==0) {
          visitNeigh(m,p);
          while (mm%p) { mm/=p; }
        }
      }
      if (mm>1) {
        visitNeigh(m,mm);
      }
    }

    NO;
  }
};

/*
* (RE-)COMPILE LAST VERSION BEFORE SUBMITTING!!!!!
  - or CHECK ADDITIONALLY IN THE ROOM SUMMARY (whether CORRECT source code was submitted)!!!!

* NEVER SUBMIT BRUTE-FORCE/INFERIOR SOLUTION WHEN IT MIGHT BE TOO SLOW!!
  - Or always re-compile again!

* Be careful of INT OVERFLOW WHEN INPUT PARAMETERS ARE IN INTS!
  - re-cast to ll vars
*/
