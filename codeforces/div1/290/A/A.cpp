/* ========================================

   * File Name : A.cpp

   * Creation Date : 02-02-2015

   * Last Modified : Thu 05 Feb 2015 11:21:16 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/512/problem/A

   * Points Gained (in case of online contest) : AC

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
  int n;
  cin >> n;
  vector<string> names(n);
  REP(i,n) {
    cin >> names[i];
  }

  // get edges
  vector<string> ed(26);
  vector<int> indeg(26, 0);
  REP(i,n-1) {
    REP(k,names[i].size()) {
      if (k >= names[i+1].size()) {
        cout << "Impossible" << endl;
        return 0;
      }
      if (names[i][k] != names[i+1][k]) {
        ed[names[i][k]-'a'] += names[i+1][k];
        indeg[names[i+1][k]-'a']++;
        break;
      }
    }
  }

  // tsort
  queue<int> q;
  string res;
  REP(i,26) {
    if (indeg[i] == 0) q.push(i);
  }
  vector<bool> done(26, false);
  vector<bool> touched(26, false);
  while (q.size()) {
    int cur = q.front(); q.pop();
    if (!done[cur]) {
      res += (cur + 'a');
      touched[cur] = done[cur] = true;
    }
    for (auto & x : ed[cur]) {
      int i = x-'a';
      if (--indeg[i]==0 && !touched[i]) {
        q.push(i);
        touched[i] = true;
      }
    }
  }

  if (res.size() == 26) cout << res;
  else cout << "Impossible";
  cout << endl;

  return 0;
}
