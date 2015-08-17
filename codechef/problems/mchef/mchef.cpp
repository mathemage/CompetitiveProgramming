
/* ========================================

 * File Name : mchef.cpp

 * Creation Date : 16-08-2015

 * Last Modified : Mon 17 Aug 2015 06:05:08 PM CEST

 * Created By : Karel Ha <mathemage@gmail.com>

 * URL : https://www.codechef.com/problems/MCHEF

 ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

//#define DEBUG

int main() {
  int t,n,k,m,l,r;
  short int c;
  scanf("%d", &t);
  REP(ti,t) {
    /* ---------------------------------------------------------------------- */
    /* LOAD THE TESTCASE */
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &m);
#ifdef DEBUG
    ERR(t, n, k, m);
#endif
    vector<long long> ratings(n);
    long long total_rating = 0;
    REP(ni,n) {
      scanf("%lld", &ratings[ni]);
      total_rating += ratings[ni];
#ifdef DEBUG
      ERR(ni, ratings[ni], total_rating);
#endif
    }

    const short int inf = k+1;
    vector<short int> costs(n,inf);
    REP(mi,m) {
      scanf("%d", &l);
      scanf("%d", &r);
      scanf("%hd", &c);
      FOR(i,l-1,r) {
        costs[i] = min(c, costs[i]);
      }
    }
    /* ---------------------------------------------------------------------- */


    /* ---------------------------------------------------------------------- */
    /* DYNAMIC PROGRAMMING: PSEUDOPOLYNOMIAL SUBSET SUM */ 
    vector<long long> optimal_ratings(k+1,total_rating);
    REP(ni,n) {
      if (ratings[ni] >= 0 || costs[ni] > k) {      // ...skip irrelevant dishes
        continue;
      }

      for (int i = k; i >= costs[ni]; i--) {
        optimal_ratings[i] = max(optimal_ratings[i],
            optimal_ratings[i-costs[ni]] - ratings[ni]);
      }

#ifdef DEBUG
      cout << "optimal_ratings: ";
      REP(oi,k+1) {
        cout << optimal_ratings[oi] << " ";
      }
      cout << endl;
#endif
    }
    /* ---------------------------------------------------------------------- */

    printf("%lld\n", *max_element(ALL(optimal_ratings)));
  }
  return 0;
}
