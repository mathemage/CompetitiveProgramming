 
/* ========================================
   * File Name : C.cpp
   * Creation Date : 02-03-2021
   * Last Modified : Út 2. března 2021, 17:44:17
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1494/problem/C
   * Points/Time :
   * Total/ETA :
   * Status : unsubmitted
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
  cerr << name << ":\t";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

// direction vectors - 4 directions
const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
// direction vectors - 8 directions
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};


void solve() {
  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  int n_neg=0;
  for (auto & it: a) {
    cin >> it;
    if (it<0) {
      n_neg++;
    }
  }
  vector<int> aneg(n_neg);
  REP(i,n_neg) {
    aneg[n_neg-i-1]=a[i];
  }
  vector<int> apos(n-n_neg);
  FOR(i,n_neg,n-1) {
    apos[i-n_neg]=a[i];
  }
//   print_vector(a, "a");
//   print_vector(aneg, "aneg");
//   print_vector(apos, "apos");

  vector<int> b(m);
  n_neg=0;
  for (auto & it: b) {
    cin >> it;
    if (it<0) {
      n_neg++;
    }
  }
  vector<int> bneg(n_neg);
  REP(i,n_neg) {
    bneg[n_neg-i-1]=b[i];
  }
  vector<int> bpos(m-n_neg);
  FOR(i,n_neg,m-1) {
    bpos[i-n_neg]=b[i];
  }
//   print_vector(b, "b");
//   print_vector(bneg, "bneg");
//   print_vector(bpos, "bpos");

  long long result = 0LL;
  for (auto & dir: {-1,1}) {
    auto & box = dir<0 ? aneg: apos;
    auto & spec = dir<0 ? bneg: bpos;

    int si=0;
    for (si = 0; si < spec.size(); si += 1) {
      if (spec[si]>=box[0]) {
        break;
      }
    }

    for (int bi = 0; bi < box.size(); bi += 1) {
      int blen=bi+1;
      int slen=0;
      while ( (bi<box.size()-1 && spec[si]<box[bi+1]-1) || true) { // TODO
        slen++;
      }
    }
  }

  cout << result << endl;
  cerr << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}
