#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int max, min, n;

class Sai {
    int a[100];

public:
    int j, i;

    void get();
    void put();
    void maxmin(int, int, int &, int &);
    void show();
};

void Sai::get() {
    cout << "\n Enter the Size of array: ";
    cin >> n;

    for (i = 1; i <= n; i++) {
        a[i] = random(1000);
    }
}

void Sai::put() {
    cout << "\n Show the Elements of array:\n";
    for (i = 1; i <= n; i++) {
        if (i % 8 == 0)
            cout << "\n";
        cout << a[i] << "\t";
    }
}

void Sai::maxmin(int i, int j, int &max, int &min) {
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

void Sai::show() {
    cout << "\n The maximum element is: " << max;
    cout << "\n The Minimum element is: " << min;
}

void main() {
    clrscr();
    cout << "\n\t*** Program to find maximum and minimum from a given array using maxmin ***\n\t";
    Sai s;
    clock_t e, l;

    s.get();
    s.put();

    e = clock();
    s.maxmin(1, n, max, min);
    l = clock();

    s.show();
    cout << "\n The Time Complexity is: " << (l - e) / CLK_TCK;

    getch();
}
