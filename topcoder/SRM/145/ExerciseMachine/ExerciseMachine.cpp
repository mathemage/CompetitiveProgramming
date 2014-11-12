#include<string>
using namespace std;

class ExerciseMachine {
public:
	int getPercentages(string time) {
		int hours = (time[0] - '0') * 10 + time[1];
		int mins = (time[3] - '0') * 10 + time[4];
		int secs = (time[5] - '0') * 10 + time[6];
		int total = (60 * hours + mins) * 60 + secs;
		int period = total % 100;
		
		int k = 0;
		for (; k < 60; k++) {
			if ((k * period) % 60 == 0) {
				break;
			}
		}
		
		return 100 / k;
	}
};
