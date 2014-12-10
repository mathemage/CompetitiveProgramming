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
#include <cassert>

using namespace std;

#define MSG(a) cout << #a << " == " << a << endl;

//#define DEB

int scores[26][7];
vector<int> sizes(26);

class CrossCountry {
public:
	struct comp {
		bool operator() (const char & a, const char & b) {
			int ia = a - 'A';
			int ib = b - 'A';
			int sa = accumulate(scores[ia], scores[ia] + 5, 0);
			int sb = accumulate(scores[ib], scores[ib] + 5, 0);

#ifdef DEB
			printf("a %c\t b %c\t sa %d\t sb %d\n", a, b, sa, sb);
#endif
			
			if (sa != sb) return sa < sb;
			else if (sizes[ia] >= 6 || sizes[ib] >= 6) {
			 	if (sizes[ia] >= 6  &&  sizes[ib] >= 6) return scores[ia][5] < scores[ib][5];
				if (sizes[ia] < 6) return false;
				if (sizes[ib] < 6) return true;
			} else {
				return a < b;
			}
		}
	};
	
	string scoreMeet(int, string);
};

string CrossCountry::scoreMeet(int numTeams, string f) {
	for (int i = 0; i < 26*7; i++) scores[i/7][i%7] = 0;
	sizes.assign(26,0);

	for (int i = 0; i < f.size(); i++) {
		int id = f[i] - 'A';
#ifdef DEB
		printf("i %d\t f[i] %c\t id %d\n", i, f[i], id);
#endif
		scores[id][ sizes[id]++ ] = i+1;
	}

#ifdef DEB
	for (int i = 0; i < numTeams; i++) {
		MSG(i)
		for (int j = 0; j < sizes[i]; j++) {
			printf("%d\t", scores[i][j]);
		}
		printf("\n");
	}
#endif

	vector<char> teams;
	for (int i = 0; i < numTeams; i++) {
		if (sizes[i] >= 5) teams.push_back('A' + i);
	}
	
#ifdef DEB			
	for (char t : teams) printf("%c", t);
	printf(" -> team\n");
#endif

	sort(teams.begin(), teams.end(), comp());
	
	string res;
	for (char t : teams) {
		res += t;
	}
	return res;
}


double test0() {
	int p0 = 2;
	string p1 = "AABBABBABBA";
	CrossCountry * obj = new CrossCountry();
	clock_t start = clock();
	string my_answer = obj->scoreMeet(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "AB";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 3;
	string p1 = "CCCBBBBBAAACC";
	CrossCountry * obj = new CrossCountry();
	clock_t start = clock();
	string my_answer = obj->scoreMeet(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "BC";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 4;
	string p1 = "ABDCBADBDCCDBCDBCAAAC";
	CrossCountry * obj = new CrossCountry();
	clock_t start = clock();
	string my_answer = obj->scoreMeet(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "BDCA";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 10;
	string p1 = "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG";
	CrossCountry * obj = new CrossCountry();
	clock_t start = clock();
	string my_answer = obj->scoreMeet(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "BCDAHEG";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 3;
	string p1 = "BABCAABABAB";
	CrossCountry * obj = new CrossCountry();
	clock_t start = clock();
	string my_answer = obj->scoreMeet(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "AB";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
