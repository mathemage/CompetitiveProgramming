/* ========================================

   ID: mathema6
   TASK: 10
   LANG: C++11
   (...for USACO solutions)

   * File Name : 10.cpp

   * Creation Date : 17-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=582396081891255&round=344496159068801

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
  cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

int main() {
  const int rng = 10000001;
  vector<int> primacities(rng);
  primacities[0] = primacities[1] = 0;

  FOR(n2,2,rng) {
    int d = 2, n = n2;
    while (d * d <= n) {
      if (n%d == 0) {
        primacities[n2]++;
        while (n%d==0) {
          n/=d;
        }
      }
      d += (d==2) ? 1 : 2;
    }
    primacities[n2] += (n != 1);
  }

  int t,a, b, k;
  cin >> t;
  REP(i,t) {
    cout << "Case #" << i+1 << ": ";
    cin >> a >> b >> k;
    //ERR(a,b,k); cout << endl;

    int res = 0;
    FOR(n,a,b+1) {
      res += (primacities[n] == k);
      //ERR(n2,primacity); cout << endl;
    }
    cout << res << endl;
  }
  return 0;
}
