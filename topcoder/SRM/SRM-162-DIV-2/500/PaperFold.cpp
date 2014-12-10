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

class PaperFold {
public:
	int numFolds(vector <int>, vector <int>);
};

int limitedFolds(int p1, int p2, int b1, int b2, int foldsLeft) {
	if (p1 <= b1 && p2 <= b2) return 0;
	if (p1 <= b2 && p2 <= b1) return 0;
	
	if (foldsLeft == 0) return -1;
	
	int n1 = limitedFolds(p1/2, p2, b1, b2, foldsLeft-1);
	int n2 = limitedFolds(p1, p2/2, b1, b2, foldsLeft-1);
	if (n1 == -1 && n2 == -1) return -1;
	else if (n1 == -1) return 1 + n2;
	else if (n2 == -1) return 1 + n1;
	else return 1 + min(n1, n2);
}

int PaperFold::numFolds(vector <int> paper, vector <int> box) {
	paper[0] *= 256;
	paper[1] *= 256;
	box[0] *= 256;
	box[1] *= 256;
	
	return limitedFolds(paper[0], paper[1], box[0], box[1], 8);
}


double test0() {
	int t0[] = {8, 11};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaperFold * obj = new PaperFold();
	clock_t start = clock();
	int my_answer = obj->numFolds(p0, p1);
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
	int t0[] = {11, 17};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaperFold * obj = new PaperFold();
	clock_t start = clock();
	int my_answer = obj->numFolds(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int t0[] = {11, 17};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaperFold * obj = new PaperFold();
	clock_t start = clock();
	int my_answer = obj->numFolds(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int t0[] = {1000,1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {62,63};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaperFold * obj = new PaperFold();
	clock_t start = clock();
	int my_answer = obj->numFolds(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {100,30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {60,110};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaperFold * obj = new PaperFold();
	clock_t start = clock();
	int my_answer = obj->numFolds(p0, p1);
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
double test5() {
	int t0[] = {1895, 6416};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {401, 1000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaperFold * obj = new PaperFold();
	clock_t start = clock();
	int my_answer = obj->numFolds(p0, p1);
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
