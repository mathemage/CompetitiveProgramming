/* ========================================
   * File Name : 2.cpp
   * Creation Date : 02-04-2021
   * Last Modified : Fri 02 Apr 2021 07:51:43 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem&cpid=1120
   * Points/Time :
   * Total/ETA :
   * Status : unsubmitted (unsolved, <30min left)
   ==========================================*/

#include <algorithm>
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
//   os << endl;
//   for (const auto & s: vec) cerr << s << endl;
  for (const auto & s: vec) cerr << s << "\t";
  return os;
}

ostream& operator<<(ostream& os, const vector<vector<string>> & vec) {
//   os << endl;
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
  long long K,N;
  cin >> K >> N;

  string name;
  vector<string> names(N);
  map<string,int> id;
  FOR(i,1,N) {
    cin >> name;
    names.PB(name);
    id[name]=i-1;
  }
  MSG(names);

  vector<vector<string>> Klist(K);
  REP(i,K) {
    REP(j,N) {
      cin >> name;
      Klist[i].PB(name);
    }
    MSG(i); MSG(Klist[i]);
  }

  vector<string> result(N);
  REP(r,N) {
    result[r].assign(N,'?');
    result[r][r]='B';
  }


  REP(k,K) {
    LINESEP1;
    MSG(k);

    FOR(a,0,N-1) {
      MSG(a);

      FOR(b,a+1,N-1) {
        MSG(b);

        if (Klist[k][a] > Klist[k][b]) {
          int idA = id[Klist[k][a]];
          int idB = id[Klist[k][b]];

          result[idB][idA]='1';
          result[idA][idB]='0';
        }
      }
    }
  }

  REP(r,N) {
    cout << result[r] << endl;
  }
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
