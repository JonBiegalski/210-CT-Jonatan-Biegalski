/*
//INPUT: Integer N, Integer num<-N-1
PROCEDURE Is_Prime(N, num)
	IF1 num=1 DO
		RETURN false
	END IF1
	ELSE1 DO
		IF2 (N mod num)=0 DO
			RETURN true
		END IF2
		ELSE2 DO
			RETURN Is_Prime(N,num-1)
		END ELSE2
	END ELSE1
END PROCEDURE
*/
#include <iostream>
#include <cstdlib>

using namespace std;

bool Is_Prime(int N, int num) {
	if (num == 1)
	{
		return true;
	}
	else
	{
		if (N%num == 0)
		{
			return false;
		}
		else
		{
			return Is_Prime(N, num - 1);
		}
	}
}

int main() {
	int N, a;
	bool isprime;
	cin >> N;
	isprime = Is_Prime(N, N-1);
	cout << isprime << endl;
	cin >> a;
}