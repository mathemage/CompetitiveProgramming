/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : B.cpp
   * Creation Date : 19-04-2021
   * Last Modified : Mon 19 Apr 2021 03:53:09 AM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a3a5
   * Points/Time :
   * Total/ETA :
   * Status :
   * S AC TLE
   * S WA -
   * S WA -
   *
   *
   ==========================================*/

#define PROBLEMNAME "TASK_PLACEHOLDER_FOR_VIM"

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
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

template<typename T> 
ostream& operator<<(ostream& os, const set<T>& vec) { 
  os << "{ | ";
  for (const auto & x: vec) os << x << "| ";
  os << "}";
  return os; 
} 

template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& vec) {
  os << "{ | ";
  for (const auto & x: vec) os << x << "| ";
  os << "}";
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
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

const int CLEAN = -1;
// const int UNDEF = -42;
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

const ll UNDEF = -1e10;

void solve() {
  ll N; cin >> N;
  vector<ll> A(N);
  cin >> A;
  MSG(A);

  if (N==2) {
    cout << 2 << endl;
    return;
  }

  vector<ll> fwd(N);
  fwd[1]=2;
  FOR(i,2,N-1) {
    if (A[i]-A[i-1]==A[i-1]-A[i-2]) {
      fwd[i]=fwd[i-1]+1;
    } else {
      fwd[i]=2;
    }
  }
  MSG(fwd);

  vector<ll> bwd(N);
  bwd[N-2]=2;
  FORD(i,N-3,0) {
    if (A[i]-A[i+1]==A[i+1]-A[i+2]) {
      bwd[i]=bwd[i+1]+1;
    } else {
      bwd[i]=2;
    }
  }
  MSG(bwd);

  ll result=0;

  ll d;
  REP(i,N) {
//     ll fwdLen = i-1>=0 ? fwd[i-1] : 0;
    ll fwdLen = i-1>=0 ? fwd[i-1] : INF;
    ll fwdNeed=UNDEF;
    if (i-2>=0) {
      d=A[i-1]-A[i-2];
      fwdNeed=A[i-1]+d;
    }

//     ll bwdLen = i+1<N ? bwd[i+1] : 0;
    ll bwdLen = i+1<N ? bwd[i+1] : INF;
    ll bwdNeed=UNDEF;
    if (i+2<N) {
      d=A[i+2]-A[i+1];
      bwdNeed=A[i+1]-d;
    }

    if (fwdNeed==bwdNeed) {
      if (fwdNeed!=UNDEF && bwdNeed!=UNDEF) {
        MAXUPDATE(result,fwdLen+bwdLen+1);
      } else {
        MAXUPDATE(result,fwdLen+bwdLen-1);

        MSG(i); MSG(A[i]);
        MSG(fwdNeed); MSG(bwdNeed);
        MSG(fwdLen); MSG(bwdLen);
        MSG(result);
      }
    } else {
      if (fwdNeed!=UNDEF) {
        MAXUPDATE(result,fwdLen+1);
      }

      if (bwdNeed!=UNDEF) {
        MAXUPDATE(result,bwdLen+1);
      }
    }
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
