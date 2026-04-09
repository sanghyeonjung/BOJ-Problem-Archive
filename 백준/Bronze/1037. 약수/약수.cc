#include<iostream>
#include<algorithm>
using namespace std;
long long int arr[55];
int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> arr[k];
	}
	sort(arr, arr + n);
	if (n == 1) {
		cout << arr[0] * arr[0];
		return 0;
	}
	cout << arr[0] * arr[n - 1];
	
}