/* ========================================

   ID: mathema6
   TASK: dualpal
   LANG: C++11

   * File Name : dualpal.cxx

   * Creation Date : 08-02-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://train.usaco.org/usacoprob2?a=N4ep8CnrqTE&S=dualpal
   
   * Duration : 17 min

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

bool isPalindrome(string s) {
  string rs = s;
  reverse(ALL(rs));
  return s == rs;
}

bool ok(int k) {
  int ways = 0;
  string repr;
  int n;
  FOR(b,2,11) {
    repr = "";
    n = k;
    while (n) {
      repr += ('0' + n%b);
      n /= b;
    }

    if (isPalindrome(repr) && ++ways > 1)
      return true;
  }
  return false;
}

int main() {
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");
  int n, s;
  fin >> n >> s;
  int k = s;
  while (n--) {
    while (!ok(++k));
    fout << k << endl;
  }

  return 0;
}
