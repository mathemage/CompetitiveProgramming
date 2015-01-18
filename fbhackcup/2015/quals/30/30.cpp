/* ========================================

   ID: mathema6
   TASK: 30
   LANG: C++11
   (...for USACO solutions)

   * File Name : 30.cpp

   * Creation Date : 09-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=1036037553088752&round=742632349177460

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

int t, n, gp, gc, gf, sp, sc, sf;
vector<int> p, c, f;

bool setTab(int r, int s, int t, int k, vector<bool> tab) {
}

int main() {
  cin >> t;
  REP(i,t) {
    printf("Case #%d: ", i+1);
    cin >> gp >> gc >> gf >> n;
    p.resize(n);
    c.resize(n);
    f.resize(n);
    vector<bool> tab(gp * gc * gf * n);

    int n2 = n * gf.size();
    int n1 = n2 * gc.size();
    REP(j,n) {
      cin >> p[j] >> c[j] >> f[j];
    }
    REP(i1,gp) REP(i2,gc) REP(i3,gf) REP(i4,n+1) {
      if (i1 + i2 + i3 == 0) {
        tab[i4] = true;
        continue;
      }

      if (i4 == 0)
        tab[i1*n1 + i2*n2 + i3*n + i4] = true;
      else
        int s1 = 
          tab
          tab(r-p[k-1], s-c[k-1], t-f[k-1], k-1) || tab(r, s, t, k-1);
    }

    cout << (sumsTo() ? "yes" : "no") << endl;
  }
  return 0;
}
