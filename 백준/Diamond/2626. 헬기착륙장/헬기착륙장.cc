#include<iostream>
#include<iomanip>
#include<cmath>
#include<math.h>
using namespace std;
struct Point {
	double x, y;
};
int n;
Point center = { 0,0 };
Point points[1004];
double dis(double x1, double y1, double x2, double y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
Point farPoint() {
	Point ans = points[0];
	for (int k = 0; k < n; k++) {
		if (dis(center.x, center.y, points[k].x, points[k].y) > dis(center.x, center.y, ans.x, ans.y)) { // 가장 먼 거리에 있는 점 선택
			ans = points[k];
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(3);
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> points[k].x >> points[k].y;
	}
	double rate = 0.1; // 반지름 비율
	for (int k = 0; k < 50000; k++) {
		Point p = farPoint();
		center.x += (p.x - center.x) * rate;
		center.y += (p.y - center.y) * rate;
		// 중심을 가장 먼 점쪽으로 이동
		rate *= 0.999;
	}
	Point p = farPoint();
	cout << center.x << " " << center.y << " \n" << sqrt(dis(center.x, center.y, p.x, p.y));
}