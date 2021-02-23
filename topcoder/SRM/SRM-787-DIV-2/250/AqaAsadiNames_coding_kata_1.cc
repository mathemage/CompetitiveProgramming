/* ========================================
 * Points/Time : 144.20
 * Total/ETA : 250
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
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

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


class AqaAsadiNames {
public:
  string getName(string Dad, string Mom, string FirstChild, string Gender) {
    string vowels = "AEIOUY";
    string token;

    map<string, vector<string>> parent;

    stringstream ss1(Dad);
    while (ss1 >> token) {
      parent["Boy"].PB(token);
    }
//     print_vector(parent["Boy"], "parent[Boy]");

    stringstream ss2(Mom);
    while (ss2 >> token) {
      parent["Girl"].PB(token);
    }
//     print_vector(parent["Girl"], "parent[Girl]");

    vector<string> sibling;
    stringstream ss3(FirstChild);
    while (ss3 >> token) {
      sibling.PB(token);
    }
//     print_vector(sibling, "sibling");

    string GenderFirst = count(ALL(vowels), sibling[0][0]) ? "Girl" : "Boy" ;

    string result;
    if (Gender != GenderFirst) {
      result = parent[Gender][1] + " " + parent[Gender][0];
    } else {
      result = parent[Gender][0] + " " + sibling[1];
    }

    return result;
  }
};
