#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<iostream>
#include<string>

using namespace std;

#define MSG(a) cout << #a << " == " << (a) << endl;
//#define DEBUG

class BitSubstring {
public:
	void makeSubstring(int M, int N, int i, int j) {
		int top = N >> i << i;
		int mid = M << (31-i) >> (31-i) >> j << j;
		int bot = N << (31-j) >> (31-j);
		N = top ^ mid ^ bot;
	}

	int updateBits(int N, int M, int i, int j) {
#ifdef DEBUG
    MSG(M)
    MSG(i)
    MSG(j)

    MSG(N)
    MSG(N >> j)
    MSG(N >> j << j)
#endif
		int top = (N >> j) << j;
		int mid = M << i;
		int bot = N << (31-i) >> (31-i);
#ifdef DEBUG
    MSG(top)
    MSG(mid)
    MSG(bot)
#endif
		return top ^ mid ^ bot;
	}
};

int main() {
  BitSubstring bs;
  int res = bs.updateBits(0b10000000000, 0b10101, 2, 6);
  int req = 0b10001010100;
#ifdef DEBUG
  MSG(res) MSG(req)
#endif
  assert(res == req);
  return 0;
}
