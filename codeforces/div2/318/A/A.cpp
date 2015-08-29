 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 29-08-2015

   * Last Modified : Sat 29 Aug 2015 08:57:22 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/574/problem/A

   * Points Gained (in case of online contest) : 0 / 500 (WA)

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
  int n, limak, x=0, cnt=1;
  cin >> n;
  vector<int> a(n);
  REP(ni,n) {
    cin >> a[ni];
  }
  limak = a[0];

  vector<int> d(n);
  ERR(cnt, x);
  REP(ni,n) {
    d[ni] = a[ni] - limak + 1;
    if (ni && a[ni] >= limak) {
      cnt++;
      x += d[ni];
      ERR(ni, a[ni], cnt, x, d[ni]); cout << endl;
    }
  }
  int s = (x + cnt - 1) / cnt;
  ERR(s);

  vector<int> delta(n);
  while (true) {
    int tot = 0;
    REP(ni,n) {
      if (a[ni] >= limak) {
        delta[ni] = d[ni] - s;
        tot += delta[ni];
      }
    }
    
    if (tot <= s) {
      cout << s << endl;
      break;
    }
    s++;
  }
  return 0;
}
