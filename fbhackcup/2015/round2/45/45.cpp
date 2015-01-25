/* ========================================

   ID: mathema6
   TASK: 45
   LANG: C++11
   (...for USACO solutions)

   * File Name : 45.cpp

   * Creation Date : 24-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=1521672018093383&round=323882677799153

   * Points Gained (in case of online contest) : 0, not working for the input

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

unsigned long long res,tmp;
int t,n,m;

unsigned long long s1,s2,xs,ys,zs;
unsigned long long o1,o2,xo,yo,zo;
unsigned long long a1,a2,xa,ya,za;
unsigned long long b1,b2,xb,yb,zb;
unsigned long long c1,c2,xc,yc,zc;
unsigned long long d1,d2,xd,yd,zd;

vector<unsigned long long> bins;
const unsigned long long billion = 1000000000;

void perform(unsigned long long o,unsigned long long a,unsigned long long b,unsigned long long c,unsigned long long d) {
#ifdef DEB
  ERR(o,a,b,c,d,res);
#endif
  REP(i,b) {
    switch (o) {
      case 1:
        bins[a-1] += c; bins[a-1] %= billion;
        bins[a-1] += (i*d)%billion; bins[a-1] %= billion;
        res += (c%billion) + ((i*d)%billion);
        break;
      case 2:
        res += (bins[a-1]%billion) + (c%billion);
        bins[a-1] = c % billion;
        break;
      case 3:
        res += bins[a-1]%billion;
        break;
      case 4:
        res += bins[a-1]%2;
        break;
    }
    res %= billion;
    a++; a %= n;
  }
#ifdef DEB
  ERR(res); cout << endl;
#endif
}

int main() {
  cin >> t;
  REP(i,t) {
    cin >> n >> m;
    cin >> s1 >> s2 >> xs >> ys >> zs;
    cin >> o1 >> o2 >> xo >> yo >> zo;
    cin >> a1 >> a2 >> xa >> ya >> za;
    cin >> b1 >> b2 >> xb >> yb >> zb;
    cin >> c1 >> c2 >> xc >> yc >> zc;
    cin >> d1 >> d2 >> xd >> yd >> zd;
    res = 0;

    // init bins
    bins.resize(n);
    bins[0] = s1;
    bins[1] = s2;
    FOR(j,2,n) {
      bins[j] = (xs*s1 + ys*s2 + zs) % billion;
      s1 = s2;
      s2 = bins[j];
    }
#ifdef DEB
    REP(j,n) {
      ERR(j,bins[j]);
    }
#endif

    perform(o1,a1,b1,c1,d1);
    perform(o2,a2,b2,c2,d2);
    FOR(j,2,m) {
      tmp = ((xo*o1 + yo*o2 + zo) % 4) + 1;
      o1 = o2;
      o2 = tmp;

      tmp = ((xa*a1 + ya*a2 + za) % n) + 1;
      a1 = a2;
      a2 = tmp;

      tmp = ((xb*b1 + yb*b2 + zb) % n) + 1;
      b1 = b2;
      b2 = tmp;

      tmp = (xc*c1 + yc*c2 + zc) % billion;
      c1 = c2;
      c2 = tmp;

      tmp = (xd*d1 + yd*d2 + zd) % billion;
      d1 = d2;
      d2 = tmp;

      perform(o2,a2,b2,c2,d2);
    }

    printf("Case #%d: %llu\n", i+1, res);
  }
  return 0;
}
