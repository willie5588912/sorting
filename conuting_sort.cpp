// Consolearrpplication1.cpp : 定義主控台應用程式的進入點。
//

/*---counting sort---
資料結構：array；non-inplace sorter*/

#include "stdafx.h"
#include <iostream>

void count(int *p_arr, int *p_cont, int n, int offset);
void cumulate(int *p_cuml, int *p_cont, int msize);
void assign(int *p_cuml, int *p_r_arr, int *p_arr, int n, int offset);
int find_nzero(int *p_cont, int msize);

int main()
{
	int arr[10] = { 50000, -20000, 1343, -12033, -159, -1392, 2, -50000, 7790, 10 };
	int r_arr[10];				/*arr、r_arr的元素數要相同。arr是原始資料；r_arr是排序後的結果*/
	int cont[100001] = { 0 };	/*表示正負50000之內的數字（5000*2+1），再大會出現錯誤，需要探討*/
	int cuml[100001] = { 0 };	/*cont、cuml元素數要相同*/
	int n = sizeof(arr) / sizeof(int);
	int msize = sizeof(cont) / sizeof(int);
	int offset = (msize - 1) / 2, i_cum;		/*offset是為了修正負數造成index的問題（index最小值為0）*/
	int i_sel, i_res;

	/*計算原始資料中每一種數字有幾個，並建立cont（counting table）*/
	count(arr, cont, n, offset);

	/*由cont轉換，建立cuml（cumulating table），此table內容就直接是原始資料排序時參照的index*/
	cumulate(cuml, cont, msize);

	/*將原始資料依據cuml所給的index排列，即可獲得排序完結果*/
	assign(cuml, r_arr, arr, n, offset);

	std::cout << "The sorted array is as following:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << r_arr[i] << " ";
	std::cout << std::endl;

}


void count(int *p_arr, int *p_cont, int n, int offset)
{
	int idx;
	for (int i = 0; i <= n - 1; i++)
	{
		idx = p_arr[i] + offset;
		p_cont[idx]++;
	}

}


void cumulate(int *p_cuml, int *p_cont, int msize)
{
	/*Initial Setting*/
	int i_cum;
	i_cum = find_nzero(p_cont, msize);	/*找尋非0數值（從第一個非0開始計算）*/
	if (i_cum == 0)
	{
		p_cuml[i_cum] = 0;
	}
	else
	{
		p_cuml[i_cum] = p_cont[i_cum - 1];
	}
	i_cum++;

	/*Interative*/
	while (i_cum <= msize - 1)
	{
		p_cuml[i_cum] = p_cuml[i_cum - 1] + p_cont[i_cum - 1];
		i_cum++;
	}
}


void assign(int *p_cuml, int *p_r_arr, int *p_arr, int n, int offset)
{
	int i_sel, i_res;
	for (int i_ini = 0; i_ini <= n - 1; i_ini++)
	{
		i_sel = offset + p_arr[i_ini];
		i_res = p_cuml[i_sel];
		p_r_arr[i_res] = p_arr[i_ini];
		p_cuml[i_sel]++;
	}
}


int find_nzero(int *p_cont, int msize)
{
	int i = 0;
	while (i < msize)
	{
		if (p_cont[i] != 0)
			break;
		i++;
	}
	return i;
}