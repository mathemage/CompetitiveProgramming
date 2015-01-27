/* ========================================

   * File Name : B.cpp

   * Creation Date : 27-01-2015

   * Last Modified : Tue 27 Jan 2015 09:16:18 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/508/problem/B

   * Points Gained (in case of online contest) : 750 / 1000

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
  string n;
  cin >> n;
  int sz = n.size(), pos = sz, pos2 = -1;
  char & d = n[sz-1];
  REP(i,sz) {
    if ((n[i]-'0') % 2 == 0) {
      if (n[i] < d) pos = min(pos,i);
      else pos2 = max(pos2, i);
    }
  }
  if (pos == sz) pos = pos2;

  if (pos == -1) n = "-1";
  else swap(d, n[pos]);
  cout << n << endl;

  return 0;
}
