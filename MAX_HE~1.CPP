#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

class Heap {
private:
    int a[1000], n;

public:
    void getdata();
    void insert();
    void disp();
};

void Heap::getdata() {
    cout << "\n...Program for Max Heap Insert...\n\n";
    cout << "Enter the Size := ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        a[i] = random(20000);
    }
}

void Heap::insert() {
    for (int j = 1; j <= n; j++) {
        int i = j;
        int item = a[i];

		while ((i > 1) && (a[i / 2] < item)) {
            a[i] = a[i / 2];
            i = i / 2;
        }

        a[i] = item;
    }
}

void Heap::disp() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\t";
    }
}

void main() {
    clrscr();
    clock_t e, s;
    Heap h;

    h.getdata();

    cout << "\n\n Before Insert :: ";
    h.disp();

    clock_t start = clock();
    h.insert();
    clock_t end = clock();

    cout << "\n\n After Insert ::\n";
    h.disp();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Execution time for Max Heap is :"<< timeTaken << " seconds" << endl;
    
    getch();
}
