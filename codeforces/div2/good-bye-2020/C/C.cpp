 
/* ========================================

   * File Name : C.cpp

   * Creation Date : 30-12-2020

   * Last Modified : St 30. prosince 2020, 17:10:36

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/contest/1466/problem/C

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

int solve(string & s) {
  int ans = 0;
  int n = s.size();
  REP(start,n) {
    for (auto & dpos : {1,2}) {
      int end = start + dpos;
      if (end < n && s[start] == s[end]) {  // a palindrome
        unordered_set<char> forbidden;
        for (auto & offset : {-2,-1,0,1,2}) {
          forbidden.insert(s[end+offset]);
        }
        FOR(c,'a','z') {
          if (forbidden.find(c) == forbidden.end()) {
            s[end] = c;
            break;
          }
        }
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    cout << solve(s) << '\n';
  }
  return 0;
}
