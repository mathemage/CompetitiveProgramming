/* ========================================
 * Points :
 * Total :
 * Status :
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

#define FOR(I,A,B) for(long long I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

class TheKingsFactorization {
public:
  vector<long long> getVector(long long N, vector<long long> primes) {
    long long M = primes.size() * 2 - 1;
    vector<long long> result(M);
    REP(i,M) {
      if (i % 2 == 0) {
        result[i] = primes[i/2];
      }
      else {
        if (N % result[i-1] == 0) {
          cout << "Case A: ";
          result[i] = result[i-1];
        } else {
          cout << "Case C: ";
          long long divisor = result[i-1];
          while (N % divisor != 0) {
            MSG(N) MSG(divisor)
            divisor += (divisor == 2) ? 1 : 2;
          }
          result[i] = divisor;
        }
      }

      MSG(N)
      N /= result[i];
      MSG(N) MSG(result[i]) MSG(i)
        cout << endl;
    }
    cout << "here" << endl;

    if (N != 1) {
      cout << "Case D: ";
      long long divisor = primes[primes.size()-1];
      while (N % divisor != 0) {
        divisor += (divisor == 2) ? 1 : 2;
      }
      result.push_back(divisor);
    }

    return result;
  }
};
// challenged
