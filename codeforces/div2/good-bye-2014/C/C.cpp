/* ========================================

   ID: mathema6
   TASK: C
   LANG: C++11
   (...for USACO solutions)

   * File Name : C.cpp

   * Creation Date : 08-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/500/problem/C

   * Duration : 21 min
    
   * Status : AC on 2nd attempt

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> w(n);
  REP(i,n) {
    cin >> w[i];
  }

  int b, curPos, lift = 0;
  vector<int> st;
  unordered_map<int, int> pos;
  REP(i,m) {
    cin >> b;
    if (pos.find(b) == pos.end()) {
      curPos = st.size();
      st.push_back(b);
    } else {
      curPos = pos[b];
    }

    while (--curPos >= 0) {
      lift += w[st[curPos]-1];
      pos[st[curPos]]++;
      swap(st[curPos+1], st[curPos]);
    }
    pos[b] = 0;
  }

  cout << lift << endl;
  return 0;
}
