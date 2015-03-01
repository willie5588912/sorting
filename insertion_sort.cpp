// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//

/*---insertion sort---
資料結構：linked list；inplace sorter；stable*/

#include "stdafx.h"
#include <iostream>
#include <list> 

int main()
{
	std::list<int> mylist;
	std::list<int>::iterator it_ins, it_pos;

	int arr[14] = { 15, -8, 20, -7, -7, 0, 0, 66, 66, 54, 18, 18, 15, 26 };	/*arr用來存放原始資料*/
	int n = sizeof(arr) / sizeof(int);
	int idx = 0, flag=0;


	/*initial setting：指標在第一個數值，不需要比較*/
	
	/*把arr的資料寫入list*/
	for (int i = 0; i < n; i++)		
		mylist.push_back(arr[i]);
	it_pos = mylist.begin();
	idx++;
	it_pos++;



	/*sorting：從第二個數值開始與前面排好的數列比較*/
	
	while (idx < n)
	{
		/*尋找正確位置（it_ins）以在他前方插入it_pos的數值*/
		it_ins = mylist.begin();
		flag = 0;	/*為了避免it_ins超過it_pos所作的控制（如果超過了會很麻煩，不好寫）*/
		while (*it_pos >= *it_ins && flag < idx)
		{
			it_ins++;
			flag++;
		}

		/*在正確位置（it_ins）插入數值（*it_pos）*/
		mylist.insert(it_ins, *it_pos);

		/*因為已經把it_pos的數值插入到前方數列的正確位置了，所以這裡要把原始it_pos所指向位置的數字給刪除
		（這樣才代表把數字調換到前方）*/
		it_pos= mylist.erase(it_pos);
	
		idx++;
	}

	/*result*/
	std::cout << "The sorted series is as following:" << std::endl;
	for (it_pos = mylist.begin(); it_pos != mylist.end(); it_pos++)
		std::cout << *it_pos << ' ';
	std::cout << std::endl;

}


