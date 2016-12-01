#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

void Multiplication(vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& out) {
	double dot;
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

map<pair<int,int>,double> into_sparse(vector<vector<double>> matrix){
	map<pair<int, int>, double> sparse;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != 0)
			{
				sparse[make_pair(i, j)] = matrix[i][j];
			}
		}
	}
	return sparse;
}

map<pair<int, int>, double> add_sparse(map<pair<int, int>, double> sparse1, map<pair<int, int>, double> sparse2) {
	map<pair<int, int>, double> result;
	for (map<pair<int, int>, double>::iterator it = sparse1.begin(); it != sparse1.end(); it++)
	{
		if (sparse2.find(make_pair(it->first.first, it->first.second)) != sparse2.end())
		{
			sparse2[make_pair(it->first.first, it->first.second)] = +sparse1[make_pair(it->first.first, it->first.second)];
		}
		else
		{
			sparse2[make_pair(it->first.first, it->first.second)] = sparse1[make_pair(it->first.first, it->first.second)];
		}
	}
	return sparse2;
}

map<pair<int, int>, double> subtract_sparse(map<pair<int, int>, double> sparse1, map<pair<int, int>, double> sparse2) {
	map<pair<int, int>, double> result;
	for (map<pair<int, int>, double>::iterator it = sparse1.begin(); it != sparse1.end(); it++)
	{
		if (sparse2.find(make_pair(it->first.first, it->first.second)) != sparse2.end())
		{
			sparse2[make_pair(it->first.first, it->first.second)] = -sparse1[make_pair(it->first.first, it->first.second)];
		}
		else
		{
			sparse2[make_pair(it->first.first, it->first.second)] = sparse1[make_pair(it->first.first, it->first.second)] * (-1);
		}
	}
	return sparse2;
}

void from_sparse(map<pair<int,int>,double> sparse, vector<vector<double>>& mat) {
	vector<vector<double>> matrix{ {0,0,0}, {0,0,0}, {0,0,0} };
	for (map<pair<int, int>, double>::iterator it = sparse.begin(); it != sparse.end();it++)
	{
		matrix[it->first.first][it->first.second] = it->second;
	}
	mat = matrix;
}

map<pair<int, int>, double> multiply_sparse(map<pair<int, int>, double> sparse1, map<pair<int, int>, double> sparse2) {
	vector<vector<double>> A{};
	vector<vector<double>> B{};
	vector<vector<double>> C{ { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	from_sparse(sparse1, A);
	from_sparse(sparse2, B);
	Multiplication(A, B, C);
	return(into_sparse(C));
}

int main() {
	vector<vector<double>> matrix{ {0,1.1,0}, {2.2,0,6.2}, {0,3,0} };
	vector<vector<double>> matrix2{ { 1,0,0.1 },{ 0,0,0 },{ 3.1,0,2 } };\
		vector<vector<double>> matri{};
	map<pair<int, int>, double> sparse;
	map<pair<int, int>, double> sparse2;
	map<pair<int, int>, double> sparse3;
	char a;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl<<endl;
	}
	
	sparse = into_sparse(matrix);
	sparse2 = into_sparse(matrix2);
	cout << "subtr sparse" << endl;
	sparse3 = subtract_sparse(sparse, sparse2);
	from_sparse(sparse3, matri);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matri[i][j] << "  ";
		}
		cout << endl<<endl;
	}
	cin >> a;
}