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

bool sumsTo(int i) {
  if (i >= p.size())
    return false;

  if (sp + p[i] == gp
      && sc + c[i] == gc
      && sf + f[i] == gf)
    return true;

  if (sumsTo(i+1))
    return true;

  if (sp + p[i] <= gp - 10
      && sc + c[i] <= gc - 10
      && sf + f[i] <= gf - 10) {
    sp += p[i];
    sc += c[i];
    sf += f[i];
    if (sumsTo(i+1))
      return true;

    sp -= p[i];
    sc -= c[i];
    sf -= f[i];
  }
  return false;
}

bool sumsTo() {
  sp = sc = sf = 0;
  sumsTo(0);
}

int main() {
  cin >> t;
  REP(i,t) {
    printf("Case #%d: ", i+1);
    cin >> gp >> gc >> gf >> n;
    p.resize(n);
    c.resize(n);
    f.resize(n);

    REP(j,n) {
      cin >> p[j] >> c[j] >> f[j];
    }
    cout << (sumsTo() ? "yes" : "no") << endl;
  }
  return 0;
}
