/*
Pseudocode:
//INPUT: List of words in sentence - Sentence[]
PROCEDURE Sentence_Reverse()
	string x<-""										//1
	FOR1 i<-0 TO i<Sentence.Length/2 DO					//N/2
		x<-Sentence[i]									//N/2
		Sentence[i]<-Sentence[Sentence.Length-i]		//N/2
		Sentence[Sentence.Length-i]<-x					//N/2
	END FOR1											//N/2
	RETURN Sentence[]									//1
END PROCEDURE											// Big O: O(N/2)
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Sentence_Reverse(vector<string>& sentence) {
	string x = "";
	for (size_t i = 0; i < sentence.size()/2; i++)
	{
		x = sentence[i];
		sentence[i] = sentence[sentence.size() - 1 - i];
		sentence[sentence.size() - 1 - i] = x;
	}
}

void split_sentence(string sentence, vector<string> &out)
{
	string word="";
	for(int i=0;i<sentence.length();i++)
	{
		if(sentence[i]==' ')
		{
			out.push_back(word);
			word="";
		}
		else
		{
			word=word+sentence[i];
		}
		
	}
	out.push_back(word);
}

int main() {
	char a;
	string sent="This is really so gosh darn freaking awesome";
	vector<string> sentence = {};
	split_sentence(sent,sentence);
	for (size_t i = 0, ilen = sentence.size(); i<ilen; i++)
	{
		cout << sentence[i] << " ";
	}
	cout << endl;
	Sentence_Reverse(sentence);
	for (size_t i = 0, ilen = sentence.size(); i<ilen; i++)
	{
		cout << sentence[i] << " ";
	}
	cin >> a;
}