 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 27-06-2015

   * Last Modified : Mon 29 Jun 2015 11:13:45 AM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/556/problem/B

   * Points Gained (in case of online contest) : 216 / 250, AC on #1

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> o(n,0);
  REP(i,n) {
    cin >> a[i];
    while (a[i] != i) {
      a[i] += (i % 2 == 0) ? 1 : -1;
      a[i] += n;
      a[i] %= n;
      o[i]++;
    }
  }
  for (auto & x : o) {
    if (x != o[0]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
