/* ========================================

   ID: mathema6
   TASK: palsquare
   LANG: C++11

   * File Name : palsquare.cxx

   * Creation Date : 06-02-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://train.usaco.org/usacoprob2?a=DyYidey3bpn&S=palsquare

   * Duration : 7 min 20 s

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

const string digits = "0123456789ABCDEFGHI";

string convert(int n, int b) {
  string res;
  while (n) {
    res += digits[n%b];
    n /= b;
  }
  return res;
}

int main() {
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");
  int b;
  fin >> b;

  string rev, sq, num;
  REP(i,300) {
    sq = rev = convert((i+1)*(i+1), b);
    reverse(ALL(sq));
    if (sq == rev) {
      num = convert(i+1, b);
      reverse(ALL(num));
      fout << num << " " << sq << endl;
    }
  }
  return 0;
}
