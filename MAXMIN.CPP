#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int max, min, n, i, j, a[100];

class MaxMin {
public:
	void get();
	void maxmin(int, int, int &, int &);
	void show();
};

void MaxMin::get() {
	cout << "\n Enter the Size of array: ";
	cin >> n;

	for (i = 1; i <= n; i++) {
		a[i] = random(1000);
	}
}

void MaxMin::maxmin(int i, int j, int &max, int &min) {
	int mid, max1, min1, max2, min2;

	if (i == j) {
		max = min = a[i];
	} else if (i == j - 1) {
		if (a[i] < a[j]) {
			max = a[j];
			min = a[i];
		} else {
			max = a[i];
			min = a[j];
		}
	} else {
		mid = (i + j) / 2;
		maxmin(i, mid, max1, min1);
		maxmin(mid + 1, j, max2, min2);
		max = max1 > max2 ? max1 : max2;
		min = min1 < min2 ? min1 : min2;
	}
}

void MaxMin::show() {
	cout << "\n The maximum element is: " << max;
	cout << "\n The Minimum element is: " << min;
}

void main() {
	clrscr();

	MaxMin obj;
	clock_t s, e;

	obj.get();

	s = clock();
	obj.maxmin(1, n, max, min);
	e = clock();

	obj.show();
	cout << "\n The Time Complexity is: " << (e - s) / CLK_TCK;

	getch();
}
