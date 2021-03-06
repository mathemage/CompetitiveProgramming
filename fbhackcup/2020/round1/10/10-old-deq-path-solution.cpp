 
/* ========================================

   * File Name : 10.cpp

   * Creation Date : 16-08-2020

   * Last Modified : Ne 16. srpna 2020, 16:40:04

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2020/round-1/problems/A1

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;

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

#define UNDEF -42
typedef pair<int, int> coord;

int N, K, W;
long long AL, BL, CL, DL;
long long AH, BH, CH, DH;

int dist(coord ptA, coord ptB) {
  return abs(ptA.first - ptB.first) + abs(ptA.second - ptB.second);
}

int get_result(const vector<int> & L, const vector<int> & H) {
//   REP(k,K) MSG(L[k]);
//   REP(k,K) MSG(H[k]);

  int Pi = 0;
  int result = 0;    // TODO

  int Li, Hi;
  deque<coord> deq_pts;
//   deque<coord> deq_pts = { {3,9}, {4, 2} };  // TODO

  // streamline via the recurrence
  deque<int> deqL;
  deqL.push_back(L[K-2]);
  deqL.push_back(L[K-1]);

  deque<int> deqH;
  deqH.push_back(H[K-2]);
  deqH.push_back(H[K-1]);

  REP(i,N) {
//     cout << endl; MSG(i);

    if (i < K) {
      Li = L[i];
      Hi = H[i];
    } else {
      Li = (AL * (long long) deqL[0] + BL * (long long) deqL[1] + CL) % DL + 1;
      deqL.push_back(Li);
      deqL.pop_front();

      Hi = (AH * (long long) deqH[0] + BH * (long long) deqH[1] + CH) % DH + 1;
      deqH.push_back(Hi);
      deqH.pop_front();

//       MSG(deqL.size()); for (auto & v: deqL) cout << v << " "; cout << endl;
//       MSG(deqH.size()); for (auto & v: deqH) cout << v << " "; cout << endl;
    }
//     MSG(Li);
//     MSG(Hi);

    if (i >= 1) {   // empty deq_pts when if a new (disconnected) polygon
      int Li_1 = (i < K) ? L[i-1] : deqL[0];
      if (Li_1 + W < Li) {  // new (disconnected) polygon
//         MSG(deq_pts.size()); for (auto & v: deq_pts) cout << "(" << v.first << "," << v.second << ")"; cout << endl;
        deq_pts.resize(0);
//         MSG(deq_pts.size()); for (auto & v: deq_pts) cout << "(" << v.first << "," << v.second << ")"; cout << endl;
      }
    }

    // unwind covered boundary & decrement its length - TODO test
    coord pt0, pt1;
    coord intersect = {UNDEF, UNDEF};
    while (deq_pts.size() >= 2) {
      pt0 = deq_pts.back();
      deq_pts.pop_back();

      pt1 = deq_pts.back();
      if (Li <= pt1.first && pt1.second <= Hi) {     // covered
        Pi -= dist(pt1, pt0);     //  decrement its length
      } else {                    // 1st outside the new rectangle
        // compute intersection point - TODO test
        if (pt1.first == pt0.first) {            // aligned columns
          intersect = {pt1.first, Hi};
        } else if (pt1.second == pt0.second) {   // aligned rows
          intersect = {Li, pt1.second};
        }

        // decrement the dist to intersect  - TODO test
        Pi -= dist(intersect, pt0);

        break;
      }
    }
    
    // pop front pts too much left (i.e. further than `w` distance) - TODO test
    while (!deq_pts.empty() && deq_pts.front().first < Li) {
      deq_pts.pop_front();
    }

    // TODO push back new boundary
    
    // intersect -> new boundary TODO test
    if (intersect.first == UNDEF || intersect.second == UNDEF) {
      return UNDEF;
    } else {
      deq_pts.push_back(intersect);
    }
    
    // TODO top left -> new boundary
    deq_pts.push_back({Li, Hi});  

    deq_pts.push_back({Li+W, Hi}); // top right -> new boundary
    deq_pts.push_back({Li+W, 0});  // bottom right -> new boundary
    
    // TODO increment its length
  }

  return result;
}

int main() {
  int T;
  cin >> T;
//   MSG(T);

  REP(t,T) {
    cin >> N >> K >> W;
//     cout << endl; MSG(N); MSG(K); MSG(W);

    vector<int> L(N);
    REP(k,K) {
      cin >> L[k];
    }
    cin >> AL >> BL >> CL >> DL;
//     MSG(AL); MSG(BL); MSG(CL); MSG(DL);

    vector<int> H(N);
    REP(k,K) {
      cin >> H[k];
    }
    cin >> AH >> BH >> CH >> DH;
//     MSG(AH); MSG(BH); MSG(CH); MSG(DH);

    cout << "Case #" << t + 1 << ": " << get_result(L, H) << endl;
  }

//   MSG(dist({39,42}, {39,39})); MSG(dist({42,42}, {39,42})); // validate dist()

  return 0;
}
