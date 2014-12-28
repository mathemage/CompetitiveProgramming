/* ========================================
 * Points : 0
 * Total : 500
 * Status : challenged, now working
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

// uncomment following line for debug mode
// #define DEBUG   

#ifdef DEBUG
#define MSG(a) cout << #a << " == " << a << endl;
#else
#define MSG(a) ;
#endif

class TheKingsFactorization {
public:
  vector<long long> getVector(long long N, vector<long long> primes) {
    long long M = primes.size() * 2 - 1;
    vector<long long> result(M);
    REP(i,M) {
      if (i % 2 == 0) {
        result[i] = primes[i/2];
        N /= result[i];
      }
    }
    MSG(N)
    REP(i,M) {
      if (i % 2 != 0) {
        if (i == M-2 && N <= result.back()) {
          result[i] = N;
        } else {
          long long divisor = result[i-1];
          while (N % divisor != 0) {
            divisor += (divisor == 2) ? 1 : 2;
          }
          result[i] = divisor;
        }
        N /= result[i];
      }
    }

    if (N != 1) {
      result.push_back(N);
    }

    return result;
  }
};
