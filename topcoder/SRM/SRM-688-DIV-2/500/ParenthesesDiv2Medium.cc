/* ========================================
 * Points : 150.07
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class ParenthesesDiv2Medium {
public:
  vector <int> correct(string s) {
    vector <int> result;
    int leftTotal = 0, leftCurrent = 0, n = s.size() / 2, i = 0;
    for (auto & c : s) {
      switch (c) {
        case '(':
          if (leftTotal < n) {
            leftCurrent++;
            leftTotal++;
          } else {
            result.emplace_back(i);
            leftCurrent--;
          }
          break;
        case ')':
          if (leftCurrent > 0) {
            leftCurrent--;
          } else {
            result.emplace_back(i);
            leftCurrent++;
            leftTotal++;
          }
          break;
      }
      i++;
    }

    return result;
  }
};
