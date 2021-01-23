/* ========================================
 * Points : 155.28 (35m 10s)
 * Total : 300
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class NextOlympics {
public:
  int countDays(string today) {
    vector<int> days_in_months = {0,0,31,28,31, 30,31,30, 31,31,30, 31,30,31};
    partial_sum(ALL(days_in_months), days_in_months.begin());

    int oly_month = 7;
    int oly_day = 23;
    int oly_total = days_in_months[oly_month] + oly_day;

    stringstream ss(today);
    string token;
    getline(ss, token, '.');
    getline(ss, token, '.');
    int tod_month = stoi(token);
    getline(ss, token, '.');
    int tod_day = stoi(token);

    int tod_total = days_in_months[tod_month] + tod_day;

    int result = oly_total - tod_total;
    MSG(oly_total); MSG(tod_total);
    if (result < 0) {
      result += 365;
    }
    return result;
  }
};
