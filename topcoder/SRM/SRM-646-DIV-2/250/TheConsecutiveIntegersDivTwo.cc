/* ========================================
 * Points : 234.09
 * Total : 250
 * Status : AC on 1st attempt
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class TheConsecutiveIntegersDivTwo {
public:
  int find(vector <int> numbers, int k) {
    if (k==1) return 0;

    sort(ALL(numbers));
    int result = numbers[1]-numbers[0]-1;
    for (int i = 0; i <  numbers.size()-1; ++i) {
      result = min(result, numbers[i+1]-numbers[i]-1);
    }

    return result;
  }
};
