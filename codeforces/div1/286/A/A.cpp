/* ========================================

   ID: mathema6
   TASK: A
   LANG: C++11
   (...for USACO solutions)

   * File Name : A.cpp

   * Creation Date : 18-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/506/problem/A

   * Points Gained (in case of online contest) : 0, unsubmitted

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
  cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

#define sz 30001
int n,d,p,fin;
vector<int> plan;
int cache[sz][sz];
int jump(int cur, int l) {
  int res = 0;
  if (l > 0 && cur < fin) {
    if (cache[cur][l-1] == -1) {
      cache[cur][l-1] = jump(cur+l-1,l-1);
    }
    res = max(res,cache[cur][l-1]);

    if (cache[cur][l] == -1) {
      cache[cur][l] = jump(cur+l,l);
    }
    res = max(res,cache[cur][l]);

    if (cache[cur][l+1] == -1) {
      cache[cur][l+1] = jump(cur+l+1,l+1);
    }
    res = max(res,cache[cur][l+1]);
  }
  return plan[cur] + res;
}

int main() {
  REP(i,sz) REP(j,sz) cache[i][j] = -1;

  cin >> n >> d;
  plan.assign(n,0);
  fin = d;
  REP(i,n) {
    cin >> p;
    plan[p]++;
    fin = max(fin,p);
  }
  cout << jump(d,d);
  return 0;
}
