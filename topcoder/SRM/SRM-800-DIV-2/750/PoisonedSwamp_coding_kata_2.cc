/* ========================================
 * Points/Time : 344.90
 * Total/ETA : 750/15m
 * Status : AC !!
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

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

#define MSG(a) cerr << "> " << #a << ": " << (a) << endl;
template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

template<typename T>
void print_queue(queue<T> q, string name) {
  cerr << name << ": ";
	while (!q.empty()){
    auto f=q.front();
		cerr << get<0>(f) << "," << get<1>(f) << "," << get<2>(f) << "  ";
		q.pop();
	}
	cerr << endl;
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

// direction vectors - 4 directions
const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
// direction vectors - 8 directions
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};

typedef tuple<int, int, int> iii;   // <row, column, poison count>

class PoisonedSwamp {
public:
  queue<iii> q;
  int n_r, n_c;
  int r, c, p;
  int rr, cc, pp;
//   bool vis[25][25][10] =  { {false} };
  bool vis[25][25][10] =  {{{false}}};

  string cross(vector <string> swamp) {
    n_r = swamp.size();
    n_c = swamp[0].size();

//     q.push({0,0,0});
    q.push(MTP(0,0,0));

    while (!q.empty()) {
//       print_queue(q, "queue");

      iii at = q.front();
      r=get<0>(at);
      c=get<1>(at);
      p=get<2>(at);
      vis[r][c][p]=true;

      q.pop();

      if (r==n_r-1 && c==n_c-1) {
        return "possible";
      }

      for (auto & drc: DXY4) {
        rr=r+drc.F;
        cc=c+drc.S;
        if (! (0<=min(rr,cc) && rr<n_r && cc<n_c && swamp[rr][cc]!='#') ) {
          continue;
        }

//         MSG(rr) MSG(cc)
        if (swamp[rr][cc]=='.') {
          pp=p;
        } else if (swamp[rr][cc]=='S') {
          pp=0;
        } else {
          pp=p + int(swamp[rr][cc]-'0');
          if (pp>=10) {
            continue;
          }
        }

        if (!vis[rr][cc][pp]) {
//           MSG(pp)
          q.push(MTP(rr,cc,pp));
          vis[rr][cc][pp]=true;
        }
      }
    }

    return "impossible";
  }
};
