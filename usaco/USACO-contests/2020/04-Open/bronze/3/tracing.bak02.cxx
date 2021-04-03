/* ========================================

   ID: mathema6
   TASK: tracing
   LANG: C++14

   * File Name : tracing.cxx
   * Creation Date : 01-04-2021
   * Last Modified : Thu 01 Apr 2021 11:06:32 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem2&cpid=1037
   * Points/Time :
   *    18m40s
   * +1h24m20s = 1h43m00s
   * +  10m40s = 1h53m40s
   * +   1m40s = 1h55m20s
   * +   9m    = 2h04m20s
   *
   * Total/ETA :
   * Status :
   * 13/16 WAs :-/
   * 12/16 WAs :-/
   *
   ==========================================*/

#include <string>
#define PROBLEMNAME "tracing"

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
  for (const auto & s: vec) cerr << s << endl;
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
ostream& operator<<(ostream& os, const set<T>& vec) { 
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
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

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


#ifndef MATHEMAGE_LOCAL
void setIO(string filename) {    // the argument is the filename without the extension
	freopen((filename+".in").c_str(), "r", stdin);
	freopen((filename+".out").c_str(), "w", stdout);
  MSG(filename);
}
#endif

void solve() {
  int N,T;
  cin >> N >> T;

  int len=1+N;
  vector<bool> infected(len);
  set<int> candidateZeroes;
  char ch;
  FOR(i,1,N) {
    cin >> ch;
    infected[i]=ch=='1';
    if (infected[i]) { candidateZeroes.insert(i); }
  }

  int t,x,y;
  map<int, pair<int, int>> shakes;
  REP(i,T) {
    cin >> t >> x >> y;
    shakes[t] = MP(x,y);
  }

  int Kmin=0, Kmax=INF;

  int last,oth;
  set<int> trueZeroes;
  MSG(candidateZeroes); LINESEP1;
  for (auto & zero: candidateZeroes) {           // brute force over all possible patient "zero"
    MSG(zero); LINESEP1;
    if (infected[zero]) {
      MSG(infected[zero]); LINESEP1;

      bool canBeZero=false;
      FOR(K,Kmin,min(Kmax, 300)) {
        MSG(K); MSG(Kmin); MSG(Kmax); LINESEP1;
        set<int> spread;
        vector<int> nShakes(len);

        int lastInfected=zero;
        spread.insert(zero);

        int candidateKmax=Kmax;
        for (auto & shake: shakes) {
          t=shake.F, x=shake.S.F, y=shake.S.S;
          MSG(t); MSG(x); MSG(y); LINESEP1;
          nShakes[x]++, nShakes[y]++;

          if (CONTAINS(spread,x) && !infected[y]) {
            if (nShakes[x]<=K) {  // impossible => x would have infected y
              break;
            } else {
              MINUPDATE(candidateKmax, nShakes[x]-1);
            }
          }
          if (CONTAINS(spread,y) && !infected[x]) {
            if (nShakes[y]<=K) {  // impossible <= y would have infected x
              break;
            } else {
              MINUPDATE(candidateKmax, nShakes[y]-1);
            }
          }

          if (x==lastInfected) { last=x, oth=y; }
          else if (y==lastInfected) { last=y, oth=x; }
          else continue;

          if (infected[oth] && !CONTAINS(spread,oth)) {
            if (nShakes[last]<=K) {
              lastInfected=oth; spread.insert(oth);
            } else {    // K is not sufficient
              break;
            }
          }
        }

        MSG(spread); LINESEP1;
        if (spread==candidateZeroes) { // "zero" is a viable patient zero
          canBeZero=true;

          MAXUPDATE(Kmin,K);
          MINUPDATE(Kmax,candidateKmax);
          break;
        }
      }

      if (canBeZero) { trueZeroes.insert(zero); }
    }
    MSG(trueZeroes); LINESEP1;
  }
  MSG(Kmin); MSG(Kmax); LINESEP1;

  cout << trueZeroes.size() << " "
       << Kmin << " "
       << (Kmax==INF?"Infinity":to_string(Kmax)) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifndef MATHEMAGE_LOCAL
  setIO(PROBLEMNAME);
#endif

  int cases = 1;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}
