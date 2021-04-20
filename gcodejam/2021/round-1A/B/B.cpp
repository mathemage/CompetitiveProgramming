/* ========================================

   ID: mathema6
   TASK: 
   LANG: C++14

   * File Name : B.cpp
   * Creation Date : 15-04-2021
   * Last Modified : Tue 20 Apr 2021 04:32:01 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007543d8
   * Points/Time :
   *      =   45m :-/
   * + 9m =   54m
   * +17m = 1h11m
   * [editorial]
   * +35m = 1h46m
   *
   * Total/ETA :
   * 15m (TS1 - brute force)
   *
   * Status :
   * S AC TLE - !
   * S AC  AC TLE !!!!
   * [editorial]
   * S AC  AC  AC !!!!!!!!!!!!
   *
   ==========================================*/

#define PROBLEMNAME "TASK_PLACEHOLDER_FOR_VIM"

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
// #define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
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

using ll = long long;
using ul = unsigned long long;
using llll = pair<ll, ll>;
using ulul = pair<ul, ul>;

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2
#endif

ostream& operator<<(ostream& os, const vector<string> & vec) {
  os << endl;
  for (const auto & s: vec) os << s << endl;
  return os;
}

template<typename T> 
ostream& operator<<(ostream& os, const vector<T> & vec) { 
  for (const auto & x: vec) os << x << " ";
  return os; 
} 

template<typename T> 
ostream& operator<<(ostream& os, const vector<vector<T>> & vec) { 
  for (const auto & v: vec) os << v << endl;
  return os; 
} 

template<typename T>
inline ostream& operator<<(ostream& os, const vector<vector<vector<T>>> & vec) {
  for (const auto & row: vec) {
    for (const auto & col: row) {
      os << "[ " << col << "]   ";
    }
    os << endl;
  }
  return os;
}

template<typename T> 
ostream& operator<<(ostream& os, const set<T>& vec) { 
  os << "{ | ";
  for (const auto & x: vec) os << x << "| ";
  os << "}";
  return os; 
} 

template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& vec) {
  os << "{ | ";
  for (const auto & x: vec) os << x << "| ";
  os << "}";
  return os;
}

template<typename T1, typename T2>
void print_vector_pairs(const vector<pair<T1, T2>> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  cerr << endl;
}

template<typename T>
istream& operator>>(istream& is, vector<T> & vec) {
  for (auto & x: vec) is >> x;
  return is;
}

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = {-1, 0, 1,  0};
const vector<int> DY4 = { 0, 1, 0, -1};
const vector<pair<int,int>> DXY4 = { {-1,0}, {0,1}, {1,0}, {0,-1} };
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};


#ifndef MATHEMAGE_LOCAL
void setIO(string filename) {    // the argument is the filename without the extension
	freopen((filename+".in").c_str(), "r", stdin);
	freopen((filename+".out").c_str(), "w", stdout);
  MSG(filename);
}
#endif

const ll MAX_CARDS=59;  // https://www.wolframalpha.com/input/?i=log2%28+499+*+1e15%29
const ll MAX_G2_SUM=29441; // https://www.wolframalpha.com/input/?i=59+*+499

vector<int> primes;

void solve() {
  ll M;
  cin >> M;

  vector<long long> P(M);
  vector<long long> N(M);
  map<ll, ll> cnt;
  ll s=0;
  REP(i,M) {
    cin >> P[i] >> N[i];
    s+=P[i]*N[i];
    cnt[P[i]] = N[i];
  }
  MSG(s);

  ll result = 0LL;
  FORD(prod, s-1, max(2LL, s-MAX_G2_SUM)) {
    ll candidProd=prod;
    ll sum=s;
    for (auto & p: P) {
      REP(_, cnt[p]) {
        if (candidProd%p==0) {
          candidProd/=p;
          sum-=p;
        } else {
          break;
        }
      }
    }

    if (candidProd==1 && sum==prod) {
      MAXUPDATE(result, prod);

      MSG(candidProd); MSG(prod); MSG(sum); MSG(result);
      LINESEP1;
    }
  }

  cout << result << endl;
}

const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vector<int> eratosthenes_sieve(int lim) {
  isprime.set(); isprime[0] = isprime[1] = 0;
  for (int i = 4; i < lim; i += 2) isprime[i] = 0;
  for (int i = 3; i*i < lim; i += 2) if (isprime[i])
    for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
  vector<int> pr;
  FOR(i,2,lim) if (isprime[i]) pr.push_back(i);
  return pr;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  primes=eratosthenes_sieve(500);
  MSG(primes);

  int cases = 1;
  cin >> cases;
  FOR(tt,1,cases) {
    cout << "Case #" << tt << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
