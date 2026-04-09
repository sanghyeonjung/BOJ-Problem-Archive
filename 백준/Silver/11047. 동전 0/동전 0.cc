#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int arr[11];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int now = 0;
	int cnt = 0;
	int temp = k;
		for (int i = n - 1; i >= 0; i--)
		{
			if (now == k)break;
			if (arr[i] <= temp)
			{
				int num = 0;
				num = temp / arr[i];
				now += arr[i] * num;
				cnt += num;
				temp -= arr[i] * num;
			}
		}
		cout << cnt;
}