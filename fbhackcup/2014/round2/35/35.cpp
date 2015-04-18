/* ========================================

   ID: mathema6
   TASK: 35
   LANG: C++11
   (...for USACO solutions)

   * File Name : 35.cpp

   * Creation Date : 24-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

   * Points Gained (in case of online contest) :

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

int t,n,h,c1,c2;

unsigned long long strength(pair<int, int> c) {
  int a=c.first, b=c.second, s=a+b;
  int m[3];
  int d[3];
  vector<bool> used(n);
  used[a-1] = used[b-1] = true;

  unsigned long long total = 0;
  for (d[0] = 1; d[0] <= n; d[0]++) {
    if (used[d[0]-1]) continue;
    used[d[0]-1] = true;
    for (d[1] = 1; d[1] <= n; d[1]++) {
      if (used[d[1]-1]) continue;
      used[d[1]-1] = true;
      for (d[2] = 1; d[2] <= n; d[2]++) {
        if (used[d[2]-1]) continue;
        used[d[2]-1] = true;

        REP(i,3) {
          m[i] = max(0, s-d[i]-1);
          if (max(s-d[i],d[i]) < b)
            m[i]++;
        }
        total += m[0]*m[1]*m[2]
               - min(m[0],m[1])*m[2] - min(m[0],m[2])*m[1] - min(m[2],m[1])*m[0]
               + 2*min(min(m[0],m[1]),m[2]);

        used[d[2]-1] = false;
      }
      used[d[1]-1] = false;
    }
    used[d[0]-1] = false;
  }
  return total;
}

bool shouldBet(pair<int, int> c) {
  cout << "Cards " << c.first << "," << c.second << endl;
  unsigned long long x = strength(c);
  unsigned long long y = ((n-2)*(n-3)*(n-4)*(n-5)*(n-6)*(n-7) / 5);
  ERR(x);
  ERR(y);
  return x > y;
}

int main() {
  cin >> t;
  REP(i,t) {
    printf("Case #%d: ",i+1);
    cin >> n >> h;

    vector<vector<int>> ranks(n);
    REP(j,n) ranks[j].assign(n,-1);
    vector<pair<int, int>> ord(n*(n-1)/2);
    int di = 0;
    FOR(diag,3,n+n) {
      FOR(b,diag/2+1,min(diag,n+1)) {
        ord[di] = {diag-b, b};
        ranks[diag-b-1][b-1] = di++;
      }
    }
    /* 
    cout << "ord: ";
    REP(j,n*(n-1)/2)
      printf("(%d,%d) ", ord[j].first, ord[j].second);
    cout << "\nranks:\n";
    REP(j,n) REP(k,n)
      printf("%d%c", ranks[j][k], (k == n-1) ? '\n' : '\t');
    */

    int l = 0, r = n*(n-1)/2-1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      ERR(l,mid,r);
      if (shouldBet(ord[mid])) {
        if (!shouldBet(ord[mid-1])) break;
        else {
          r = mid;
        }
      } else {
        l = mid + 1;
      }
      ERR(l,mid,r); cout << endl;
    }

    REP(j,h) {
      cin >> c1 >> c2;
      if (c1 > c2) swap(c1,c2);
      ERR(ranks[c1-1][c2-1], mid);
      if (ranks[c1-1][c2-1] < mid) cout << "F";
      else cout << "B";
    }
    cout << endl;
  }
  return 0;
}
