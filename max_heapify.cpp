// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//

/*merge sort : stable, non-inplace sorter*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void Max_Heapify(std::vector <int>& data, int root);

int main()
{
	int arr[10] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	std::vector<int> data(arr, arr+sizeof(arr)/sizeof(int));
	int n = data.size();
	
	Max_Heapify(data, 1);

	for (int i = 0; i < n; i++)
	{
		std::cout << data[i] << " ";
	}
	
	std::cout << std::endl;
}

void Max_Heapify(std::vector <int>& data, int root)
{
	int heap_size = data.size();
	int key_index = root;
	int largest;
	if (2 * key_index + 1 >= heap_size - 1)
		return;
	else if (2 * key_index + 1 == heap_size - 1)
	{
		if (data[key_index] <= data[2 * key_index + 1])
			swap(data[key_index], data[2 * key_index + 1]);
	}
	else
	{
		if (data[key_index] <= data[2 * key_index + 1])
			largest = 2 * key_index + 1;
		else
			largest = key_index;

		if (data[largest] <= data[2 * key_index + 2])
			largest = 2 * key_index + 2;

		swap(data[key_index], data[largest]);
		key_index = largest;
	}
	Max_Heapify(data, key_index);
}
