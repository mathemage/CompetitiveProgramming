/* ========================================
 * Points : 127.21
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class RaceApproximator {
public:
  string timeToBeat(int D1, int T1, int D2, int T2, int raceDistance) {
    double d1 = D1;
    double d2 = D2;
    double t1 = T1;
    double t2 = T2;

    int t = t1*exp(log(t2/t1)*log(d1/raceDistance)/log(d1/d2));

    stringstream result;
    result << t / 3600 << ":";
    t %= 3600;
    result << setfill('0') << setw(2) << t/60 << ":";
    result << setfill('0') << setw(2) << t%60; 
    return result.str();
  }
};
