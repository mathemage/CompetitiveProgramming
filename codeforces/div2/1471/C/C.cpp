 
/* ========================================
   * File Name : C.cpp
   * Creation Date : 05-01-2021
   * Last Modified : Út 5. ledna 2021, 17:38:07
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1471/problem/C
   * Points :
   * Total : 1000
   * Status : not submitted
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

int main() {
  int t,n,m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> k(n);
    for (auto & ki : k) {
      cin >> ki;
    }
    vector<int> c(m);
    for (auto & ci : c) {
      cin >> ci;
    }

//     cout << << end;
  }
  return 0;
}
