#include <cstdlib>
#include <iostream>

using namespace std;

const int eggs_per_day=3;
const int days_to_hatch=5;
int day = 1;

void egg_day(int ar[]){
	ar[0] = ar[0] + ar[1];
	for (int i = 1; i < days_to_hatch-1; i++)
	{
		ar[i] = ar[i + 1];
	}
	ar[days_to_hatch - 1] = ar[0] * eggs_per_day;
	cout << "Day " << day << endl;
	for (int i = 0; i <= days_to_hatch-1; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
	day++;
}

int main() {
	int a;
	int ar[days_to_hatch]{ 1,0,0,0,0 };

	for (int i = 0; i <= 4; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
	for(int i=0;i<=30;i++)
	{
		egg_day(ar);
	}
	cin >> a;
}