#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int number;
	int noOfTrailingZeroes=0;
	cin >> number;
	if (number < 5)
	{
		noOfTrailingZeroes = 0;
	}
	else
	{
		for (int i = 5; i <= number; i=i*5)
		{
			noOfTrailingZeroes = noOfTrailingZeroes + (number / i);
		}
	}
	cout << noOfTrailingZeroes << " trailing zeroes!";
	cin >> number;
}