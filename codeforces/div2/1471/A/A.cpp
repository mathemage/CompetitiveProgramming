 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 05-01-2021
   * Last Modified : Út 5. ledna 2021, 20:27:42
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1471/problem/0
   * Points : 458
   * Total : 500
   * Status : AC (3 pretests)
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;
#define endl "\n"

const int CLEAN = -1;
const int UNDEF = -42;

int main() {
  int t,n,x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<int> a(n);
    long long mi = 0;
    long long ma = 0;
    for (auto & ai : a) {
      cin >> ai;
      mi += ai;
      ma += (ai + x - 1) / x;
    }
    mi = (mi + x - 1) / x;
    cout << mi << " " << ma << endl;
  }
  return 0;
}
