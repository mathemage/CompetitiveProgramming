 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 21-11-2020

   * Last Modified : So 21. listopadu 2020, 22:35:33

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/problemset/problem/1324/A

   * Points Gained (in case of online contest) : AC

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

bool solve(const vector<int> & a) {
  int req_parity = *min_element(ALL(a)) % 2;
  for (auto & ai: a) {
    if (ai % 2 != req_parity) {
      return false;
    }
  }
  return true;
}

bool solve2(const vector<int> & a) {
  int sum = 0;
  for (auto & ai: a) {
    sum += ai % 2;
  }
  return sum % a.size() == 0;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    REP(i,n) {
      cin >> a[i];
    }

//     cout << (solve(a) ? "YES" : "NO") << endl;
    cout << (solve2(a) ? "YES" : "NO") << endl;
  }
  return 0;
}
