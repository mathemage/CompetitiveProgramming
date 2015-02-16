/* ========================================

   * File Name : nsquare2.cpp

   * Creation Date : 13-02-2015

   * Last Modified : Mon 16 Feb 2015 06:30:02 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/NSQUARE2/

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()

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
  vector<int> n(q);
  vector<int> a(q);
  REP(i,q) {
    cin >> n[i] >> a[i];
  }

  int m = *max_element(ALL(a)) + 1;
  vector<int> heads(m, 0);
  vector<int> cnt(m, 100000);
  cnt[0] = 0;
  // DP
  FOR(k,1,m) {
    for (int i = 1; i * i <= k; ++i) {
      int tail = k - i * i;
      if (cnt[tail] < cnt[k]) {
        cnt[k] = cnt[tail];
        heads[k] = i;
      }
    }
    cnt[k]++;
  }

  REP(i,q) {
    if (n[i] >= cnt[a[i]]) {
      REP(j, cnt[a[i]] - n[i]) {
        cout << "0 ";
      }
      while (a[i]) {
        cout << heads[a[i]] << " ";
        a[i] -= heads[a[i]] * heads[a[i]];
      }
    } else {
      cout << "Impossible";
    }
    cout << endl;
  }

  return 0;
}
