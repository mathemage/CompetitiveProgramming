/* ========================================

   * File Name : A.cpp

   * Creation Date : 27-01-2015

   * Last Modified : Tue 27 Jan 2015 09:16:51 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/508/problem/A

   * Points Gained (in case of online contest) : 470 / 500

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

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
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

int main() {
  int n,m,k,i,j;
  cin >> n >> m >> k;
  int res = 0;
  vector<vector<bool>> board(n);
  REP(a,n) board[a].assign(m,false);

  REP(t,k) {
    cin >> i >> j;
    board[--i][--j] = true;
    if (i > 0 && board[i-1][j]) {
      if (j > 0 && board[i-1][j-1] && board[i][j-1]) {
        res = t+1;
        break;
      }
      if (j < m-1 && board[i-1][j+1] && board[i][j+1]) {
        res = t+1;
        break;
      }
    }
    if (i < n-1 && board[i+1][j]) {
      if (j > 0 && board[i+1][j-1] && board[i][j-1]) {
        res = t+1;
        break;
      }
      if (j < m-1 && board[i+1][j+1] && board[i][j+1]) {
        res = t+1;
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
