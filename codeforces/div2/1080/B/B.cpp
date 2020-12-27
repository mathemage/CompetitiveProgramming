 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 25-12-2020

   * Last Modified : Pá 25. prosince 2020, 22:53:54

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1080/B

   * Points Gained (in case of online contest) : AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << (a) << endl;

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
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    long long ans = l % 2 ? 1 : -1;
    long long dist = r-l+1;
//     MSG(l); MSG(r); MSG(dist);  MSG(ans);
    ans *= dist / 2;
//     MSG(ans);
    ans += (dist % 2) * r * (r % 2 ? -1 : 1);
//     MSG(ans);

    cout << ans << endl;
//     cerr << endl;
  }
  return 0;
}
