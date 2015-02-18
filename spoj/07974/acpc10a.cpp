/* ========================================

   * File Name : acpc10a.cpp

   * Creation Date : 18-02-2015

   * Last Modified : Wed 18 Feb 2015 05:18:02 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/ACPC10A/

   * Duration : 10 min

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
  int x,y,z,d;
  while (1) {
    cin >> x >> y >> z;
    if (!x && !y && !z) return 0;
    d = y-x;
    if (z == y+d) {
      cout << "AP " << z+d << endl;
    } else {
      cout << "GP " << z*z/y << endl;
    }
  }
  return 0;
}
