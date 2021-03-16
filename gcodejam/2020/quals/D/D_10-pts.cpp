 
/* ========================================
   * File Name : D_10-pts.cpp
   * Creation Date : 15-03-2021
   * Last Modified : Út 16. března 2021, 15:36:49
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
   * Points/Time :
   *  10m
   * +59m40s = 1h 9m40s
   * + 7m10s = 1h16m50s
   *
   * Total/ETA : 1h30m
   * Status :
   * WA test set 2
   *
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

// #define endl "\n"
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
  #define MSG_VEC(v) print_vector((v), (#v));
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2
#endif

template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
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

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const int OK_ECODE = 0;
const int WRONG_ANSWER_ECODE = -2;

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

int t, b;

void solve() {
  vector<int> result(b+2);  // +2 for reversal
  int p;
  int bit;

//   int n_queries = 150;
//   int n_queries = 10;
  int n_queries = b;
  REP(qi,n_queries) {
    MSG(qi);
    p = qi%b+1;

    cout << p << endl;
    cin >> bit;
    MSG(p) MSG(bit);

    result[p] = bit;
    LINESEP1;
  }

  FOR(bi,1,b) {
    cout << result[bi];
  }
  cout << endl;

  string response;
  cin >> response;
  if (response == "N") {
//     exit(WRONG_ANSWER_ECODE);
    exit(OK_ECODE);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t >> b;
  MSG(t); MSG(b);

  FOR(t_case,1,t) {
    MSG(t_case);
    solve();
    LINESEP2;
  }
  exit(OK_ECODE);
}
