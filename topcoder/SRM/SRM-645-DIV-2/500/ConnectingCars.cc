/* ========================================
 * Points : 
 * Total : 500
 * Status : failed
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class ConnectingCars {
public:
  long long minimizeCost(vector <int> positions, vector <int> lengths) {
    int n = positions.size();
    vector<pair<double, double>> cars(n);
    REP(i,n) {
      cars[i] = { positions[i], positions[i] + lengths[i] };
    }
    sort(ALL(cars));

    double mid = (2*accumulate( positions.begin(), positions.end(), 0)
      + accumulate( lengths.begin(), lengths.end(), 0) ) / (2*n);

    int m = 0;
    while (cars[m].first < mid) {
      m++;
    }
    m = max(0, m-1);

    long long result = 0;

    double d = max(0.0, mid - cars[m].second);
    result += d;
    cars[m].first += d;
    cars[m].second += d;
    for (int i = m - 1; i >= 0; i--) {
      d = cars[i].first - cars[i-1].second;
      result += d;
      cars[i-1].first += d;
      cars[i-1].second += d;
    }

    d = max(0.0, (m+1<n) ? cars[m+1].first - mid : 0.0);
    result += d;
    if (m+1 < n) {
      cars[m+1].first -= d;
      cars[m+1].second -= d;
    }
    for (int i = m + 2; i < n; i++) {
      d = cars[i].first - cars[i-1].second;
      result += d;
      cars[i].first -= d;
      cars[i].second -= d;
    }

    return result;
  }
};
