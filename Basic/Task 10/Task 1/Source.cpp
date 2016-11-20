#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

void Longest_Subarray(vector<int>& arr, vector<int>& out)
{

	int subarray_start = 0;
	int subarray_length = 1;
	int longest_subarray_start = 0;
	int longest_subarray_length = 1;

	for (size_t i = 0,ilen=arr.size(); i<ilen; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;



	for (size_t i = 1, ilen = arr.size(); i<ilen; i++)
	{
		
		if (arr[i-1] < arr[i])
		{
			subarray_length++;
		}
		else
		{

			if (subarray_length > longest_subarray_length)
			{
				longest_subarray_start = subarray_start;
				longest_subarray_length = subarray_length;
			}
			subarray_start = i;
			subarray_length = 1;
		}
	}

	if (subarray_length > longest_subarray_length)
	{
		longest_subarray_start = subarray_start;
		longest_subarray_length = subarray_length;
	}


	//iterators
	auto start = next(arr.begin(), longest_subarray_start);
	auto end = next(arr.begin(), longest_subarray_start + longest_subarray_length);

	out.assign(start, end);
	for (int i : out)
	{
		cout << i << " ";
	}
	cout << endl;

}



int main() {
	vector<int> arr = {2,1,3,4,8,9,10,11,12,1};
	vector<int> vec;
	vector<int> longy;
	vec.assign(arr.begin(), next(arr.begin(), 10));
	
	Longest_Subarray(vec, longy);



	int a;
	cin >> a;
}