// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//

/*merge sort : stable, non-inplace sorter*/

#include "stdafx.h"
#include <iostream>
#include <vector>

void SortSubVector(std::vector<int>& data, int low, int high);
void Merge(std::vector<int>& data, int low, int middle1, int middle2, int high);

int main()
{
	int arr[8] = { 15, 8, 20, 7, 66, 54, 18, 26};
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
	int i_record, j_record;
	std::vector<int> data_temp;
	
	int i = low;
	int j = middle2;
	for (; i <= middle1 && j <= high;)
	{
		i_record = i;
		j_record = j;
		if (data[i] <= data[j])
		{
			data_temp.push_back(data[i]);
			i++;
		}
		else
		{
			data_temp.push_back(data[j]);
			j++;
		}
	}

	if (i == middle1 + 1) 
	{
		for (; j_record <= high; j_record++)		
			data_temp.push_back(data[j_record]);
	}
	else if (j == high + 1)
	{
		for (; i_record <= middle1; i_record++)
			data_temp.push_back(data[i_record]);
	}

	int p = low;
	for (int k = 0; k < data_temp.size(); k++)
	{
		data[p] = data_temp[k];
		p++;
	}
}
