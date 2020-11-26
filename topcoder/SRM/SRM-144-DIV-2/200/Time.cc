/* ========================================
 * Points : 60
 * Total : 200
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Time {
public:
  string whatTime(int seconds) {
    string result;

    result += to_string(seconds / 3600);
    result += ":";
    seconds %= 3600;

    result += to_string(seconds / 60);
    result += ":";
    seconds %= 60;

    result += to_string(seconds);

    return result;
  }
};
