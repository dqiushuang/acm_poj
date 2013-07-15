// 5-LIS.cpp : 定义控制台应用程序的入口点。
//This is an O(n*log n) program. But it is not accepted.

#include "stdafx.h"
#include <iostream>
using namespace std;

int a[1005];
int dp[1005];

int _tmain(int argc, _TCHAR* argv[])
{
	again:
	int n, left, right, mid;
	cin >>n;
	for(int i = 1; i <= n; ++i) {
		cin >>a[i];
		dp[i] = 0;
	}
	int len = 1;
	dp[1] = a[1];
	for(int i = 2; i <= n; ++i) {
		left = 1;
		right = len;
		while(left <= right) {
			mid = (left + right) / 2;
			if(dp[mid] < a[i])
				left = mid + 1;
			else 
				right = mid - 1;
		}
		dp[left] = a[i];
		if(len < left)
			len++;
	}
	
	cout <<len;
	goto again;
	system("pause");
	return 0;
}

