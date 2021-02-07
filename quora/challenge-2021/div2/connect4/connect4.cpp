 
/* ========================================
   * File Name : connect4.cpp
   * Creation Date : 07-02-2021
   * Last Modified : Ne 7. února 2021, 03:10:57
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points/Time :
   * - 27m 10s
   * - 52m 40s
   *  
   * Total/ETA : 35m
   * Status :
   * -  76/100 (Output isn't correct)
   * - 100/100 :-) ^_^
   *
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


void show_grid(const vector<string> & grid) {
  for (auto & line: grid) {
    for (auto & c: line) {
      cerr << c;
    }
    cerr << endl;
  }
}

void solve() {
  string result = "DRAW";
  int winning_move = UNDEF;
  vector<int> heights(7,0);
  vector<string> grid(6, "_______");
//   show_grid(grid);

  int col,row,rr,cc;
  FO(move,1,42) {
    cin >> col;
    col--;
    row = heights[col]++;
    grid[row][col] = move%2?'R':'Y';

    if (result != "DRAW") {
      continue;
    }

    REP(di,8) {
      int streaks=0;

      rr = row;
      cc = col;
      while (0<=rr && rr<6 && 0<=cc && cc<7 && grid[rr][cc] == grid[row][col]) {
        streaks++;
        rr += DX8[di];
        cc += DY8[di];
      } 

      rr = row;
      cc = col;
      while (0<=rr && rr<6 && 0<=cc && cc<7 && grid[rr][cc] == grid[row][col]) {
        streaks++;
        rr -= DX8[di];
        cc -= DY8[di];
      } 
      streaks--;  // row, col counted twice

      if (streaks >= 4) {
        winning_move = move;
        result = move%2?"RED":"YELLOW";
//         show_grid(grid); cerr << endl;
        break;
      }
    }
  }

  cout << result;
  if (result != "DRAW") {
    cout << " " << winning_move;
  }
  cout << endl;
}

int main() {
  int cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
