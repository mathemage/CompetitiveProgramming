 
/* ========================================
   * File Name : C.cpp
   * Creation Date : 09-03-2021
   * Last Modified : Pá 12. března 2021, 16:55:52
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
   * Points/Time : 
   * 1h10m10s
   *  + 3m    =1h13m10s
   *  + 6m50s =1h20m00s
   *  + 5m
   *  + 4m50s =1h29m50s
   *  +16m30s =1h46m20s
   *  + 1m50s =1h48m10s
   *  +10m50s =1h59m00s
   *
   * Total/ETA : 7+12=19pts
   * Status :
   * WA test set 2
   * WA test set 2
   * read editorial
   * WA test set 2
   * WA test set 2
   * WA test set 2
   * read 2 other solution -> WA test set 2
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

#define MSG(a) cerr << "> " << #a << ": " << (a) << endl;
template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

template<typename T>
void print_vector_pairs(const vector<pair<T, T>> & vec, const string & name) {
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
  int n;
  cin >> n;
  vector<pair<int, int>> se(n);
  map<pair<int, int>, int> id;
  REP(i,n) {
    cin >> se[i].F >> se[i].S;
    id[se[i]] = i;
  }

//   cerr << endl;
  sort(ALL(se), [](auto & a, auto & b) { return a.F < b.F; } );
//   print_vector_pairs(se, "se (1st sort)");
//   sort(ALL(se));
//   print_vector_pairs(se, "se (2nd sort)");

  string result(n,'_');
//   print_vector(result, "result"); cerr << endl;

  int C_finish=UNDEF;
  int J_finish=UNDEF;
  for (auto & slot: se) {
    if (C_finish <= slot.F) {
      result[id[slot]]= 'C';
      C_finish=slot.S;
    } else if (J_finish <= slot.F) {
      result[id[slot]]= 'J';
      J_finish=slot.S;
    } else {
      cout << "IMPOSSIBLE";
      return;
    }
//     print_vector(result, "result"); cerr << endl;
  }

  cout << result;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); // TODO
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  REP(i,cases) {
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
