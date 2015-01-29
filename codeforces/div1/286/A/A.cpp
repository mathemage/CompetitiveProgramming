/* ========================================

   * File Name : A.cpp

   * Creation Date : 29-01-2015

   * Last Modified : Thu 29 Jan 2015 11:33:41 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/506/problem/A

   * Points Gained (in case of online contest) : 0, unsubmitted, AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

int main() {
  const int sz = 30001;
  const int wdth = 491;

  int n,d,p,m=0;
  cin >> n >> d;
  vector<int> plan(sz);
  REP(i,n) {
    cin >> p;
    plan[p]++;
    m = max(m, p);
  }
  vector<vector<int>> dp(m+d+wdth/2+2, vector<int>(wdth,0));
  int off = d - wdth / 2;

  rep(i,m+1,d) rep(j,max(off,1),d+wdth/2+1) {
    dp[i][j-off] = plan[i]
             + max( (j>1 ? dp[i+j-1][j-1-off] : 0) , max(dp[i+j][j-off] , dp[i+j+1][j+1-off]) );
  }
  cout << dp[d][wdth/2];

  return 0;
}
