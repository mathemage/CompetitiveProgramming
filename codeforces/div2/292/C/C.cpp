/* ========================================

   * File Name : C.cpp

   * Creation Date : 17-02-2015

   * Last Modified : Tue 17 Feb 2015 08:40:00 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/515/problem/C

   * Points Gained (in case of online contest) : 652 / 1000

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
  vector<vector<int> > pf {
    {}, {},
    {2},
    {3},
    {2,2},
    {5},
    {2,3},
    {7},
    {2,2,2},
    {3,3}
  };

  int n;
  cin >> n;
  char d;
  vector<int> cnt(10,0);
  REP(i,n) {
    cin >> d;
    REP(j,d-'0'+1) {
      for (auto & x : pf[j]) {
        cnt[x]++;
      }
    }
  }

  for (auto & k : {7,5,3,2}) {
    while (cnt[k]) {
      cout << k;
      REP(i,k+1) {
        for (auto & x : pf[i]) {
          cnt[x]--;
        }
      }
    }
  }

  return 0;
}
