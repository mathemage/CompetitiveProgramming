 
/* ========================================

   * File Name : C.cpp

   * Creation Date : 13-08-2015

   * Last Modified : Sat 15 Aug 2015 07:03:06 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/570/problem/C

   * Points Gained (in case of online contest) : 0 / 1500 (not submitted)

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

//#define DEBUG

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  int f = 0;
  REP(i,n-1) {
    if (s[i] == '.' && s[i+1] == '.') {
      f++;
    }
  }
#ifdef DEBUG
  ERR(f); cout << endl;
#endif

  int i;
  char c;
  REP(j,m) {
    cin >> i;
    i--;
    cin >> c;

    if (s[i] != '.' && c == '.') {
      if (i > 0 && s[i-1] == '.') {
        f++;
      }
      if (i < n-1 && s[i+1] == '.') {
        f++;
      }
    }

    if (s[i] == '.' && c != '.') {
      if (i > 0 && s[i-1] == '.') {
        f--;
      }
      if (i < n-1 && s[i+1] == '.') {
        f--;
      }
    }

#ifdef DEBUG
    ERR(s);
#endif
    s[i] = c;
    cout << f << endl;
#ifdef DEBUG
    ERR(s); ERR(f); cout << endl;
#endif
  }
  return 0;
}
