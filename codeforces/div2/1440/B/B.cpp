 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 27-11-2020

   * Last Modified : Pá 27. listopadu 2020, 00:47:46

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1440/B

   * Points Gained (in case of online contest) : WA (#2) - AC

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
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n * k);
    REP(i,n*k) {
      cin >> a[i];
    }

    unsigned long long sum = 0;
    int median_pos = a.size() - n / 2;
    REP(j,k) {
//       MSG(median_pos); MSG(a[median_pos - 1]); MSG(n / 2 + 1);
      sum += a[median_pos - 1];
      median_pos -= n / 2 + 1;
    }

    cout << sum << endl;
  }
  return 0;
}
