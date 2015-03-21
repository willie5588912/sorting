// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//

/*merge sort : stable, non-inplace sorter*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void Max_Heapify(std::vector <int>& data, int root);
void Build_Max_Heap(vector<int>& data);

int main()
{
	int arr[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	std::vector<int> data(arr, arr + sizeof(arr) / sizeof(int));
	int n = data.size();
	int heapSize = n;

	Build_Max_Heap(data);
	for (int i = 0; i < n; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;


	for (int i = data.size() - 1; i >= 1; i--) {
		swap(data[0], data[i]);
		heapSize--;
		Max_Heapify(data, 0);
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
}

void Build_Max_Heap(vector<int>& data)
{
	int heapSize = data.size(); //不用port過去
	for (int heapify_root = (heapSize - 2) / 2; heapify_root >= 0; heapify_root--)
		Max_Heapify(data, heapify_root);
}

void Max_Heapify(std::vector <int>& data, int root)
{
	int heap_size = data.size();	//port過去將所有heap_size改成SortTool裡面有的heapSize
	int key_index = root;
	int largest;
	if (2 * key_index + 1 > heap_size - 1)
		return;
	else if (2 * key_index + 1 == heap_size - 1)
	{
		if (data[key_index] <= data[2 * key_index + 1])
			swap(data[key_index], data[2 * key_index + 1]);
		return;
	}
	else
	{
		if (data[key_index] >= data[2 * key_index + 1] && data[key_index] >= data[2 * key_index + 2])
			return;
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
