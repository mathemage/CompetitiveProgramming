/* ========================================
   * File Name : D.cpp
   * Creation Date : 27-03-2021
   * Last Modified : Sat 27 Mar 2021 08:29:30 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
   * Points/Time :
   * 1h49m
   *
   * Total/ETA : 7+11+10 pts ~1h
   * Status :
   * AC (Test Set 1&2, 3 is ?)
   * AC all (3 is AC, too!!)
   * <- (only) 2001 participants (5%) solved 3 test sets
   * - see screenshot
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

const int OK_ECODE = 0;
const int WRONG_ANSWER_ECODE = 1;
const int TOO_MANY_QUERIES_ECODE = 2;
const int INVALID_ECODE = 3;
const int INVALID_RANGE_ECODE = 4;
const int NSEGMENTS_ECODE = 5;
const int LR_ECODE = 6;

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

int t,n,q;
int qi;
int median;

inline int ask(int i, int j, int k) {
  LINESEP1; MSG(i) MSG(j) MSG(k);
  for (auto & idx: {i,j,k}) {
    if (!(1<=idx && idx<=n)) {
      MSG(idx);
      exit(INVALID_RANGE_ECODE);
  //     exit(OK_ECODE);
    }
  }
  cout << i << " " << j << " " << k << endl;

  int response;
  cin >> response;
  qi++;
  MSG(qi); MSG(response); LINESEP1;

  if (response == -1) {
    exit(INVALID_ECODE);
//     exit(OK_ECODE);
  }
  return response;
}

void solve() {
  vector<int> result = {-INF, INF};
  MSG(result);

  median = ask(1,2,3);
  for (auto & x: {1,2,3}) {
    if (x!=median) {
      result.insert(result.end()-1, x);
    }
  }
  result.insert(result.begin()+2, median);
  MSG(result);

  int i,j;
  FOR(k,4,n) {
    if (qi > q) {
      exit(TOO_MANY_QUERIES_ECODE);
//       exit(OK_ECODE);
    }

//     MSG(result);
//     MSG(k); 

    int l=0,r=SZ(result)-1;
    while (l+1<r) {
      MSG(l); MSG(r);
      int nSegments=r-l;
      if (nSegments==2) {
        if (r==SZ(result)-1) {
          i=l, j=r-1;
        } else {
          i=l+1, j=r;
        }
      } else if (nSegments>=3) {
        int third=nSegments/3;
        i=l+third, j=r-third;
      } else {
        exit(NSEGMENTS_ECODE);
//       exit(OK_ECODE);
      }
//       median = ask(i,j,k);
      int a=result[i], b=result[j];
      median = ask(a,b,k);

      if (median==a) { // 1) -> left third
        r=i;
      }
      if (median==k) { // 2) -> mid third
        l=i, r=j;
      }
      if (median==b) { // 3) -> right third
        l=j;
      }
      LINESEP1;
    }
    
    if (r!=l+1) {
      MSG(k); MSG(l); MSG(r);
      exit(LR_ECODE);
//       exit(OK_ECODE);
    }
    result.insert(result.begin()+r, k);
    MSG(result);
    LINESEP1;
  }

  result.erase(result.begin()); // -INF
  result.pop_back();            // INF
  cout << result << endl;

  int response;
  cin >> response;
  if (response == -1) {
    exit(WRONG_ANSWER_ECODE);
//     exit(OK_ECODE);
  } else {
    MSG("Passed testcase!");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> t >> n >> q;
  qi=0;
  FOR(t_case,1,t) {
    MSG(t_case);
    solve();
    LINESEP2;
  }
  return 0;
}
