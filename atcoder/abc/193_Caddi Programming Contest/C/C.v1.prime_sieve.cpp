/* ========================================
   * File Name : C.cpp
   * Creation Date : 19-03-2021
   * Last Modified : Fri 19 Mar 2021 09:43:57 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://atcoder.jp/contests/abc193/tasks/abc193_c
   * Points/Time :
   * 33m40s
   * +
   * 
   * Total/ETA :
   * Status :
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MTP make_tuple
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())
#define SZ(x) ((int) (x).size())

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC(v) print_vector((v), (#v));
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2
#endif

template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

template<typename T1, typename T2>
void print_vector_pairs(const vector<pair<T1, T2>> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  cerr << endl;
}

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

vector<long long> sieve(long long maxN) {
  vector<bool> isPrime(maxN+1,true);

  vector<long long> primes={2};
  long long n;
  for (n = 3; n*n <= maxN; n += 2) {
//     MSG(n);
    if (isPrime[n]) {
      primes.PB(n);
      for (long long k = n*n; k <= maxN; k += n) {
//         MSG(k);
        isPrime[k]=false;
      }
    }
//     LINESEP1;
  }

  while (n<=maxN) {
//     MSG(n);
    if (isPrime[n]) primes.PB(n);
    n+=2;
  }
  return primes;
}

void solve() {
  long long n;
  cin >> n;

  vector<long long> primes = sieve(1e5+10);
  MSG(primes.size());

  long long result = 0LL;
  for (auto & p: primes) {
    if (p*p > n) {
      break;
    }

    int k=p*p;
    while (k<=n) {
      result++;
      k*=p;
    }
  }

  cout << n-result << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//   MSG_VEC(sieve(52));
//   MSG_VEC(sieve(53));
//   MSG_VEC(sieve(54));
//   MSG_VEC(sieve(100));
//   MSG_VEC(sieve(1000));

  int cases = 1;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}
