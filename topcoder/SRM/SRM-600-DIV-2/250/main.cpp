#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

class TheShuttles
{
public:
  int getLeastCost(vector<int> cnt, int baseCost, int seatCost) {
    //const int l = *min_element(cnt.begin(), cnt.end());
    const int u = *max_element(cnt.begin(), cnt.end());
    int ans = 0;

    for (int x = 1; x <= u; x++) {
      int shuttles = 0;
      for (int c : cnt) {
        shuttles += (c%x != 0) ? (c/x + 1) : (c/x);
      }
      // cost
      if (ans) {
        ans = min(ans, shuttles * (baseCost + x * seatCost));
      } else {
        ans = shuttles * (baseCost + x * seatCost);
      }
    }
    return ans;
  }
};

int main()
{
  TheShuttles ts;
  vector<int> v1 = {9};
  vector<int> v2 = {9, 4};
  vector<int> v3 = {51, 1, 77, 14, 17, 10, 80};
  vector<int> v4 = {5, 6};
  assert(ts.getLeastCost(v1, 30, 5) == 75);
  assert(ts.getLeastCost(v2, 30, 5) == 150);
  assert(ts.getLeastCost(v2, 10, 5) == 105);
  assert(ts.getLeastCost(v3, 32, 40) == 12096);
  assert(ts.getLeastCost(v4, 1, 100) == 1111);
  return 0;
}

