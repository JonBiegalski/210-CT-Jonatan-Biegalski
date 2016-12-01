/*
PSEUDOCODE:

//input: 2d arrays A and B of same size(n)
PROCEDURE Addition(A, B)
	2D array C<-empty							//1
	FOR1 i<-1 TO A.length DO					//N
		FOR2 j<-1 TO A.width DO					//N^2
			C[i][j]<- A[i][j] + B[i][j]			//N^2
		END FOR2								//N^2
	END FOR1									//N
	RETURN C									//1
END PROCEDURE									//O(N^2)

//input: 2d arrays A and B of same size(n)
PROCEDURE Subtraction(A, B)
	2D array C<-empty							//1
	FOR1 i<-1 TO A.length DO					//N
		FOR2 j<-1 TO A.width DO					//N^2
			C[i][j]<- A[i][j] - B[i][j]			//N^2
		END FOR2								//N^2
	END FOR1									//N
	RETURN C									//1
END PROCEDURE									//O(N^2)

//input: float X and 2d array A
PROCEDURE Multiplication_Scalar(X, A)
	2D array C<-empty							//1
	FOR1 i<-1 TO A.length DO					//N
		FOR2 j<-1 TO A.width DO					//N^2
			C[i][j]<- A[i][j] * X				//N^2
		END FOR2								//N^2
	END FOR1									//N	
	RETURN C									//1
END PROCEDURE									//O(N^2)

//input: 2d arrays A and B of same size(n)
PROCEDURE Multiplication_Matrices(A,B)
	2D array C<-empty							//1
	FOR1 i<-1 TO A.length DO					//N
		FOR2 j<-1 TO A.width DO					//N^2
			dot=0;								//N^2
			FOR3 m<-1 to A.width DO				//N^3
				dot=dot+A[i][m]*B[n][j]			//N^3
			END FOR3							//N^3
			C[i][j]=dot							//N^2
		END FOR2								//N^2
	END FOR1									//N
	RETURN C									//1
END PROCEDURE									//O(N^3)
*/

#include <iostream>
#include <vector>
using namespace std;

void Multi_Scalar(vector<vector<int>>& A, int X, vector<vector<int>>& out) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			out[i][j] = A[i][j] * X;
		}
	}
}

void Addition(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& out) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			out[i][j] = A[i][j] + B[i][j];
		}
	}
}

void Subtraction(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& out) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			out[i][j] = A[i][j] - B[i][j];
		}
	}
}

void Multiplication(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& out) {
	int dot;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dot = 0;
			for (int n = 0; n < 3; n++)
			{
				dot = dot + A[i][n] * B[n][j];
			}
			out[i][j] = dot;
		}
	}
}

int main() {
	vector<vector<int>> A{ {1,1,1},{1,1,1},{1,1,1} };
	vector<vector<int>> B{ { 1,1,1 },{ 1,1,1 },{ 1,1,1 } };
	vector<vector<int>> C{ {0,0,0}, {0,0,0}, {0,0,0} };
	vector<vector<int>> D{ { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	vector<vector<int>> E{ { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	vector<vector<int>> Answer{ { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	char a;

	//Answer=A*B-2*(A-B)

	//E=A*B
	cout << "multiplication" << endl;
	Multiplication(A, B, E);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<E[i][j]<<" ";
		}
		cout << endl;
	}
	//C=(A-B)
	cout <<endl<< "subtraction" << endl;
	Subtraction(A,B,C);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<C[i][j]<<" ";
		}
		cout << endl;
	}
	//D=2*C
	cout <<endl<< "multiplication scalar" << endl;
	Multi_Scalar(C, 2, D);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<D[i][j]<<" ";
		}
		cout << endl;
	}
	//Answer=E-D
	cout <<endl<< "subtraction" << endl;
	Subtraction(E, D, Answer);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<Answer[i][j]<<" ";
		}
		cout << endl;
	}
	cin >> a;
}