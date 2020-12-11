/* ========================================
 * Points : 75.04
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

//#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;


class OpenAllHours {
public:
  string verify(int N, vector <string> openingTime, vector <string> closingTime) {
    vector<int> o(N);
    vector<int> c(N);
    string s;
    int hh, mm;
    REP(i,N) {
      stringstream ss(openingTime[i]);
      ss >> hh;
      ss.ignore();
      ss >> mm;
      o[i] = hh * 60 + mm;
//       MSG(i); MSG(o[i]);
    }

    REP(i,N) {
      stringstream ss(closingTime[i]);
      ss >> hh;
      ss.ignore();
      ss >> mm;
      c[i] = hh * 60 + mm;
//       MSG(i); MSG(c[i]);
    }

    REP(time,60 * 24) {
      bool covered = false;
      REP(i,N) {
        bool is_between = min(o[i], c[i]) <= time && time < max(o[i], c[i]);
        if (is_between ^ (o[i] > c[i])) {   // covered by a shop
//           MSG(time) MSG(is_between); // MSG(is_between ^ (o[i] > c[i]));
          covered = true;
          break;
        }
      }
      if (!covered) {
        return "incorrect";
      }
    }

    return "correct";
  }
};
