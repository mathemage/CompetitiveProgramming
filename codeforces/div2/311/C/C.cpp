 
/* ========================================

   * File Name : C.cpp

   * Creation Date : 30-06-2015

   * Last Modified : Tue 30 Jun 2015 07:00:11 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/557/problem/C

   * Points Gained (in case of online contest) : 0 / 1500, not submitted

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

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  vector<int> d(n);
  REP(i,n) {
    cin >> l[i];
  }
  int bs = 210;
  vector< vector<int> > buckets(bs);
  REP(i,n) {
    cin >> d[i];
    buckets[d[i]].emplace_back(l[i]);
  }
  REP(i,bs) {
    sort(ALL(buckets[i]));
    reverse(ALL(buckets[i]));
    /* 
    REP(j,buckets[i].size()) {
      cout << buckets[i][j] << '\t';
    }
    if (buckets[i].size()) {
      cout << endl;
    } */
  }

  vector<int> maxs(bs,-1);
  vector<int> heads(bs,-1);
  int res = 200 * 100000 * 4;
  int prefix_price = 0;

  do {
    int cnt = 0;
    int discard_price = 0;
    REP(i,bs) {
      if (heads[i] + 1 < buckets[i].size()) {
        maxs[i] = buckets[i][heads[i]+1];
      } else {
        maxs[i] = -1;
      }
    }
    int ma = *max_element(ALL(maxs));
    ERR(ma);
    if (ma < 1) {
      break;
    }

    // leave the longest group
    REP(i,bs) {
      while (heads[i]+1 < buckets[i].size() && buckets[i][heads[i]+1] == ma) {
        heads[i]++;
        cnt++;
        discard_price += i;
      }
    }
    ERR(cnt, discard_price); cout << endl;
    int leave_price = 0;
    int to_discard = n - 2 * cnt + 1;
    int p = 1, cur = heads[1] + 1;
    ERR(to_discard);
    while (to_discard > 0) {
      while (p < bs && (buckets[p].size() == 0 || cur > buckets[p].size() - 1)) {
        p++;
        cur = heads[p] + 1;
        ERR(cur, p, buckets[p].size()); cout << endl;
      }

      if (p >= bs) {
        break;
      }
      leave_price += p;
      cur++;
      to_discard--;
    }
    if (to_discard > 0) {
      break;
    }
    res = min(res, prefix_price + leave_price);
    ERR(to_discard, res, prefix_price, leave_price);

    // discard the longest group
    if (discard_price >= leave_price) {
      break;
    } else {
      prefix_price += discard_price;
    }
  } while(1);

  cout << res << endl;
  return 0;
}
