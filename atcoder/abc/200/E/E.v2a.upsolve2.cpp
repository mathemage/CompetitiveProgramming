 
/* ========================================

   ID: mathema6
   TASK: E
   LANG: C++14

   * File Name : E.cpp
   * Creation Date : 08-05-2021
   * Last Modified : Mon 10 May 2021 08:59:55 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://atcoder.jp/contests/abc200/tasks/abc200_e
   * Points/Time :
   * +36m :-(
   * +
   *
   * Total/ETA : 500
   * [upsolve] ~9m
   * [upsolve v2] ~35m
   *
   * Status :
   * unsubmitted
   * [upsolve]
   *
   *
   ==========================================*/

#define PROBLEMNAME "E"

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
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.F << ", " << p.S << ")"; }

template<typename T>
istream& operator>>(istream& is, vector<T> & vec) { for (auto & x: vec) is >> x; return is; }

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) { return min(l,u)<=x && x<max(l,u); }

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

ll N,K; 

inline ll TP(ll r) {
//   MSG(r); MSG(N);
//   LINESEP1;

  if (2<=r && r<=2*N) {
//     MSG(min(N,r-1));
//     MSG(max(1LL,r-N));
//     MSG(min(N,r-1) - max(1LL,r-N));
//     LINESEP1;
#ifdef MATHEMAGE_DEBUG
    assert(min(N,r-1) - max(1LL,r-N) + 1LL >= 0);
#endif

    return min(N,r-1) - max(1LL,r-N) + 1LL;
  } else {
    return 0;
  }
}

void solve() {
  cin >> N >> K;
  MSG(N); MSG(K); LINESEP1;

#ifdef MATHEMAGE_DEBUG
//   cerr << TP(-1) << endl;
//   cerr << TP(0) << endl;
//   cerr << TP(1) << endl;
//   cerr << TP(2) << endl;
//   cerr << TP(3) << endl;
//   cerr << TP(4) << endl;
//   cerr << TP(5) << endl;

//   MSG(TP(-1));
//   MSG(TP(0));
//   MSG(TP(1));
//   MSG(TP(2));
//   MSG(TP(3));
//   MSG(TP(4));
//   MSG(TP(5));
//   LINESEP1;
#endif

  ll cnt;

  cnt=TP(2);
//   MSG(cnt); LINESEP1; LINESEP1;
  assert(TP(2)==1);

  ll S=UNDEF;
  FOR(s,3,3*N) {
//     MSG(s); MSG(cnt); MSG(K); LINESEP1;

    if (cnt<K) {
      K-=cnt;
    } else {
      S=s;
      break;
    }

    cnt-=TP(s-N);
    cnt+=TP(s);
  }
  MSG(S); MSG(K); LINESEP1;
  assert(S!=UNDEF);

  // TODO re-implement below
  assert(false);

  ll B=UNDEF; ll T=UNDEF; ll P=UNDEF;
  MSG(S-2); MSG(min(N,S-2)); LINESEP1;
  FOR(b,1,min(N,S-2)) {
    ll remaining=S-b;
    ll lower = max(1LL, remaining-N);
    ll upper = min(N, remaining-1LL);
    cnt=upper-lower+1LL;
    MSG(b); MSG(cnt); LINESEP1;

    if (cnt<K) {
      K-=cnt;
    } else {
      B=b;
      T=lower+K-1;
      break;
    }
  }
  P=S-B-T;

  cout << B << " " << T << " " << P << endl;
  cout.flush();

  assert(1<=B); assert(1<=T); assert(1<=P);
  assert(B<=N); assert(T<=N); assert(P<=N);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

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
