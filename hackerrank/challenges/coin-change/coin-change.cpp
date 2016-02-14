 
/* ========================================

   * File Name : coin-change.cpp

   * Creation Date : 14-02-2016

   * Last Modified : Sun 14 Feb 2016 04:09:02 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.hackerrank.com/challenges/coin-change

   * Status : WA, AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
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

// #define DEBUG
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  REP(i,m) {
    cin >> c[i];
  }

  vector<long long> dp(n+1, 0);
  dp[0] = 1;
#ifdef DEBUG
  for (auto & x : dp) {
    cout << x << " ";
  }
  cout << endl << endl;
#endif

  for (auto & d : c) {
    for (int k = n; k > 0; k--) {
      for (int x = k - d; x >= 0; x -= d) {
        dp[k] += dp[x];
      }
    }

#ifdef DEBUG
    ERR(d);
    for (auto & x : dp) {
      cout << x << " ";
    }
    cout << endl << endl;
#endif
  }
  cout << dp[n] << endl;
  return 0;
}
