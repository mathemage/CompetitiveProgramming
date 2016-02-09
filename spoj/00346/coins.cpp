/* ========================================

   * File Name : coins.cpp

   * Creation Date : 09-02-2016

   * Last Modified : Wed 10 Feb 2016 12:47:56 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/COINS/

   * Status : WA, WA, RE, AC

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

long long limit = 1000000000 / 8;
vector<long long> dp(limit+1);

long long solve(long long n) {
  if (n <= limit) {
    return dp[n];
  } else {
    return max(n, solve(n/2) + solve(n/3) + solve(n/4));
  }
}

int main() {
  dp[0] = 0;
  for (long long n = 1; n <= limit; n++) {
    dp[n] = max(n, dp[n/2] + dp[n/3] + dp[n/4]);
  }

  vector<long long> results;
  while (true) {
    int n;
    cin >> n;
    if (cin.eof()) {
      break;
    }
    results.emplace_back(solve(n));
  }
  for (int i = 0; i < results.size(); ++i) {
    cout << results[i];
    if (i < results.size() - 1) {
      cout << endl;
    }
  }
  return 0;
}
