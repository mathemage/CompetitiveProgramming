 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 22-07-2015

   * Last Modified : Thu 23 Jul 2015 11:08:26 AM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/560/problem/B

   * Points Gained (in case of online contest) : 0 / 1000, WA

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
  int len = 4;
  vector<int> a(len);
  vector<int> b(len);
  FOR(i,1,4) {
    cin >> a[i] >> b[i];
  }

  REP(i,2) {
    REP(j,2) {
      int x1 = a[2];
      int y1 = b[2];
      int x2 = a[1] - a[3] + 1;
      int y2 = b[1] - b[3] + 1;

      if (!(x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0)) {
        continue;
      }
      if (!(x1 <= a[1] && x2 <= a[1] && y1 <= b[1] && y2 <= b[1])) {
        continue;
      }
      if (!(x2 <= x1 && y2 <= y1)) {
        cout << "YES\n";
        //ERR(x1, x2, y1, y2); cout << endl;
        //ERR(a[2], b[2], a[3], b[3]); cout << endl;
        return 0;
      }

      swap(a[3], b[3]);
    }
    swap(a[2], b[2]);
  }
  cout << "NO\n";
  return 0;
}
