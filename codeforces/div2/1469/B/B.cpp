 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 28-12-2020

   * Last Modified : Po 28. prosince 2020, 17:37:21

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/contest/1469/problem/B

   * Points Gained (in case of online contest) : not submitted

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

    vector<vector<int>> dp(n+1);
    REP(i,n+1) {
      dp.resize(m,0);

      FOR(j,1,n+1) {
        dp[0][j] = dp[0][j-1] + r[j-1];
      }
      FOR(i,1,m+1) {
        dp[i][0] = dp[i-1][0] + b[i-1];
      }
    }

    REP(i,n+1) {
      REP(j,m+1) {
        dp[i][j] = max(dp[
      }
    }
  }
  return 0;
}
