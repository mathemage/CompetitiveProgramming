#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

class ExerciseMachine {
public:
	int getPercentages(string time) {
		int hours = (time[0] - '0') * 10 + time[1] - '0';
		int mins = (time[3] - '0') * 10 + time[4] - '0';
		int secs = (time[6] - '0') * 10 + time[7] - '0';
		int total = (60 * hours + mins) * 60 + secs;
		int period = total % 100;

		int k = 1;
		for (; k <= 100; k++) {
			if ((k * period) % 100 == 0) {
				break;
			}
		}

		return 99 / k;
	}
};

int main() {
  ExerciseMachine em;
  assert( em.getPercentages("00:30:00") == 99);
  assert( em.getPercentages("00:28:00") == 19);
}
