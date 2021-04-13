/* ========================================
   * File Name : 1.cpp
   * Creation Date : 02-04-2021
   * Last Modified : Mon 12 Apr 2021 12:27:36 AM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem&cpid=1119
   * Points/Time :
   *  37m
   * + 4m    ~   41m
   * +26m10s ~ 1h07m10s
   *
   * Total/ETA : 10m
   * Status : 
   * (reading OJ's tests)
   *  3/17 WAs :-/
   *  2/17 WAs :-O
   *  AC !!!! Yesssssss!!!!
   *
   ==========================================*/

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


void solve() {
  int N,L;
  cin >> N >> L;
  vector<int> c(N);
  for (auto & ci: c) {
    cin >> ci;
  }
  MSG(N) MSG(L) MSG(c.size()); MSG(c); LINESEP1;

  sort(REVALL(c));
  MSG("reversed");
  cerr.flush(); cout.flush(); MSG(c.size()); MSG(c); LINESEP1;

  int h = 0LL;
  FOR(i,1,N) {
    if (c[i-1]>=i) {
      h++;
      MSG(i); MSG(c[i-1]); MSG(h); LINESEP1;
    } else {
      break;
    }
  }
  MSG(h); LINESEP1;

//   while (L-- && h<N) {
//     c[h]++;
//     h++;
//   }
  reverse(ALL(c));
  for (auto & ci: c) {
    if (L && ci>=h) {
      ci++;
      if (--L==0) {
        break;
      }
    }
  }
  sort(REVALL(c));
  MSG(c);

  h = 0LL;
  FOR(i,1,N) {
    if (c[i-1]>=i) {
      h++;
      MSG(i); MSG(c[i-1]); MSG(h); LINESEP1;
    } else {
      break;
    }
  }
  MSG(c); LINESEP1;

  cout << h << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}