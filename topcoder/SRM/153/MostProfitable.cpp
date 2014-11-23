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

class MostProfitable {
public:
	string bestItem(vector <int>, vector <int>, vector <int>, vector <string>);
};

string MostProfitable::bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items) {
	string best = "";
	int max = 0;
	for (int i = 0; i < items.size(); i++) {
		if (max < sales[i] * (prices[i] - costs[i])) {
			best = items[i];
			max = sales[i] * (prices[i] - costs[i]);
		}
	}
	return best;
}


double test0() {
	int t0[] = {100,120,150,1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {110,110,200,2000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {20,100,50,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	string t3[] = {"Video Card","256M Mem","CPU/Mobo combo","Complete machine"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	MostProfitable * obj = new MostProfitable();
	clock_t start = clock();
	string my_answer = obj->bestItem(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Complete machine";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {134};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	string t3[] = {"Service, at cost"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	MostProfitable * obj = new MostProfitable();
	clock_t start = clock();
	string my_answer = obj->bestItem(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {38,24};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {37,23};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1000,643};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	string t3[] = {"Letter","Postcard"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	MostProfitable * obj = new MostProfitable();
	clock_t start = clock();
	string my_answer = obj->bestItem(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {10,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {11,12};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	string t3[] = {"A","B"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	MostProfitable * obj = new MostProfitable();
	clock_t start = clock();
	string my_answer = obj->bestItem(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "A";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
