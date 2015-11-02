 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 02-11-2015

   * Last Modified : Mon 02 Nov 2015 02:31:08 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/459/A

   * Points Gained (in case of online contest) : AC

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
  vector<int> x(5);
  vector<int> y(5);
  cin >> x[1] >> y[1] >> x[2] >> y[2];

  if (x[1] == x[2]) {
    int d = abs(y[1] - y[2]);
    cout << x[1] + d << " " << y[1] << " ";
    cout << x[2] + d << " " << y[2];
  } else if (y[1] == y[2]) {
    int d = abs(x[1] - x[2]);
    cout << x[1] << " " << y[1] + d << " ";
    cout << x[2] << " " << y[2] + d;
  } else {
    int dx = abs(x[1] - x[2]);
    int dy = abs(y[1] - y[2]);
    if (dx != dy) {
      cout << "-1";
    } else {
      cout << x[1] << " " << y[2] << " " << x[2] << " " << y[1];
    }
  }


  cout << endl;
  return 0;
}
