#include<vector>
using namespace std;

class YahtzeeScore {
public:
	int maxPoints(vector<int> toss) {
		int counts[6] = {0,0,0,0,0,0};
		for (int& t : toss) {
			counts[t]++;
		}
		int max = 0;
		for (int i = 0; i < 6; i++) {
			if (max < counts[i] * i) {
				max = counts[i] * i;
			}
		}
		return 0;
	}
};
