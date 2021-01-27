/* ========================================
 * Points :
   * 2h 11m 25s 
   * 2h 26m 30s (308.77/1000) 
   * 2h 30m 40s (300/1000) 
   * 2h 39m 50s (300/1000) 
   * 2h 46m 50s (300/1000) 
   * 3h  1m 10s (300/1000) 
   * 3h 14m 40s (300/1000) 
   * 3h 21m 50s (300/1000) 
   * 3h 25m 50s (300/1000) 
   * 3h 31m 50s (300/1000) 
   * 3h 31m 00s (300/1000) 
   * 5h 00m 10s (300/1000) 
 * Total : 1000
 * Status : TLE - WA - TLE (x2) - TLE #12 - TLE #7,#14,#13,#9 - TLE #12 - WA #57 - TLE #25&WA #57 - TLE #14,#7 - TLE #25 - segfault #28

 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

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
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;
const long long INF = LLONG_MAX;


class FlightPlan {
public:
  typedef pair<int, int> coord_t;   // (xy position, height)
  typedef long long dist_t;
  typedef pair<dist_t, coord_t> next_wakes_t;

  // TODO include into C++ template
  struct hash_pair {
    template <class T1, class T2>
      size_t operator()(const pair<T1, T2>& p) const
      {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
      }
  };

  vector<coord_t> get_neighbors(coord_t at_coord, int R, int C, vector<int> & H) {
    vector<coord_t> neighbors;
    int row = at_coord.F / C;
    int col = at_coord.F % C;
    int at_height = at_coord.S;

    // row-col neighbors
    vector<int> dr = {0, 0,1,-1};
    vector<int> dc = {1,-1,0, 0};
    REP(di,4) {
      int neigh_row = row + dr[di];
      int neigh_col = col + dc[di];
      if (0 <= neigh_row && neigh_row < R
       && 0 <= neigh_col && neigh_col < C ) {
        int neigh_rc = neigh_row * C + neigh_col;
        int neigh_height = max(at_height, H[neigh_rc]);
        neighbors.PB(MP(neigh_rc, neigh_height));
      }
    }

    return neighbors;
  }

  long long get_dist(coord_t at_coord, coord_t neigh_coord, long long C, long long clr, long long cdn, long long cup) {
    long long delta_row = abs(at_coord.F / C - neigh_coord.F / C);
    long long delta_col = abs(at_coord.F % C - neigh_coord.F % C);

    return (delta_row + delta_col) * clr
      + max(0LL, (long long)(at_coord.S - neigh_coord.S)) * cdn
      + max(0LL, (long long)(neigh_coord.S - at_coord.S)) * cup;
  }

//   long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr) {
  long long fly(long long R, long long C, vector <int> H, long long cup, long long cdn, long long clr) {
    vector<unordered_set<int>> current_heights(R * C);

    // ===stats===
    long long n_push = 0LL;
    long long n_pop = 0LL;
    long long n_dec = 0LL;
    long long n_while = 0LL;

    // ===Dijkstra===
    // dist
    unordered_map<coord_t, dist_t, hash_pair> dist;
    // priority queue (next_wakes)
    set<next_wakes_t> next_wakes;
    // visited
    unordered_set<coord_t, hash_pair> visited;

    int end_rc = R*C-1;
    int end_h = H[end_rc];
    coord_t end_coord = MP(end_rc,end_h);
    dist[end_coord] = INF;
    current_heights[end_rc].insert(end_h);

    // dist(start)
    coord_t start_coord = MP(0,H[0]);
    dist_t start_dist = 0LL; 
    dist[start_coord] = start_dist;
    // next_wakes <- start
    next_wakes.insert(MP(start_dist, start_coord));
    n_push++;
    current_heights[0].insert(H[0]);

    // until next_wakes empty
    while (!next_wakes.empty()) {
      n_while++;

      // (at_dist, at_coord) <- next_wakes.top
      next_wakes_t at = *next_wakes.begin();
      dist_t at_dist = at.F;
      coord_t at_coord = at.S;
      // next_wakes.pop
      next_wakes.erase(next_wakes.begin());
      n_pop++;
//       MSG(next_wakes.size());
//       MSG(at_coord.F); MSG(at_coord.S); MSG(at_dist); cerr << endl;

      // early stop
      if (at_coord == end_coord) {
        break;
      }

      // set `at` as visited
      visited.insert(at_coord);

      // optimize out coords already too far from end_coord
      if (dist.count(end_coord) > 0 &&
          dist[at_coord] + get_dist(at_coord, end_coord, C, clr, cdn, cup) >= dist[end_coord]) {
        continue;
      }

      // lazy Dijkstra: if (at_dist > dist[at_coord]) continue;
      if (at_dist > dist[at_coord]) {
        continue;
      }

      // vertical neighbors
      for (auto & neigh_h: current_heights[at_coord.F]) {
        // compute new_dist
        coord_t neigh_coord = MP(at_coord.F, neigh_h);
        dist_t new_dist = dist[at_coord] + get_dist(at_coord, neigh_coord, C, clr, cdn, cup);

        if (new_dist < dist[neigh_coord]) {   // optimize out redundant heights
          if (neigh_coord == end_coord) {
            dist[end_coord] = new_dist;
          } else {
            next_wakes.erase(MP(dist[neigh_coord], neigh_coord));
            n_dec++;
            current_heights[neigh_coord.F].erase(neigh_coord.S);
          }
        }
      }

      // horizontal neighbors
      for (auto & neigh_coord : get_neighbors(at_coord, R, C, H)) {
//         MSG(neigh_coord.F); MSG(neigh_coord.S);
        // if unvisited neighbor
        if (visited.count(neigh_coord) == 0) {
//           MSG(visited.count(neigh_coord)); cerr << endl;
          // compute new_dist
          dist_t new_dist = dist[at_coord] + get_dist(at_coord, neigh_coord, C, clr, cdn, cup);
          // new_dist < dist[neigh]?
          bool neigh_dist_undef = (dist.count(neigh_coord) == 0);
          if (neigh_dist_undef || new_dist < dist[neigh_coord]) {     // relax dist[neigh]
            if (!neigh_dist_undef) {
              next_wakes.erase(MP(dist[neigh_coord], neigh_coord));
              n_dec++;
            }

            dist[neigh_coord] = new_dist;

            // next_wakes <- push neigh
            next_wakes.insert(MP(new_dist, neigh_coord));
            n_push++;
            current_heights[neigh_coord.F].insert(neigh_coord.S);
          }
        }
      }
    }

    MSG(n_while); MSG(n_push); MSG(n_pop); MSG(n_dec);

    return dist[end_coord];
  }
};
