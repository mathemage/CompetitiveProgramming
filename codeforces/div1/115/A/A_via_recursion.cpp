 
/* ========================================

   * File Name : A_via_recursion.cpp

   * Creation Date : 18-11-2020

   * Last Modified : St 18. listopadu 2020, 23:31:36

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/115/A

   * Points Gained (in case of online contest) : AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -1;

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

vector<int> d, p;
// vector<int> p;

int get_depth(int i) {
  if (d[i] == UNDEF) {
    d[i] = (p[i] == -1) ? 1 : 1 + get_depth(p[i] - 1);
  }
//   MSG(d[i]);
  return d[i];
}

int main() {
  int n;
  cin >> n;

  p.resize(n);
  REP(i,n) { cin >> p[i]; }

//   for (auto & x: p) { cout << x << " "; } cout << endl;

  d.resize(n, UNDEF);
  REP(i,n) {
//     MSG(i); MSG(p[i]); 
    d[i] = get_depth(i);
  }

//   for (auto & x: d) { cout << x << " "; } cout << endl;
  cout << *max_element(ALL(d));

  return 0;
}
