 
/* ========================================
   * File Name : upvotes_via_brute_force_v2.cpp
   * Creation Date : 04-02-2021
   * Last Modified : Čt 4. února 2021, 23:35:32
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/upvotes
   * Points/Time : 5m
   * Total/ETA : 7m
   * Status : same git diff
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

const int CLEAN = -1;
const int UNDEF = INT_MAX;
const int INF = INT_MAX;


void solve_via_brute_force() {
  int N, K;
  cin >> N >> K;

  vector<int> upvotes(N);
  vector<int> signs(N, UNDEF);
  REP(i,N) {
    cin >> upvotes[i];
  }

  for (int win_start=0, win_end=win_start+K-1 ; win_end < N; win_start++, win_end++) {
//     cerr << endl << endl; MSG(win_start); MSG(win_end);
    long long result = 0LL;
    FO(start,win_start,win_end) FO(end,start+1,win_end) {
      bool is_inc = true, is_dec = true;
      FO(i,start+1,end) {
        is_inc &= upvotes[i-1]<=upvotes[i];
        is_dec &= upvotes[i-1]>=upvotes[i];
      }

      if (is_inc) { result++; }
      if (is_dec) { result--; }
//       cerr << endl; MSG(start); MSG(end); MSG(result);
    }
    cout << result << endl;
  }
}

int main() {
  int cases = 1;
  while (cases--) {
    solve_via_brute_force();
  }
  return 0;
}
