// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

void sort(int *p_arr, int i);
void swap(int &a, int &b);
void bubble_sort(int *p_arr, int n);

int main()
{
	int arr[5] = {18, 2, 20, 34, 12};
	int n = sizeof(arr) / sizeof(int);


	bubble_sort(arr, n);


	std::cout << "The sorted array is as following:" << std::endl;
	for (int i = 0; i<n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout<< std::endl;
}

void bubble_sort(int *p_arr, int n)
{
	for (int stage = 1; stage <= n - 1; stage++)
	{
		int round = n - stage;
		for (int i = 0; i <= round - 1; i++)
		{
			sort(p_arr, i);
		}
	}
}

/***
這個sort function只排序兩個數字
***/

void sort(int *p_arr, int i)
{
	if (p_arr[i]> p_arr[i + 1])
		swap(p_arr[i], p_arr[i + 1]);
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}