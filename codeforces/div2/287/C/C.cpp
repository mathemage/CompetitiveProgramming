/* ========================================

   ID: mathema6
   TASK: C
   LANG: C++11
   (...for USACO solutions)

   * File Name : C.cpp

   * Creation Date : 23-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/507/problem/C

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
void err(vector<string>::iterator it) {
  cout << endl;
}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

int main() {
  int h;
  unsigned long long res=0,n;
  bool l = true;

  cin >> h >> n;
  while (h > 0) {
    if (l && n > (1LL<<h>>1)) {
      res += (1LL<<h);
      n -= (1LL<<h>>1);
    } else if (l && n <= (1LL<<h>>1)) {
      res++;
      l = false;
    } else if (!l && n <=(1LL<<h>>1)) {
      res += (1LL<<h);
    } else if (!l && n > (1LL<<h>>1)) {
      res++;
      n -= (1LL<<h>>1);
      l = true;
    }
    h--;
  }

  cout << res << endl;
  return 0;
}
