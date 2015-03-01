// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//



#include "stdafx.h"
#include <iostream>
#include <list> 

int main()
{
	std::list<int> mylist;
	std::list<int>::iterator it_ins, it_pos;

	int arr[14] = { 15, -8, 20, -7, -7, 0, 0, 66, 66, 54, 18, 18, 15, 26 };
	int n = sizeof(arr) / sizeof(int);
	int idx = 0, flag=0;

	/*initial setting*/
	for (int i = 0; i < n; i++)
		mylist.push_back(arr[i]);
	it_pos = mylist.begin();
	idx++;
	it_pos++;

	/*sorting*/
	while (idx < n)
	{
		it_ins = mylist.begin();
		flag = 0;
		while (*it_pos >= *it_ins && flag < idx)
		{
			it_ins++;
			flag++;
		}
		mylist.insert(it_ins, *it_pos);
		it_pos= mylist.erase(it_pos);
	
		idx++;
	}

	std::cout << "The sorted series is as following:" << std::endl;
	for (it_pos = mylist.begin(); it_pos != mylist.end(); it_pos++)
		std::cout << *it_pos << ' ';
	std::cout << std::endl;

}


