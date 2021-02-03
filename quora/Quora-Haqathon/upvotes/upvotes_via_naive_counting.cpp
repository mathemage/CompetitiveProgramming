 
/* ========================================
   * File Name : upvotes.cpp
   * Creation Date : 22-01-2021
   * Last Modified : St 3. února 2021, 22:59:10
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/upvotes
   * Points/Time : 1h 31 m 10 s (previous) + ? (~30 m) + 1h 5 m 50 s + (1h 39m 40s )
   * Total :
   * Status :
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
const int UNDEF = INT_MAX;
const int INF = INT_MAX;

struct interval_t {
  int L;
  int R;
  int sgn;
};

char sgn_int2char(int sgn) {
  return sgn? (sgn>0?'+':'-') : '0';
}

void print_interval(string name, vector<interval_t> intervals) {
  cerr << name << ": ";
  for (auto & interval : intervals) {
    cerr << "[" << interval.L << ","  << interval.R << "]";
    cerr << "(" << sgn_int2char(interval.sgn) << ")\t";
  }
  cerr << endl;
}

bool is_subinterval(interval_t inner, interval_t outer) {
  return outer.L <= inner.L && inner.R <= outer.R;
}

void solve_via_naive_counting() {
  int N, K;
  cin >> N >> K;
  if (N == 1) {
    cout << 0 << endl;
    return;
  }

  //-----values and signs-----
  vector<int> upvotes(N);
  vector<int> signs(N, UNDEF);
  REP(i,N) {
    cin >> upvotes[i];
    if (i>0) {
      signs[i] = SGN(upvotes[i]-upvotes[i-1]);
    }
//     MSG(upvotes[i]); MSG(signs[i]); cerr << endl;
//     cerr << signs[i] << " ";
  }
//   cerr << endl;
  //--------------------------

  //-----maximal nonzero and zero intervals-----
  vector<interval_t> nonzero_intervals = { {1,1,signs[1]} };
  vector<pair<int, int>> nonzero_possgn;
  vector<interval_t> zero_intervals = { };
  FO(i,1,N-1) {
    if (signs[i] != 0) {  // nonzero intervals
      if (!nonzero_possgn.empty() ) {
        auto & last_possgn = nonzero_possgn.back();
        if (last_possgn.S == -signs[i]) {
          nonzero_intervals.back().R = i-1;
          nonzero_intervals.PB( {last_possgn.F+1, last_possgn.F+1, signs[i]} );
        }
      }

      nonzero_possgn.PB(MP(i, signs[i]));
    } else {  // zero intervals
      if (zero_intervals.empty() || zero_intervals.back().R!=i-1) {
        zero_intervals.PB({i,i,0});
      } else {
        zero_intervals.back().R = i;
      }
    }
  }
  nonzero_intervals.back().R = N-1;
  //--------------------------------------------------

  int win_start = 0, win_end=win_start+K-1;

  //-----initialize indices i_l, i_r into nonzero_intervals-----
  int i_l = 0;
  //-----search for i_r-----
  int i_r = 0;
  while (! (nonzero_intervals[i_r].L <= win_end && win_end <= nonzero_intervals[i_r].R) ) {
    i_r++;
  }
  int i_0 = 0;  // index zero_intervals
  //--------------------------------------------------
  
  //-----calculate balance for the first window-----
  long long win_balance = 0LL;
  FO(i,i_l,i_r) {
    int sgn_i = nonzero_intervals[i].sgn;
    long long width = min(win_end, nonzero_intervals[i].R) - max(win_start, nonzero_intervals[i].L) + 1;
    win_balance += sgn_i * width * (width+1LL) / 2LL; // TODO: extract interval_contribution(interval_t interval, sgn_i)

    // subtract subranges inside zero_intervals
    while ( is_subinterval(zero_intervals[i_0],
          {nonzero_intervals[i_l].L, nonzero_intervals[i_r].R, 0}) ) {
      long long width_0 = min(win_end, zero_intervals[i_0].R) - max(win_start, zero_intervals[i_0].L) + 1;
      win_balance -= sgn_i * width_0 * (width_0+1LL) / 2LL;

      if (zero_intervals[i_0].R < min(win_end, nonzero_intervals[i].R)) {
        i_0++;
      } else {
        break;
      }
    }
  }
  //--------------------------------------------------


  //----------------DEBUG-print-----------------------
  cerr << "nonzero_possgn: ";
  for (auto & sg: nonzero_possgn) {
    cerr << sg.F << "(" << sgn_int2char(sg.S) << ")\t";
  }
  cerr << endl;

  print_interval("nonzero_intervals", nonzero_intervals);
  print_interval("zero_intervals", zero_intervals);

  MSG(win_start); MSG(win_end);
  print_interval("i_l, i_r", {nonzero_intervals[i_l], nonzero_intervals[i_r]});

  cout << "win_balance: ";
  cout << win_balance << endl;
  //--------------------------------------------------


//   for (win_start=1, win_end=win_start+K-1 ; win_end < N; win_start++, win_end++) {
  for (int win_start=0, win_end=win_start+K-1 ; win_end < N; win_start++, win_end++) {
//     cerr << endl << endl; MSG(win_start); MSG(win_end);
    long long result = 0LL;
    FO(start,win_start,win_end) FO(end,start+1,win_end) {
      int min_sign = INF;
      int max_sign = -INF;
      FO(i,start+1,end) {
        MINUPDATE(min_sign, signs[i]);
        MAXUPDATE(max_sign, signs[i]);
      }

      if (min_sign >= 0 && max_sign == 1) { result++; }
      if (min_sign == -1 && max_sign <= 0) { result--; }
//       cerr << endl; MSG(start); MSG(end); MSG(min_sign); MSG(max_sign); MSG(result);
    }

    cout << result << endl;
  }
}

int main() {
  int cases;
//   cin >> cases;
  cases = 1;
  while (cases--) {
    solve_via_naive_counting();
  }
  return 0;
}
