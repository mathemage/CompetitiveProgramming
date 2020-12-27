 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 27-12-2020

   * Last Modified : Ne 27. prosince 2020, 22:36:46

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1150/B

   * Points Gained (in case of online contest) : AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;

template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

int main() {
  int n;
  cin >> n;
  vector<string> board(n);
  REP(i,n) {
    cin >> board[i];
  }

//   vector<int> dx = {0, 0,  0, 1, -1};
//   vector<int> dy = {0, 1, -1, 0,  0};
  vector<pair<int, int>> dxy = {
    { 0, 0},
    { 0,-1},
    { 0, 1},
    {-1, 0},
    { 1, 0}
  };

  REP(row,n) {
    REP(col,n) {
      if (board[row][col] == '.') {
        for (auto & d : dxy) {
          int x = row + 1 + d.first;
          int y = col + d.second;
          if (0 <= x && x < n &&
              0 <= y && y < n &&
              board[x][y] == '.') {
            board[x][y] = '#';
          } else {
            cout << "NO\n";
            return 0;
          }
        }
      }
    }
  }
  cout << "YES\n";
  return 0;
}
