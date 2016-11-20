/*
Use binary search to find if there are values within the specified interval
PSEUDOCODE
INPUT: Integer array X, Int Low, Int High

PROCEDURE Binary_Interval(X, low, high)
	IF1 (X[middle]<high AND X[middle]>low)
		RETURN True
	END IF1
	ELSE1
		IF2 (X.Length=1)
			RETURN False
		END IF2
		IF3 X[middle]>low
			Binary_Interval(X(without last), low, high)
		END IF3
		ELSE2
			Binary_Interval(X(without first), low, high)
		END ELSE2
	END ELSE1
END PROCEDURE
*/

#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>

using namespace std;

bool Binary_Interval(int X[],int first, int last,int low, int high) {
	int middle = (first + last) / 2;
	if (X[middle]<high && X[middle]>low)
	{
		return true;
	}
	else
	{
		if (first == last)
		{
			return false;
		}
		if (X[middle] > low)
		{
			Binary_Interval(X, first, last-1, low, high);
		}
		else
		{
			Binary_Interval(X, first+1, last , low, high);
		}

	}
}

int main() {
	int low,high,a;
	int X[10] = { 1, 3, 4, 5, 7, 8, 10, 13, 16, 18 };
	cout << "lower:";
	cin >> low;
	cout << endl;
	cout << "higher:";
	cin >> high;
	cout << endl;
	if (Binary_Interval(X, 0, 9, low, high))
	{
		cout << "It's there"<<endl;
	}
	else
	{
		cout << "Not there"<<endl;
	}

	cin >> a;
}