#include <cassert>
#include <vector>
using namespace std;

class WidgetRepairs {
public:
  int days(vector<int> arrs, int numPerDay) {
    int ans = 0;
    int stack = 0;
    for (int d : arrs) {
      stack += d;
      if (stack > 0) {
        ans++;
      }
      stack -= numPerDay;
      if (stack < 0) {
        stack = 0;
      }
    }
    while (stack > 0) {
      stack -= numPerDay;
      ans++;
    }
    return ans;
  }
};

int main()
{
  WidgetRepairs wr;
  vector<int> v1 = { 10, 0, 0, 4, 20 };
  assert (wr.days(v1, 8) == 6);
  return 0;
}

