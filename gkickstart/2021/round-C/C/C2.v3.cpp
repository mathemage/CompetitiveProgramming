/* ========================================

   ID: mathema6
   TASK: C2
   LANG: C++14

   * File Name : C2.cpp
   * Creation Date : 31-05-2021
   * Last Modified : Mon 31 May 2021 01:06:35 AM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ec28e
   * Points/Time :
   * [upsolve v1]
   *     = 32m
   * +0m = 32m
   * +5m = 40m
   *
   * Total/ETA : 8+8+13 pts
   * [upsolve v1] ~1h
   *
   * Status :
   * S AC WA - !!
   * S AC WA - :-/
   * S WA -  - :-(
   * S AC WA - :-/
   * S WA -  - :-(
   * S WA -  - :-/
   * S WA -  - :-/
   * S WA -  - :-(
   * [Practice mode]
   * S WA -  - :-( <- wouldn't work in-contest anyway! ^_^
   *
   * [upsolve v1]
   * S TLE - - :-/
   * S WA  - - :-O
   * S WA  - - :-(
   *
   ==========================================*/

#include <memory>
#include <random>
#define PROBLEMNAME "C2"

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
#define PB push_back
#define MP make_pair
#define MTP make_tuple
// #define MINUPDATE(A,B) A = min((A), (B));
// #define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((int) (x).size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define YN(b) cout << ((b)?"YES":"NO") << endl;

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
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& vec) { for (const auto & x: vec) os << x.F << ":" << x.S << " | "; return os; }

template<typename T1, typename T2> 
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.F << ", " << p.S << ")"; }

template<typename T>
istream& operator>>(istream& is, vector<T> & vec) { for (auto & x: vec) is >> x; return is; }

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) { return min(l,u)<=x && x<max(l,u); }

template<class T> bool umin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

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

const string RPS="RPS";
unordered_map<char, char> counter;

inline double payOff(string moves, double W, double E) {
  double ans=0.0;

  unordered_map<char, double> cnt;
  for (int i = 0; i < SZ(moves); i += 1) {
//     LINESEP1; MSG(i); MSG(moves[i]);

    for (char ch: RPS) {
      double prob = i ? cnt[ch] / ((double)i) : 1.0/3.0;

      if (ch==moves[i]) {
        ans += prob * E;
      } else if (ch==counter[moves[i]]) {
        ans += prob * W;
      }
    }

    cnt[moves[i]]++;
//     MSG(cnt); MSG(ans);
  }

  return ans;
}

void solve() {
  ll X; cin >> X;
  double W,E; cin >> W >> E;
//   MSG(payOff("RSRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR", W, E)); LINESEP1;

  string result;

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  const int nSamples=1e3;
//   const int nSamples=1e4;
//   const int nSamples=1e5;
//   const int nSamples=1e6;

  double bestPayoff=-1.0;
  REP(_,nSamples) {
    unordered_map<char, double> cnt;

    string trial="R";
    cnt['R']++;
    FOR(i,2,60) {     // sample round
      std::discrete_distribution<int> distrib{cnt['R'], cnt['P'], cnt['S']};
      int sampledIdx=distrib(gen);
      char choice=RPS[sampledIdx];
      char move=counter[choice];

      trial+=move;
      cnt[move]++;
    }
    if ( umax(bestPayoff, payOff(trial, W, E)) ) { result=trial; }

    string random="R";
    cnt['R']++;
    FOR(i,2,60) {     // sample round
      std::uniform_int_distribution<> distrib(0, 2);
      int sampledIdx=distrib(gen);
      char choice=RPS[sampledIdx];
      char move=counter[choice];

      random+=move;
      cnt[move]++;
    }
    if ( umax(bestPayoff, payOff(trial, W, E)) ) { result=random; }
  }
  MSG(bestPayoff);

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifndef MATHEMAGE_LOCAL
//   setIO(PROBLEMNAME);
#endif

  counter['R']='P';
  counter['P']='S';
  counter['S']='R';

  int cases = 1;
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
