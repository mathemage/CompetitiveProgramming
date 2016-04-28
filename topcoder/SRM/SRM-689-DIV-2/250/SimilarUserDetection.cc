/* ========================================
 * Points : 238.78
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class SimilarUserDetection {
public:
  string haveSimilar(vector <string> handles) {
    for (auto & h : handles) {
      for (auto & c : h) {
        switch (c) {
          case 'O':
            c = '0';
            break;
          case 'l':
            c = '1';
            break;
          case 'I':
            c = '1';
            break;
        }
      }
    }

    int n = handles.size();
    REP(i,n) REP(j,i) {
      if (handles[i] == handles[j]) {
        return "Similar handles found";
      }
    }

    return "Similar handles not found";
  }
};
