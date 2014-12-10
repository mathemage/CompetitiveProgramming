#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class SMBus {
	enum state { trans, idle, done };
	vector<state> states;
	int total, sz, digitIndex;
public:
	int transmitTime(vector <string>, vector <int>);

	bool finishedMaster(vector<string> & ms) {
		for (int i = 0; i < sz; i++) {
//			printf("i %d\t sz %d\n", i, sz);
			if (states[i] == trans && digitIndex >= ms[i].size()) {
				states[i] = done;
				return true;
			}
		}
		return false;
	}

	void nextMessage(vector<string> ms, vector<int> ts) {
		digitIndex = 0;
		int mstr;

		for (mstr = 0; mstr < sz; mstr++) {
			if (states[mstr] == idle) {
				states[mstr] = trans;
			}
		}
						
		while (!finishedMaster(ms)) {
			// get lowest byte
			char lB = '9' + 1;
			for (mstr = 0; mstr < sz; mstr++) {
				if (states[mstr] == trans) {
					lB = min(lB, ms[mstr][digitIndex]);
				}
			}
			
			int delay = 0;
			for (mstr = 0; mstr < sz; mstr++) {
				if (states[mstr] == trans) {
					delay = max(delay, ts[mstr]);
					if (ms[mstr][digitIndex] > lB) {
						states[mstr] = idle;
					}
				}				
			}
			
			total += delay;
			
			printf("digitIndex %d\t total %d\t", digitIndex, total);
			display();
			
			digitIndex++;
		}
		
		cout << "Next message..." << endl;
		if (! all_of(states.begin(), states.end(), [](state s){return s == done;} ) ) {
			nextMessage(ms, ts);
		}
	}
						
	void display() {
		for (state s : states) {
			switch (s) {
			case trans:
				cout << "t";
				break;
			case idle:
				cout << "i";
				break;
			case done:
				cout << "d";
				break;
			}
		}
		cout << endl;
	}
};

int SMBus::transmitTime(vector <string> messages, vector <int> times) {
	sz = messages.size();
	states.assign(sz, idle);
	total = 0;
	
	nextMessage(messages, times);
	
	return total;
}


double test0() {
	string t0[] = {"123","124","134"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SMBus * obj = new SMBus();
	clock_t start = clock();
	int my_answer = obj->transmitTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 25;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"012", "1234", "1233", "1223", "1123"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {4,1,5,2,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SMBus * obj = new SMBus();
	clock_t start = clock();
	int my_answer = obj->transmitTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 94;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"0002019289019101039663222896280025447",
 "00201873554718989597528841094293294387326",
 "010699029378761", "0110118", "011143279122561420",
 "001046384966198", "00200570375817801109530240012",
 "0003163277589822", "01100240744590150136673219652442108",
 "012033596872642679096489479354", "0121059494098",
 "00001002303019117948961792176", "00216399923558", "02014",
 "00224999120803846121427603894967637446889670369",
 "01101009414735635151893037596051740080475886",
 "0000101211809647472761605153430927981533514",
 "176845042961739039392207791589",
 "02000047506929386333221966659552927385017901842706",
 "021001117450487502127241076595509511",
 "021010776262723557108100899515",
 "0210114830738951774606917781619656",
 "0211798433083855430", "00000005842153604632996228135814",
 "0001000766929248550736138555144997170272757787",
 "0001010247593342056062432721557",
 "01100004828618452515832113396660046634951",
 "0132559984733529872911444204991646138116334788",
 "0224149857349431864906523152249992",
 "00001142929552573133212195441932219",
 "0011090498947092002457447355036811372647896489218",
 "000001275414757476198997466", "00010014",
 "00111025861963467834393486017602553072649743",
 "000102085", "00120882661783539",
 "01100018938145727291185020",
 "01100191373790478446634214244459341793", "0001129060",
 "001111287431066271555393813846448",
 "011010160778408696098486370196313", "0002125146381515395"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
 87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
 2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SMBus * obj = new SMBus();
	clock_t start = clock();
	int my_answer = obj->transmitTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 71048;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


//Powered by [KawigiEdit] 2.0!
