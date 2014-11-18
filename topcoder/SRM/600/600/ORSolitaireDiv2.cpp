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

class ORSolitaireDiv2 {
public:
	int getMinimum(vector <int>, int);
};

int ORSolitaireDiv2::getMinimum(vector <int> numbers, int goal) {
	// filter by bitmask
	unsigned int bm = goal;
	vector <int> ns;
	for (unsigned n : numbers) {
		if (n == (bm & n)) {
			ns.push_back(n);
		}
	}

	vector <int> counts;
	unsigned int g = goal;
	cout << "g is " << g << " goal is " << goal << endl;
	
	int width = 0;
	while (g) {
		counts.push_back(0);
		g >>= 1;
		width++;
	}
	
	for (unsigned int n : ns) {
		cout << endl << "Inspecting n == " << n << endl;
		g = goal;
		for (int i = 0; i < width; i++) {
			counts[i] += n%2;
			n >>= 1;
			g >>= 1;
		}
		for (int c : counts) {
			cout << c << " ";
		}
	}
	
	int m = 21;
	g = goal;
	for (int c : counts) {
		if (g%2) m = min(c, m);
		g >>= 1;
	}
	return m;
}


double test0() {
	int t0[] = {1,2,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 7;
	ORSolitaireDiv2 * obj = new ORSolitaireDiv2();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
double test1() {
	int t0[] = {1, 2, 4, 7, 8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 7;
	ORSolitaireDiv2 * obj = new ORSolitaireDiv2();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
double test2() {
	int t0[] = {12571295, 2174218, 2015120};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	ORSolitaireDiv2 * obj = new ORSolitaireDiv2();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	int t0[] = {5, 2, 4, 52, 62, 9, 8, 3, 1, 11, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 11;
	ORSolitaireDiv2 * obj = new ORSolitaireDiv2();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 510;
	ORSolitaireDiv2 * obj = new ORSolitaireDiv2();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
