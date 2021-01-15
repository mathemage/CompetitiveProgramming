/* ========================================
 * Points :
   * 2h 11m 25s 
   * 2h 26m 30s (308.77/1000) 
   * 2h 30m 40s (300/1000) 
   * 2h 39m 50s (300/1000) 
   * 2h 46m 50s (300/1000) 
   * 3h  1m 10s (300/1000) 
 * Total : 1000
 * Status : TLE - WA - TLE (x2) - TLE #12 - TLE #7,#14,#13
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


class FlightPlan {
public:
  typedef pair<int, int> coord_t;   // (xy position, height)
  typedef long long dist_t;
  typedef pair<dist_t, coord_t> pq_t;

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

  vector<coord_t> get_neighbors(coord_t at_coord, int R, int C, vector<int> & H, vector<unordered_set<int>> & current_heights) {
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

    // vertical neighbors
    for (auto & neigh_h : current_heights[at_coord.F]) {
      if (neigh_h != at_height) {
        neighbors.PB(MP(at_coord.F, neigh_h));
      }
    }

    return neighbors;
  }

//   long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr) {
  long long fly(int R, int C, vector <int> H, long long cup, long long cdn, long long clr) {
    vector<unordered_set<int>> current_heights(R * C);

    // ===Dijkstra===
    // dist
    unordered_map<coord_t, dist_t, hash_pair> dist;
    // priority queue (PQ)
    auto cmp = [](pq_t left, pq_t right) { return (left.F) > (right.F); };
    priority_queue<pq_t, vector<pq_t>, decltype(cmp)> pq(cmp);
    // visited
    unordered_set<coord_t, hash_pair> visited;
    // dist(start)
    coord_t start_coord = MP(0,H[0]);
    dist_t start_dist = 0LL; 
    dist[start_coord] = start_dist;
    // PQ <- start
    pq.push(MP(start_dist, start_coord));
    current_heights[0].insert(H[0]);

    int end_rc = R*C-1;
    int end_h = H[end_rc];
    coord_t end = MP(end_rc,end_h);
    current_heights[end_rc].insert(end_h);

    // until PQ empty
    while (!pq.empty()) {
      // (at_dist, at_coord) <- PQ.pop
      pq_t at = pq.top();
      dist_t at_dist = at.F;
      coord_t at_coord = at.S;
      pq.pop();
//       MSG(pq.size());
//       MSG(at_coord.F); MSG(at_coord.S); MSG(at_dist); cerr << endl;

      if (at_coord == end) {
        break;
      }

      // set `at` as visited
      visited.insert(at_coord);

      // if (at_dist > dist[at_coord]) continue;
      if (at_dist > dist[at_coord]) {
        continue;
      }

      // for neighbors
      for (auto & neigh_coord : get_neighbors(at_coord, R, C, H, current_heights)) {
//         MSG(neigh_coord.F); MSG(neigh_coord.S);
        // if unvisited neighbor
        if (visited.count(neigh_coord) == 0) {
//           MSG(visited.count(neigh_coord)); cerr << endl;
          // new_dist =
          dist_t new_dist = dist[at_coord]
            + (at_coord.F != neigh_coord.F) * clr
            + max(0LL, (long long)(at_coord.S - neigh_coord.S)) * cdn
            + max(0LL, (long long)(neigh_coord.S - at_coord.S)) * cup;
          // new_dist < dist[neigh]?
          bool neigh_dist_undef = dist.count(neigh_coord) == 0;
          if (neigh_dist_undef || new_dist < dist[neigh_coord]) {
            // relax dist[neigh]
            dist[neigh_coord] = new_dist;

            if (at_coord.F == neigh_coord.F && !neigh_dist_undef) {   // optimize out redundant heights
              current_heights[neigh_coord.F].erase(neigh_coord.S);
            } else {
              // PQ <- neigh
              pq.push(MP(new_dist, neigh_coord));
              current_heights[neigh_coord.F].insert(neigh_coord.S);
            }
          }
        }
      }
    }

    return dist[end];
  }
};
