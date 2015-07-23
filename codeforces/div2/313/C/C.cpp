 
/* ========================================

   * File Name : C.cpp

   * Creation Date : 22-07-2015

   * Last Modified : Thu 23 Jul 2015 11:09:17 AM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/560/problem/C

   * Points Gained (in case of online contest) : 0 / 1500, RE

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
  int len = 1002;
  vector<int> triags(len);
  REP(i,len) {
    triags[i] = i ? (triags[i-1] + i + i-1) : 0;
  }

  vector<int> hex(6);
  REP(i,6) {
    cin >> hex[i];
  }
  cout << triags[ hex[0] + hex[1] + hex[2] ] 
          - triags[ hex[0] ] 
          - triags[ hex[2] ] 
          - triags[ hex[4] ] << endl;
  return 0;
}
