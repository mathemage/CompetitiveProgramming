 
/* ========================================

   * File Name : D.cpp

   * Creation Date : 30-12-2020

   * Last Modified : St 30. prosince 2020, 18:30:49

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/contest/1466/problem/D

   * Points Gained (in case of online contest) : AC pretests

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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;

    vector<pair<int, int>> w(n);
    int i = 0;
    long long sum = 0;
    for (auto & wi : w) {
      cin >> wi.first;
      sum += wi.first;
      wi.second = ++i;
    }
    sort(w.rbegin(),w.rend());
//     sort(ALL(w), bool [](auto &left, auto &right) { return left.second < right.second; });
//     for (auto & wi : w) {
//       MSG(wi.first); MSG(wi.second);
//     }

    vector<int> deg(n+5,0);
    int u,v;
    REP(i,n-1) {
      cin >> u >> v;
      deg[u]++;
      deg[v]++;
    }

    cout << sum << ' ';
    for (auto & wi : w) {
      while (--deg[wi.second]) {
        sum += wi.first;
        cout << sum << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
