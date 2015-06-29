 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 29-06-2015

   * Last Modified : Mon 29 Jun 2015 04:32:59 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/problemset/problem/144/A

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
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) {
    cin >> a[i];
  }
  int ma = *max_element(ALL(a));
  int mi = *min_element(ALL(a));

  int cur = 0, secs = 0;
  while (a[cur] != ma) {
    cur++;
  }
  while (--cur >= 0) {
    swap(a[cur], a[cur+1]);
    secs++;
  }

  cur = n-1;
  while (a[cur] != mi) {
    cur--;
  }
  while (++cur <= n-1) {
    swap(a[cur], a[cur-1]);
    secs++;
  }
  cout << secs << endl;
  return 0;
}
