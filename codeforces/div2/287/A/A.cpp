/* ========================================

   ID: mathema6
   TASK: A
   LANG: C++11
   (...for USACO solutions)

   * File Name : A.cpp

   * Creation Date : 23-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/507/problem/A

   * Points Gained (in case of online contest) : 425 / 500

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
  int n,k,x;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  REP(i,n) {
    cin >> x;
    a[i] = {x,i+1};
  }
  sort(ALL(a));
  int res = n, sum = 0;
  REP(i,n) {
    sum += a[i].first; 
    if (sum > k) {
      res = i;
      break;
    }
  }

  cout << res << endl;
  REP(i,res) {
    cout << a[i].second << " ";
  }
  return 0;
}
