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