/* ========================================

   * File Name : D1.cpp

   * Creation Date : 07-02-2015

   * Last Modified : Sat 07 Feb 2015 09:23:25 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/513/problem/D1

   * Points Gained (in case of online contest) : unsubmitted

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
  int n, c, a, b;
  string s;
  cin >> n >> c;
  vector<pair<int, int> > lc, rc;
  REP(i,c) {
    cin >> a >> b >> s;
    if (a >= b) {
      cout << "IMPOSSIBLE";
      return 0;
    }

    a--; b--;
    if (s == "LEFT") {
      lc.emplace_back(pair<int, int> {a,b});
    } else {
      rc.emplace_back(pair<int, int> {a,b});
    }
  }
  sort(ALL(lc));
  sort(ALL(rc));

  const int nan = -1;

  vector<int> min_desc(n);
  FOR(i,n,0) {
    min_desc[i] = i;
    for (auto & x : lc) {
      if (x.first == i) min_desc[i] = x.second;
      if (x.first >= i) break;
    }

    if (min_desc[i] == i) {
      for (auto & x : rc) {
        if (x.first == i) min_desc[i] = x.second;
        if (x.first >= i) break;
      }
    }

    min_desc[i] = min(min_desc[i], min_desc[min_desc[i]]);
  }

  reverse(ALL(lc));
  reverse(ALL(rc));

  vector<int> max_desc(n);
  FOR(i,n,0) {
    max_desc[i] = i;
    for (auto & x : rc) {
      if (x.first == i) max_desc[i] = x.second;
      if (x.first <= i) break;
    }

    if (max_desc[i] == i) {
      for (auto & x : lc) {
        if (x.first == i) max_desc[i] = x.second;
        if (x.first <= i) break;
      }
    }

    max_desc[i] = max(max_desc[i], max_desc[max_desc[i]]);
  }

  /*
  cout << "min_desc: ";
  for (auto & x : min_desc) {
    cout << x << " ";
  }
  cout << endl;
  cout << "max_desc: ";
  for (auto & x : max_desc) {
    cout << x << " ";
  }
  cout << endl;  */

  vector<vector<int> > ls(n);
  for (auto & x : lc) {
    ls[x.first].emplace_back(x.second);
  }
  vector<vector<int> > rs(n);
  for (auto & x : rc) {
    rs[x.first].emplace_back(x.second);
  }

  REP(i,n) {
    if (rs[i].size() && ls[i].size()
        && max_desc[ls[i][0]] >= min_desc[rs[i].back()] ) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }

  vector<int> lson(n,nan);
  vector<int> rson(n,nan);

  stack<int> st;
  st.push(i);
  while (st.size()) {
    int cur = st.top(); st.pop();
    if (ls[cur].empty()) {
      rson[cur] = cur+1;
      st.push(rson[cur]);
    } else {
      lson[cur] = cur+1;
      rson[cur] = max_desc[ls[cur][0]] + 1;
      st.push(rson[cur]);
      st.push(lson[cur]);
    }
  }

  st.push(0);
  while (st.size()) {
    int cur = st.top(); st.pop();
    cout << lson[cur] << " ";
    cout << cur << " ";
    cout << rson[cur] << " ";
  }
  return 0;
}
