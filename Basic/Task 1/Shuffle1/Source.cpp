#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	int a;

	int deck[10];

	for (int i = 0; i <= 10; i++)
	{
		deck[i] = rand() % 11;
	}
	for (int i = 0; i <= 10; i++)
	{
		cout << deck[i] << " ";
	}
	cout << endl;


	//shuffle

	for (int i = 0; i <= 10; i++)
	{
		int j = rand() % 10;
		int x = deck[i];
		deck[i] = deck[j];
		deck[j] = x;
	}

	for (int i = 0; i <= 10; i++)
	{
		cout << deck[i] << " ";
	}
	cout << endl;

	cin >> a;
}