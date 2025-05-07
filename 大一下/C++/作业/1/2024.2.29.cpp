#include<iostream>
using namespace std;

class Solution_02_29
{
public:
	double GetTrapezoidArea() {
		int up = 10, down = 30, height = 10;
		double s = (double)(up + down) * height / 2;
		return s;
	}

	double GetAverage(int a, int b, int c) {
		double average = (double)(a + b + c) / 3;
		return average;
	}
};

void test_02_29() {
	double s = Solution_02_29().GetTrapezoidArea();
	int score1, score2, score3;
	cin >> score1 >> score2 >> score3;
	double a = Solution_02_29().GetAverage(score1, score2, score3);
	cout << s << endl << a;
}