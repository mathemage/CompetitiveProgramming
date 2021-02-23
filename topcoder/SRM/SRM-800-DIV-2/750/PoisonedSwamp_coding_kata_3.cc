/* ========================================
 * Points/Time : 453.97 (27m)
 * Total/ETA : 750
 * Status : AC
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
  for (const auto & x: vec) cerr << get<0>(x) << "," << get<1>(x) << ","  << get<2>(x) << "  ";
  cerr << endl;
}
// template<typename T>
// void print_vector(const vector<T> & vec, const string & name) {
//   cerr << name << ": ";
//   for (const auto & x: vec) cerr << x << "  ";
//   cerr << endl;
// }

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

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


typedef tuple<int,int,int> iii;

class PoisonedSwamp {
public:
  iii q[20 * 20 * 10 + 10];
  bool vis[25][25][10] = {{{false}}};
  int r,c,p;
  int rr,cc,pp;

  string cross(vector <string> swamp) {
    int n_r=swamp.size();
    int n_c=swamp[0].size();

    int back=0,front=0;
    q[back++] = MTP(0,0,0);

    while (front<back) {
//       cerr << endl; MSG(front) MSG(back);

      iii at=q[front++];
      r=get<0>(at);
      c=get<1>(at);
      p=get<2>(at);
      vis[r][c][p]=true;
//       MSG(r) MSG(c) MSG(p);
      
      if (r==n_r-1 && c==n_c-1) {
        return "possible";
      }
//       MSG(n_r-1); MSG(n_c-1);

      for (auto & dxy : DXY4) {
        rr=r+dxy.F;
        cc=c+dxy.S;

        if (0<=min(rr,cc) && rr<n_r && cc<n_c && swamp[rr][cc]!='#') {
          if (swamp[rr][cc]=='.') {
            pp=p;
          } else if (swamp[rr][cc]=='S') {
            pp=0;
          } else {
            pp=p+int(swamp[rr][cc]-'0');
          }

          if (!vis[rr][cc][pp] && pp<10) {
            q[back++]=MTP(rr,cc,pp);
            vis[rr][cc][pp]=true;
          }
        }
      }
    }

    return "impossible";
  }
};
