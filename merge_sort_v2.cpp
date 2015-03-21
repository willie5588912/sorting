// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//


#include "stdafx.h"
#include <iostream>
#include <vector>

void SortSubVector(std::vector<int>& data, int low, int high);
void Merge(std::vector<int>& data, int low, int middle1, int middle2, int high);

int main()
{
	int arr[9] = { 4, 3, 5, 1, 2, 8, 7, 9, 3};
	std::vector<int> data(arr, arr+sizeof(arr)/sizeof(int));
	int n = data.size();
	
	SortSubVector(data, 0, data.size() - 1);

	
	for (int i = 0; i < n; i++)
	{
		std::cout << data[i] << " ";
	}
	
	std::cout << std::endl;
}


void SortSubVector(std::vector<int>& data, int low, int high)
{
	int mid;
	if (low == high)
		return;
	mid = (low + high) / 2;
	SortSubVector(data, low, mid);
	SortSubVector(data, mid + 1, high);
	Merge(data, low, mid, mid + 1, high);
}

void Merge(std::vector<int>& data, int low, int middle1, int middle2, int high)
{

}