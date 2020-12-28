 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 28-12-2020

   * Last Modified : Po 28. prosince 2020, 17:10:50

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://codeforces.com/contest/1469/problem/0

   * Points Gained (in case of online contest) : WA (#2) - WA (#2) - AC

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

// bool solve(string s) {
//   int i = 0;
// 
//   int pre = 0;
//   while (s[i] != '(') {
//     if (s[i] == '?') {
//       pre++;
//     } 
//     if (s[i] == ')') {
//       return false;
//     } 
//     i++;
//   }
// 
//   int mid = 0;
//   while (s[i] != ')') {
//     if (s[i] == '?') {
//       mid++;
//     } 
//     i++;
//   }
// 
//   int post = 0;
//   while (i < s.size()) {
//     if (s[i] == '?') {
//       post++;
//     } 
//     i++;
//   }
// 
//   return (mid % 2 == 0 && (pre + post) % 2 == 0);
// }

// bool solve(string s) {
//   int i = 0;
//   while (s[i] != '(') {
//     if (s[i] == ')') {
//       return false;
//     } 
//     i++;
//   }
// 
//   return s.size() % 2 == 0;
// }

bool solve(string s) {
  return s[0] != ')' && s[s.size()-1] != '(' && s.size() % 2 == 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << (solve(s) ? "yes" : "no") << '\n';
  }
  return 0;
}
