 
/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : A.testset1.cpp
   * Creation Date : 05-04-2021
   * Last Modified : Út 6. dubna 2021, 20:30:50
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034
   * Points/Time : 
   * ~36m
   * +  1m10s = 37m10s
   * + 10m30s = 47m40s
   * +    40s = 48m20s
   * +  1m30s = 49m50s
   *
   * Total/ETA : 50m
   * Status :
   * S AC AC WA (i.e. AC TS1 & TS2)
   * S AC AC WA (i.e. AC TS1 & TS2)
   * S AC AC WA (i.e. AC TS1 & TS2)
   * S AC AC RE (i.e. AC TS1 & TS2)
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
  int N;
  cin >> N;

  vector<string> P(N);
  REP(i,N) {
    cin >> P[i];
  }
//   MSG(P);

  sort(ALL(P), [](auto & a, auto & b) { return a.size() > b.size(); } );
//   MSG(P);

  vector<string> result(2);
  for (auto & Pi: P) {
    MSG(Pi);
    stringstream ss(Pi);
    string token;

    vector<string> part;
    while (getline(ss, token, '*')) {
        part.PB(token);
    }

    MSG(part.size());
    if (SZ(part)==1) {
      part.PB("");
    }
    reverse(ALL(part.back()));
    MSG(part);

    for (int i: {0,SZ(part)-1}) {
      REP(pos,max(SZ(result[i]), SZ(part[i]))) {
        if (pos>=SZ(result[i])) {
          result[i]+=part[i][pos];
          continue;
        } else if (pos>=SZ(part[i])) {
          break;
        } else if (result[i][pos]!=part[i][pos]) {
          cout << '*' << endl;
          return;
        }
      }
    }
    MSG(result);
    LINESEP1;
  }

  reverse(ALL(result[1]));
  cout << result[0]+result[1] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  cin >> cases;
  REP(i,cases) {
    cout << "Case #" << i+1 << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
