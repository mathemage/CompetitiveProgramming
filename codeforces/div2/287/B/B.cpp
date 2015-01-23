/* ========================================

   ID: mathema6
   TASK: B
   LANG: C++11
   (...for USACO solutions)

   * File Name : B.cpp

   * Creation Date : 23-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/507/problem/B

   * Points Gained (in case of online contest) : 792 / 1000

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
  int r,x,y,x2,y2;
  cin >> r >> x >> y >> x2 >> y2;
  double d = sqrt(pow(x2-x,2) + pow(y2-y,2));
  cout << ceil(d / (2*r));
  return 0;
}
