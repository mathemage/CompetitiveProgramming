/* ========================================
 * Points : 290.83
 * Total : 300
 * Status : AC on 1st attempt
 ==========================================*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <cctype>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

class IBEvaluator {
public:
  vector <int> getSummary(vector <int> predictedGrades, vector <int> actualGrades) {
    vector <int> result(7);

    int n =predictedGrades.size();
    REP(i,n) {
      result[abs(predictedGrades[i] - actualGrades[i])]++;
    }
    for (int & i : result) {
      i = 100 * i / n;
    }
    return result;
  }
};
