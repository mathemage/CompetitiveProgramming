 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 29-08-2015

   * Last Modified : Mon 31 Aug 2015 04:54:38 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/574/problem/A

   * Points Gained (in case of online contest) : 0 / 500 (WA, AC)

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
  REP(ni,n) {
    cin >> a[ni];
  }

  int limak = a[0];
  int budget = 0;

  while (true) {
    FOR(ni,1,n) {
      if (a[ni] >= limak) {
        budget -= a[ni] - (limak - 1);
      }
      if (budget < 0) {
        break;
      }
    }

    if (budget >= 0) {
      cout << limak - a[0] << endl;
      return 0;
    } else {
      limak++;
      budget = limak - a[0];
    }
  }
}
