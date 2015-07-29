 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 30-06-2015

   * Last Modified : Wed 01 Jul 2015 02:49:46 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/557/problem/0

   * Points Gained (in case of online contest) : 474 / 500, AC

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
  vector<int> mi(3);
  vector<int> ma(3);
  vector<int> res(3);
  REP(i,3) {
    cin >> mi[i] >> ma[i];
    res[i] = mi[i];
    n -= res[i];
  }

  REP(i,3) {
    if (n == 0) {
      break;
    }

    int d = min(n, ma[i] - res[i]);
    n -= d;
    res[i] += d;
  }

  REP(i,3) {
    cout << res[i] << " ";
  }
  return 0;
}