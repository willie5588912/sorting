// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//


#include "stdafx.h"
#include <iostream>

void swap(int &a, int &b);
void sort(int *p_arr, int n);
void checklength(int &a_size, int &b_size, int stage, int idx, int n);
void compare(int *p_a, int *p_b, int a_size, int b_size, int *p_new_arr, int &new_idx);
void choose(int *p_comp, int *p_input_arr, int stage, int &idx, int n);

int main()
{
	int arr[10] = { 2, 10, 12, 18, 25, 6, 16, 20, 32, 34 };
	int new_arr[10], input_arr[10];
	int n = sizeof(arr) / sizeof(int);
	int idx = 0, stage = 1;
	int a_size, b_size;
	int round = 1;
	int new_idx = -1;

	/*sorting*/
	sort(arr, n);

	for (int i = 0; i < n; i++)
	{
		new_arr[i] = arr[i];
	}

	/*merging*/
	while (pow(2, stage) < n)
	{
		for (int i = 0; i < n; i++)
		{
			input_arr[i] = new_arr[i];
		}
		while (idx < n)
		{
			checklength(a_size, b_size, stage, idx, n);

			int *a;
			int *b;
			a = new int[a_size];
			b = new int[b_size];

			choose(a, input_arr, stage, idx, n);
			choose(b, input_arr, stage, idx, n);

			compare(a, b, a_size, b_size, new_arr, new_idx);

			delete[] a;
			delete[] b;
		}
		idx = 0;
		stage++;
		new_idx = -1;
	}


	/*result*/
	std::cout << "The sorted array is as following: " << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << new_arr[i] << " ";
	std::cout << std::endl;

}

void sort(int *p_arr, int n)
{
	int i = 0;
	while (i < n)
	{
		if (i + 1 < n)
		{
			if (p_arr[i] > p_arr[i + 1])
				swap(p_arr[i], p_arr[i + 1]);
		}
		i += 2;
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void checklength(int &a_size, int &b_size, int stage, int idx, int n)
{
	int remainder = n - idx;
	int set_size = pow(2, stage);
	if (remainder >= 2 * set_size)
	{
		a_size = set_size;
		b_size = set_size;
	}
	else if (2 * set_size > remainder && remainder >= set_size)
	{
		a_size = set_size;
		b_size = remainder - a_size;
	}
	else if (set_size > remainder)
	{
		a_size = remainder;
		b_size = 0;
	}
}


void choose(int *p_comp, int *p_input_arr, int stage, int &idx, int n)
{
	int round = 1;
	while (round <= pow(2, stage) && idx <= n - 1)
	{
		p_comp[round - 1] = p_input_arr[idx];
		idx++;
		round++;
	}
	round = 1;
}

void compare(int *p_a, int *p_b, int a_size, int b_size, int *p_new_arr, int &new_idx)
{
	int i = 0, j = 0, k = 0;
	if (b_size != 0)
	{
		while (k < a_size + b_size)
		{
			if (i < a_size && j < b_size)
			{
				if (p_a[i] <= p_b[j])
				{
					new_idx++;
					p_new_arr[new_idx] = p_a[i];
					i++;
				}
				else if (p_a[i]>p_b[j])
				{
					new_idx++;
					p_new_arr[new_idx] = p_b[j];
					j++;
				}
			}
			else if (i != a_size || j != b_size)
			{
				if (i == a_size)
				{
					new_idx++;
					p_new_arr[new_idx] = p_b[j];
					j++;
				}
				else if (j == b_size)
				{
					new_idx++;
					p_new_arr[new_idx] = p_a[i];
					i++;
				}
			}
			k++;
		}
	}
	else if (b_size == 0)
	{
		for (int ii = 0; ii < a_size; ii++)
		{
			new_idx++;
			p_new_arr[new_idx] = p_a[ii];
		}
	}
}

