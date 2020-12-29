 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 28-12-2020

   * Last Modified : St 30. prosince 2020, 00:23:46

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/contest/1469/problem/B

   * Points Gained (in case of online contest) : not submitted - AC

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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    vector<int> r(n);
    REP(j,n) {
      cin >> r[j];
    }

    cin >> m;
    vector<int> b(m);
    REP(i,m) {
      cin >> b[i];
    }

    int max_f = 0;

    int n_rows = 1 + n;
    int n_cols = 1 + m;
    vector<vector<int>> dp(n_rows);
    REP(row,n_rows) {
//       MSG(row);
      dp[row].resize(n_cols);
      if (row == 0) {
        dp[0][0] = 0;
        FOR(col,1,n_cols) {
          dp[0][col] = dp[0][col-1] + b[col-1]; 
          max_f = max(max_f, dp[0][col]);
        }
      } else {
        dp[row][0] = dp[row-1][0] + r[row-1]; 
        max_f = max(max_f, dp[row][0]);

        FOR(col,1,n_cols) {
          dp[row][col] = max(dp[row-1][col] + r[row-1], dp[row][col-1] + b[col-1]);
          max_f = max(max_f, dp[row][col]);
        }
      }
    }
    cout << max_f << '\n';
  }
  return 0;
}
