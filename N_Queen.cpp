#include<iostream.h>
#include<conio.h>
#include<math.h>

class NQueens {
    int x[100], n;
    int z;

public:
    void get();
    void show();
    void queen(int, int);
    int place(int, int);
};

void NQueens::get() {
    cout << "Enter the number of queens: \n";
    cin >> n;

    for (int i = 1; i <= n; i++)
        x[i] = 0;

    z = 0;
    queen(1, n);
}

void NQueens::queen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;

            if (k == n) {
                cout << endl;
                z++;
                cout << z << ":->";

                for (i = 1; i <= n; i++)
                    cout << x[i] << "\t";
            } else {
                queen(k + 1, n);
            }
        }
    }
}

int NQueens::place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if ((x[j] == i) || abs(x[j] - i) == (abs(j - k)))
            return 0;
    }
    return 1;
}

void main() {
    clrscr();
    NQueens n;
    n.get();
    getch();
}
