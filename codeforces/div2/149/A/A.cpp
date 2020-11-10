 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 10-11-2020

   * Last Modified : Út 10. listopadu 2020, 00:51:33

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/149/A

   * Points Gained (in case of online contest) : WA on #36 - AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;

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
  int k;
  cin >> k;
  vector<int> a(12);
  REP(i,12) {
    cin >> a[i];
  }

  sort(ALL(a));
  reverse(ALL(a));

  int growth = 0;
  int i = 0;
  while (i < 12 && growth < k) {
    growth += a[i++];
  }

  cout << (growth >= k ? i : -1) << endl;
  return 0;
}
