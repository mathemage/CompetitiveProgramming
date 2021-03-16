 
/* ========================================
   * File Name : D.cpp
   * Creation Date : 16-03-2021
   * Last Modified : Út 16. března 2021, 20:39:23
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
   * Points/Time :
   *  42m30s
   * +25m00s = 1h 7m30s
   * +10m50s = 1h18m20s
   *
   * Total/ETA : 1h15m
   * Status : 
   * WA test set 2
   * RE test set 2 (INVALID_BIT_ECODE)
   * AC !!!!!!!!!!!!!!!!!!!!!!!!!
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

const int MAX_QUERIES = 150;
const int UNSET_BIT = -1;

const int OK_ECODE = 0;
const int WRONG_ANSWER_ECODE = -2;
const int TOO_MANY_QUERIES_ECODE = -3;
const int INVALID_BIT_ECODE = -4;

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
int qi;

inline int ask(int p) {
  cout << p << endl;
  qi++; MSG(qi);

  int bit;
  cin >> bit;
  return bit;
}

void solve() {
  vector<int> result(b+2, UNSET_BIT);  // +2 for reversal
  int bit;

  int pLeft=1, pRight=b;
  int pComplementation=UNDEF, pReversal=UNDEF;
  const int pDummy=1;

  qi=1;
  while (pLeft <= pRight) {
    MSG_VEC(result);

    if (qi > MAX_QUERIES) {
//       exit(TOO_MANY_QUERIES_ECODE);
      exit(OK_ECODE);
    }
    
    if (qi%10==1 && qi>10) {
      // check for complementation
      if (pComplementation!=UNDEF) {
        bit = ask(pComplementation);
        if (bit==1-result[pComplementation]) {   // complement if needed
          FOR(bi,1,b) {
            if (result[bi]==0 || result[bi]==1) {
              result[bi]=1-result[bi];
            }
          }
        }
      }

      // check for reversal
      if (pReversal!=UNDEF) {
        bit = ask(pReversal);
        if (bit==1-result[pReversal]) {   // reverse if needed
          reverse(ALL(result));
        }
      }

      while (qi%10 <= 2) {
        bit = ask(pDummy);
      }
    }

    // ask about pLeft
    result[pLeft] = ask(pLeft);
    // ask about pRight
    result[pRight] = ask(pRight);
    // compare pLeft and pRight => update pComplementation
    if (pComplementation==UNDEF && result[pLeft]==result[pRight]) {
      pComplementation=pLeft;
      MSG(pComplementation);
    }
    // compare pLeft and pRight => update pReversal
    if (pReversal==UNDEF && result[pLeft]==1-result[pRight]) {
      pReversal=pLeft;
      MSG(pReversal);
    }

    pLeft++, pRight--;
    MSG_VEC(result);
    LINESEP1;
  }

  FOR(bi,1,b) {
    if (result[bi]!=0 && result[bi]!=1) {
      LINESEP1; MSG(result[bi]);
      exit(INVALID_BIT_ECODE);
//       exit(OK_ECODE);
    }
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
