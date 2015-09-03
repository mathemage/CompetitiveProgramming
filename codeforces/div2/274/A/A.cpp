 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 03-09-2015

   * Last Modified : Thu 03 Sep 2015 03:26:12 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/479/A

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
  int a,b,c;
  cin >> a >> b >> c;
  int res = 0;

  res = max(res, (a+b)+ c);
  res = max(res, (a*b)+ c);
  res = max(res, (a+b)* c);
  res = max(res, (a*b)* c);

  swap(a,c);

  res = max(res, (a+b)+ c);
  res = max(res, (a*b)+ c);
  res = max(res, (a+b)* c);
  res = max(res, (a*b)* c);

  cout << res << endl;
  return 0;
}
