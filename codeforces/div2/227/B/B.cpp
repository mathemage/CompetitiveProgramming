 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 03-01-2021
   * Last Modified : Ne 3. ledna 2021, 22:57:44
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/227/problem/B
   * Points : 
   * Total : 500
   * Status : AC
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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> pos(n+5);
  for (int i = 0; i < a.size(); ++i) {
    cin >> a[i];
    pos[a[i]] = i+1;
  }

  long long vasya = 0;
  long long petya = 0;
  int m, bi;
  cin >> m;
  while (m--) {
    cin >> bi;
    vasya += pos[bi];
    petya += n + 1 - pos[bi];
  }
  cout << vasya << " " << petya << endl;
  return 0;
}
