#include <iostream>

using namespace std;

class Spiral {
private:
  int x, y;
  int counter;

  // right, down, left, up
  const int dirx[4] = {0,1,0,-1};
  const int diry[4] = {1,0,-1,0};

  int dir;
  int** matrix;
public:
  Spiral() {
    reset();
  }

  void reset() {
    x = y = counter = dir = 0;
  }

  void step() {
    x += dirx[dir];
    y += diry[dir];
  }

  void next_dir() {
    dir++;
    dir %= 4;
  }

  void mark(int dim) {
    if (dim == 0) {
    } else if (dim == 1) {
      matrix[x][y] = ++counter;
    } else {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < dim-1; j++) {
          matrix[x][y] = ++counter;
          if (!(i == 3 && j == dim-2)) {
            step();
          }
        }
        next_dir();
      }

      step();
      mark(dim-2);
    }
  }

  int** spiral(int n) {
    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
      matrix[i] = new int[n];
    }

    reset();
    mark(n);
    return matrix;
  }

  void display_spiral(int n) {
    int** sp = spiral(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d\t", sp[i][j]);
      }
      printf("\n");
      delete sp[i];
    }
    delete sp;
  }
};


int main()
{
  Spiral sp;
  for (int i = 0; i <= 6; i++) {
    printf("%d x %d:\n", i, i);
    sp.display_spiral(i);
    printf("\n");
  }
  return 0;
}
