/* ========================================
 * Points : 235.95
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class PassingGrade {
public:
  int pointsNeeded(vector <int> pointsEarned, vector <int> pointsPossible, int finalExam) {
    int gained = accumulate(ALL(pointsEarned),0);
    int total = accumulate(ALL(pointsPossible),0) + finalExam;
    int res = ceil(0.65 * total) - gained; 

    MSG(total)
    MSG(0.65 * total)
    MSG(gained)
    MSG(res)
    if (res > finalExam) return -1;
    return max(res,0);
  }
};
