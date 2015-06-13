 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 12-06-2015

   * Last Modified : Sat 13 Jun 2015 04:29:09 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/551/problem/A

   * Points Gained (in case of online contest) : 0/500 (WA)

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

  vector<int> k(2015, 0);
  vector<int> a(n);
  REP(i,n) {
    cin >> a[i];
    k[a[i]]++;
  }

  int ac = 0;
  FOR(i, 2000, 0) {
    int l = k[i];
    k[i] = 1 + ac;
    ac += l;
  }

  for (auto & x : a) {
    cout << k[x] << " ";
  }
  return 0;
}
