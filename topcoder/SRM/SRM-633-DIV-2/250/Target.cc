/* ========================================
 * Points : 150.93
 * Total : 250
 * Status : AC on 1st attempt
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Target {
public:
  vector <string> draw(int n) {
    if (n <= 1)
      return vector<string> {"#"};

    vector <string> result(n);
    int i = 2;
    for (auto & s : draw(n-4)) {
      result[i++] = "# " + s + " #";
    }

    result[0].resize(n);
    result[1].resize(n);
    result[n-2].resize(n);
    result[n-1].resize(n);
    REP(i,n) {
      result[0][i] = result[n-1][i] = '#';
      if (i == 0 || i == n-1)
        result[1][i] = result[n-2][i] = '#';
      else
        result[1][i] = result[n-2][i] = ' ';
    }

    return result;
  }
};
