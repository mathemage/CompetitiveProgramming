/* ========================================
 * Points :
 * Total : 300
 * Status :
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Scramble {
public:
  string scrambleWord(string text) {
    int n = text.size();
    string remove = text.substr(1,n-2);
    sort(ALL(remove));
    string result = text;
    int a = 1, b = n-2, pos;
    REP(i,n-2) {
      pos = (i % 2) ? b-- : a++;
      result[pos] = remove[i];
    }

    return result;
  }
};
