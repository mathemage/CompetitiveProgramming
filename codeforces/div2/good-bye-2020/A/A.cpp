 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 30-12-2020

   * Last Modified : St 30. prosince 2020, 15:52:28

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/contest/1466/problem/0

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
    vector<int> x(n);
    for (auto & xi : x) {
      cin >> xi;
    }

    vector<bool> dist(55,false);
    int n_dist = 0;
    REP(i,n) {
      FOR(j,i+1,n) {
        int d = x[j] - x[i];
        if (!dist[d]) {
          dist[d] = true;
          n_dist++;
        }
      }
    }

    cout << n_dist << '\n';
  }
  return 0;
}
