 
/* ========================================
   * File Name : upvotes_via_dp.cpp
   * Creation Date : 04-02-2021
   * Last Modified : Čt 4. února 2021, 15:44:57
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/upvotes/problem
   * Points/Time :
   * Total/ETA : 1h 15m
   * Status :
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

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


void print_vector(vector<long long> vec, string name) {
  cerr << name << ": ";
  for (auto & x: vec) {
    cerr << x << "  ";
  }
  cerr << endl;
}

void solve() {
  int N,K;
  cin >> N >> K;
  vector<int> upvotes(N);
  REP(i,N) {
    cin >> upvotes[i];
  }

  vector<long long> counts_inc(N,0LL);
  vector<long long> counts_dec(N,0LL);
  FOR(i,1,N) {
    if (upvotes[i-1]<=upvotes[i]) {
      counts_inc[i] = counts_inc[i-1]+1;
    }
    if (upvotes[i-1]>=upvotes[i]) {
      counts_dec[i] = counts_dec[i-1]+1;
    }
  }

  /* DEBUG */
  print_vector(counts_inc, "counts_inc");
  print_vector(counts_dec, "counts_dec");
  /*********/

  long long balance = 0LL;
  cout << balance << endl;
}

int main() {
  int cases;
  cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
