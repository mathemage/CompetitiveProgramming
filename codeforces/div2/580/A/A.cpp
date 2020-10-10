 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 10-10-2020

   * Last Modified : So 10. října 2020, 21:48:48

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/580/A

   * Points Gained (in case of online contest) : WA (#9) - AC

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
  int n;
  cin >> n;
//   MSG(n);

  vector<int> a(n);
  int cur_len, max_len = 0;
  REP(i,n) {
    cin >> a[i];
//     MSG(a[i]);

    if (i > 0 && a[i] >= a[i - 1]) {
      cur_len++;
    } else {
      cur_len = 1;
    }
    max_len = max(max_len, cur_len);
  }

  cout << max_len;

  return 0;
}
