 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 27-08-2015

   * Last Modified : Thu 27 Aug 2015 11:43:54 AM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/208/A

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
  string s, res;
  cin >> s;
  for (int i = 0; i <  s.size(); ++i) {
    if (i + 2 < s.size() && s.substr(i,3) == "WUB") {
      i += 2;
      if (res.size() && res.back() != ' ') {
        res += ' ';
      }
    } else {
      res += s[i];
    }
  }

  cout << res.substr(0, 1 + res.find_last_not_of(' '));
  return 0;
}
