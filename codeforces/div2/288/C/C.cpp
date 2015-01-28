/* ========================================

   * File Name : C.cpp

   * Creation Date : 28-01-2015

   * Last Modified : Wed 28 Jan 2015 07:44:54 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/508/problem/C

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
  int m,t,r,res=0;
  cin >> m >> t >> r;
  if (t < r) {
    cout << -1 << endl;
    return 0;
  }

  vector<short> w(m);
  vector<short> cnt(m,r);
  REP(i,m) {
    cin >> w[i];
  }
  REP(i,m) {
    int offset = t-1;
    while (cnt[i]) {
      cnt[i]--;
      res++;
      FOR(j,i+1,m) {
        if (w[j] <= w[i] + offset) cnt[j]--;
        else break;
      }
      offset--;
    }
  }

  cout << res << endl;
  return 0;
}
