/* ========================================

   ID: mathema6
   TASK: 25
   LANG: C++11
   (...for USACO solutions)

   * File Name : 25.cpp

   * Creation Date : 22-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=620734011349888&round=544142832342014

   * Duration : 2 hours, unverified

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
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
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

//#define DEB

int main() {
  int t,n,m;
  int x1,a1,b1,c1,r1;
  int x2,a2,b2,c2,r2;
  cin >> t;
  REP(i,t) {
    unsigned long long res = 0;
    cin >> n >> m;
    cin >> x1 >> a1 >> b1 >> c1 >> r1;
    cin >> x2 >> a2 >> b2 >> c2 >> r2;

    vector<int> board[2];
    board[0].resize(n);
    board[1].resize(m);
    board[0][0] = x1;
    board[1][0] = x2;
    FOR(j,1,max(n,m)) {
      if (j < n)
        board[0][j] = (a1 * board[0][(j-1) % n] + b1 * board[1][(j-1) % m] + c1) % r1;
      if (j < m)
        board[1][j] = (a2 * board[0][(j-1) % n] + b2 * board[1][(j-1) % m] + c2) % r2;
    }
#ifdef DEB
    REP(k,2) {
      printf("board %d: ", k);
      for (auto & x : board[k]) {
        cout << x << " ";
      }
      cout << endl;
    }
#endif

    unordered_set<int> seen[2];
    queue<int> missing[2];
    int cur = 0, oth = 1;
    int pos[2] = {0, 0};
    int tofind, x;
    int cnt[2] = {1, 1};

    while (cnt[0] * cnt[1] > 0) {
      if (pos[cur] < board[cur].size()) {
        seen[cur].insert(board[cur][pos[cur]]);
        missing[oth].push(board[cur][pos[cur]]);
      }

      while (missing[cur].size() + missing[oth].size() > 0) {
        while (missing[oth].size()) {
          tofind = missing[oth].front(); missing[oth].pop();
          //ERR(tofind);
          if (seen[oth].find(tofind) == seen[oth].end()) {
            while (pos[oth] < board[oth].size()) {
              x = board[oth][pos[oth]];
              if (seen[oth].find(x) == seen[oth].end()) {
                seen[oth].insert(x);
                if (seen[cur].find(x) == seen[cur].end())
                  missing[cur].push(x);
              }
              //ERR(oth,pos[oth],x);
              pos[oth]++;
              if (x == tofind) {
                if (missing[oth].empty()) pos[oth]--;
                break;
              }
            }
            //ERR(cur,missing[cur].size()); ERR(oth,missing[oth].size());
          }
        }
        if (pos[oth] == missing[oth].size()) break;
        swap(cur, oth);
      }

      //cout << "##########\n"; ERR(cur,pos[cur]); ERR(oth,pos[oth]);

      REP(k,2) {
        cnt[k] = (pos[k] < board[k].size()) ? 1 : 0;
        while (++pos[k] < board[k].size()
            && seen[k].find(board[k][pos[k]]) != seen[k].end()) {
          cnt[k]++;
        }
      }
      res += cnt[0] * cnt[1];
      //ERR(res); cout << endl;
    }

    printf("Case #%d: %llu\n", i+1, res);
  }
  return 0;
}
