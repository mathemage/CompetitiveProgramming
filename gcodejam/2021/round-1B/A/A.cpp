/* ========================================

   ID: mathema6
   TASK: A
   LANG: C++14

   * File Name : A.cpp
   * Creation Date : 26-04-2021
   * Last Modified : Thu 29 Apr 2021 08:36:37 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae694
   * Points/Time :
   *  -4m (wash up)
   *  45m =   41m :-/
   * +17m =   58m :-/ :-(
   * + 6m = 1h 4m
   * +24m
   * + 3m =
   * +27m = 1h31m
   * + 7m = 1h38m
   * + 6m = 1h44m
   * + 2m = 1h46m
   * + 9m = 1h54m [testdata]
   * + 9m = 2h 3m [editorial]
   * +~4m [testcase in6]
   * +1h15m = 3h22m :-( :-( :-(
   * +  58m (= 4h20m :-( :-( :-( :-( :-( :-() <- not debugged yet :-/
   *
   * Total/ETA :
   *   25m
   *   48m
   * 1h30m
   * 4h00m
   *
   * Status :
   * S AC AC WA :-)
   * S AC AC MLE :-O
   * S AC AC TLE !
   * MLE on S(ample) [when multi == 100] :-/
   * S AC AC WA :-( :-(
   * S AC AC RE :-O (couldn't find full seconds??)
   * S AC AC RE :-O (non-zero nanosecond even after shift??)
   * S AC AC RE :-O (couldn't find full seconds??)
   * [testdata] -> wrong approach (remainders after 1e9 not divisible by 11, 719, 708?)
   * [editorial]
   * S AC RE - :-O :-( :-( :-(
   *
   ==========================================*/

#include <algorithm>
#include <unordered_map>
#define PROBLEMNAME "A"

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
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

using l3 = tuple<ll, ll, ll>;
vector<long long> ABC(3);
vector<long long> ABC2(3);
vector<long long> ang(3);
map<llll, vector<long long>> angle2time;
vector<long long> hms;

const ll TICKS_IN_FULL_CIRCLE = 360 * 12 * 1e10;
const ll NANO_IN_SEC = 1e9;

inline ll modulo(ll x, ll mod=NANO_IN_SEC) {
  return (x%mod + mod) % mod;
}

// vector<vector<long long>> getCanon(vector<long long> angles) {
//   vector<vector<long long>> result;
//   REP(iOffset,3) {
//     result.PB({});
//     REP(iAng,3) {
//       if (iOffset!=iAng) {
//         result.back().PB(
//             (angles[iAng]-angles[iOffset]+TICKS_IN_FULL_CIRCLE) % TICKS_IN_FULL_CIRCLE // TODO use modulo()
//             );
//       }
//     }
//     sort(ALL(result.back()));  // TODO should sort??
//   }
//   return result;
// }
// 
inline llll getCanon(vector<long long> angles) { // angles[0] = hour hand, angles[1] = min hand, angles[0] = sec hand
  llll result{angles[1]-angles[0], angles[2]-angles[0]};
  result.F=modulo(result.F, TICKS_IN_FULL_CIRCLE);
  result.S=modulo(result.S, TICKS_IN_FULL_CIRCLE);
  return result;
}

void solve() {
  cin >> ABC;
  MSG(ABC);

  ll n=UNDEF;
  ll nsSince=UNDEF;  // nanosecs since the last full hour

  LINESEP1;
  ll angH,angM;
  ll m,s;            // whole mins, secs
  REP(h,12) {        // whole hours
    MSG(h);
    do {
      LINESEP1;
      MSG(ABC);
      angH=ABC[0], angM=ABC[1];

      // angM-angH == 12*ns - (3600*h*1e9 + ns)
      // angM-angH == 11*ns - 3600*h*1e9
      // angM-angH+3600*h*1e9 == 11*ns 
      if ((angM-angH+3600LL*h*NANO_IN_SEC) % 11LL != 0LL) continue;
      nsSince=(angM-angH+3600LL*h*NANO_IN_SEC)/11LL;
      MSG(nsSince); MSG(nsSince/NANO_IN_SEC);

      if (!(0<=nsSince && nsSince<3600*NANO_IN_SEC)) continue;

      n=nsSince%NANO_IN_SEC;
      s=(nsSince/NANO_IN_SEC)%60LL;
      m=(nsSince/NANO_IN_SEC)/60LL;
      vector<long long> need{h,m,s,n};
      MSG(need);

      // shift back by n nanosecs
      ABC2=ABC;
      MSG(ABC2);
      ABC2[0]-=n;       // hour hand
      ABC2[1]-=12LL*n;  // min hand
      ABC2[2]-=720LL*n; // sec hand
      MSG(ABC2);
      for (auto & a: ABC2) { a=modulo(a, TICKS_IN_FULL_CIRCLE); }
      MSG(ABC2);

      llll canon=getCanon(ABC2);
      MSG(canon.F); MSG(canon.S);
      if (CONTAINS(angle2time, canon)) {
        hms=angle2time[canon];
        MSG(hms);

        hms.PB(n);
        if (hms==need) {
          cout << need << endl;
          return;
        }
      }
    } while (next_permutation(ALL(ABC)));
    LINESEP1;
  }

  cout.flush(); cerr.flush();
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifndef MATHEMAGE_LOCAL
//   setIO(PROBLEMNAME);
#endif

  ll totalSec;
  REP(h,12) {
    REP(m,60) {
      REP(s,60) {
        totalSec=60*60*h + 60*m + s;

        ang[0]=totalSec * NANO_IN_SEC;          // hour hand
        ang[1]=12 * (60*m + s) * NANO_IN_SEC;   // min hand
        ang[2]=720 * s * NANO_IN_SEC;           // sec hand

        angle2time[getCanon(ang)]={h,m,s};
      }
    }
  }
  MSG(angle2time.size());

  int cases = 1;
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
