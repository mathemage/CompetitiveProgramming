#include<cassert>
#include<vector>
using namespace std;

class YahtzeeScore {
public:
  int maxPoints(vector<int> toss) {
    int counts[6] = {0,0,0,0,0,0};
    for (int& t : toss) {
      counts[t-1]++;
    }
    int max = 0;
    for (int i = 0; i < 6; i++) {
      if (max < counts[i] * (i+1)) {
        max = counts[i] * (i+1);
      }
    }
    return max;
  }
};

int main() {
  YahtzeeScore ys;
  vector<int> v1 = {2, 2, 3, 5, 4};
  vector<int> v2 = {6,4,1,1,3};
  assert(ys.maxPoints(v1) == 5);
  assert(ys.maxPoints(v2) == 6);
}
