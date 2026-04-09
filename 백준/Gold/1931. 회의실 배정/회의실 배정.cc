#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef struct kk {
	int start;
	int end;
}point;
bool operator < (point a, point b) {
	if (a.end == b.end)
	{
		return a.start <= b.start;
	}
	return a.end < b.end;
}
int main() {
	int k = 0;
	point arr[100001];
	cin >> k;
	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i].start >> arr[i].end;
	}

	sort(arr, arr + k);
	point now;
	now.start = arr[0].start;
	now.end = arr[0].end;
	cnt++;
	for (int i = 1; i < k; i++)
	{
		if (now.end <= arr[i].start)
		{
			cnt++;
			now.start = arr[i].start;
			now.end = arr[i].end;
		}
	}
	cout << cnt;
	
}
