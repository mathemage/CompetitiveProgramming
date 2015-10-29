 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 29-10-2015

   * Last Modified : Thu 29 Oct 2015 01:51:56 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/469/A

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
  int n, p, q, k;
  cin >> n;
  vector<int> lvl(n+1, 0);
  cin >> p;
  REP(i,p) {
    cin >> k;
    lvl[k] = 1;
  }
  cin >> q;
  REP(i,q) {
    cin >> k;
    lvl[k] = 1;
  }

  if (accumulate( lvl.begin(),  lvl.end(), 0) == n) {
    cout << "I become the guy.";
  } else {
    cout << "Oh, my keyboard!";
  }
  cout << endl;
  return 0;
}
