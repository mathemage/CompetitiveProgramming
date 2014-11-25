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

class DiskSpace {
public:
	int minDrives(vector <int>, vector <int>);
};

int DiskSpace::minDrives(vector <int> used, vector <int> total) {
	int all_used = accumulate(used.begin(), used.end(), 0);
	sort(total.begin(), total.end());
	reverse(total.begin(), total.end());
	
	int res = 0;
	while (all_used > 0) {
		all_used -= total[res++];
	}
	return res;
}


double test0() {
	int t0[] = {300,525,110};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {350,600,115};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	DiskSpace * obj = new DiskSpace();
	clock_t start = clock();
	int my_answer = obj->minDrives(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int t0[] = {1,200,200,199,200,200};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1000,200,200,200,200,200};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	DiskSpace * obj = new DiskSpace();
	clock_t start = clock();
	int my_answer = obj->minDrives(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int t0[] = {750,800,850,900,950};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {800,850,900,950,1000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	DiskSpace * obj = new DiskSpace();
	clock_t start = clock();
	int my_answer = obj->minDrives(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
double test3() {
	int t0[] = {49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,
 49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
 50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	DiskSpace * obj = new DiskSpace();
	clock_t start = clock();
	int my_answer = obj->minDrives(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 49;
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
double test4() {
	int t0[] = {331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	DiskSpace * obj = new DiskSpace();
	clock_t start = clock();
	int my_answer = obj->minDrives(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
