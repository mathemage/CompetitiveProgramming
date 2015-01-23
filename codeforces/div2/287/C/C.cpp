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
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

int h,n;
long long res=0;
bool l = true;

long long solve() {
  if (h == 0) {
    return res;
  }

  if (l && n > (1L<<h>>1)) {
    res += (1L<<h);
    n -= (1L<<h>>1);
  } else if (l && n <= (1L<<h>>1)) {
    res++;
    l = false;
  } else if (!l && n <=(1L<<h>>1)) {
    res += (1L<<h);
  } else if (!l && n > (1L<<h>>1)) {
    res++;
    n -= (1L<<h>>1);
    l = true;
  }
  h--;

  return solve();
}

int main() {
  cin >> h >> n;
  cout << solve() << endl;
  return 0;
}
