// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//

/*stable, in-place*/

#include "stdafx.h"
#include <iostream>
#include <vector>

int main()
{
	int arr[6] = { 5, 1, 2, 8, 4, 2 };
	std::vector<int> data(arr, arr+sizeof(arr)/sizeof(int));
	int n = data.size();
	int isr = 0, key = 0, j=0;

	for (int i = 1; i < n; i++)
	{
		key = data[i];
		isr = i;
		j = i - 1;
		while (j >= 0 && data[j] > key)
		{
			isr = j;
			j--;
		}
		data.erase(data.begin() + i);
		data.insert(data.begin() + isr, key);
	}
	



//	std::cout << data.size() << std::endl;

	
	for (int i = 0; i < n; i++)
	{
		std::cout << data[i] << " ";
	}
	
	std::cout << std::endl;
}