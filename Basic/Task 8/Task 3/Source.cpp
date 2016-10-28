#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string No_Vowels(string S) {
	cout << S << endl;
	if (S == "")
	{
		return "";
	}
	else
	{
		if (S[0] == 'a' || S[0] == 'e' || S[0] == 'i' || S[0] == 'o' || S[0] == 'u')
		{
			return No_Vowels(S.substr(1));
		}
		else
		{
			return S[0] + No_Vowels(S.substr(1));
		}
	}
}

int main() {
	char a;
	string S,X;
	cin >> S;
	cout << S << endl;
	X=No_Vowels(S);
	cout << X << endl;
	cin >> a;
}