/* ========================================

   ID: mathema6
   TASK: 25-winning
   LANG: C++11
   (...for USACO solutions)

   * File Name : 25-winning.cpp

   * Creation Date : 17-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

/* 
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
  cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
} */

#define sz 2001
unsigned long ways[sz][sz-1];

int main() {
  const int mod = 1000000007;

  REP(x,sz) ways[x][0] = 1;
  REP(y,sz-1) ways[0][y] = 1;
  FOR(y,1,sz-1) FOR(x,1,sz) {
    if (x == y) {
      ways[x][y] = ways[x-1][y];
    } else if (x == y+1) {
      ways[x][y] = ways[x][y-1];
    } else {
      ways[x][y] = ways[x-1][y] + ways[x][y-1];
    }
    ways[x][y] %= mod;
  }

  int t,a,b;
  cin >> t;
  REP(i,t) {
    scanf("%d-%d", &a, &b);
    printf("Case #%d: %lu %lu\n", i+1, ways[a][b], ways[b][b]);
  }
  return 0;
}
