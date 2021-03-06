 
/* ========================================
   * File Name : C.cpp
   * Creation Date : 08-03-2021
   * Last Modified : Út 9. března 2021, 21:45:28
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
   * Points/Time : 
   * 25m40s+
   * Total/ETA : 7+12=19pts
   * Status :
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

  cerr << endl;
//   print_vector_pairs(se, "se");
//   sort(ALL(se), [](auto & a, auto & b) { return a.S < b.S; } );
  sort(ALL(se), [](pair<int, int> & a, pair<int, int> & b) { return a.S < b.S; } );
  print_vector_pairs(se, "se");

  vector<char> result(n);
  result[id[se[0]]]='C';
  vector<int> indices_J;
  FOR(i,1,n-1) {
    if (se[i-1].S <= se[i].F) {
      result[id[se[i]]]= 'C';
    } else {
      result[id[se[i]]]= 'J';
      indices_J.PB(i);
    }
  }

  print_vector(indices_J, "indices_J");
  for (int i = 1; i < indices_J.size(); i += 1) {
    vector<pair<int, int>> v1={ se[indices_J[i-1]] };
    print_vector_pairs(v1, "se[indices_J[i-1]]");
    vector<pair<int, int>> v2={ se[indices_J[i]] };
    print_vector_pairs(v2, "se[indices_J[i]]");

    if (se[indices_J[i-1]].S > se[indices_J[i]].F) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  for (auto & it: result) {
    cout << it;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  REP(i,cases) {
//     cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
