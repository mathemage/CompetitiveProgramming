 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 26-01-2021
   * Last Modified : Út 26. ledna 2021, 01:27:20
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1474/problem/B
   * Points/Time : 24m 30 s - ~27m
   * Total :
   * Status : WA (#2) - AC - AC (without p1*p1*p1)
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve(vector<long long> & primes) {
  int d;
  cin >> d;

  long long p1 = *upper_bound(ALL(primes), d);
  long long p2 = *upper_bound(ALL(primes), p1+d-1);
//   long long result = min(p1*p2, p1*p1*p1);
  long long result = p1*p2;
  cout << result << endl;
//   MSG(p1) MSG(p2) cerr << endl;
}

int main() {
  vector<long long> primes = {2,3,5,7};
  for (long long n = 11; primes.back() < 25000; n += 2) {
    bool is_prime = true;
    for (long long i = 0; i<primes.size() && primes[i]*primes[i]<=n ; i += 1) {
      if (n % primes[i] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      primes.push_back(n);
    }
  }
  
  int cases;
  cin >> cases;
//   cases = 1;
  while (cases--) {
    solve(primes);
  }
  return 0;
}
