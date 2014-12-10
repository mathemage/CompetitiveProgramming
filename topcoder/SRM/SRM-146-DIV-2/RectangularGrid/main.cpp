#include<cassert>

class RectangularGrid {
public:
  long long countRectangles(int w, int h) {
    long long result = 0;
    for (int i = 1; i <= w; i++) {
      for (int j = 1; j <= h; j++) {
        result += (i == j) ? 0 : (w+1-i)*(h+1-j);
      }
    }
    return result;
  }
};

int main() {
  RectangularGrid rg;
  assert(rg.countRectangles(3, 3) == 22);
  assert(rg.countRectangles(5, 2) == 31);
}
