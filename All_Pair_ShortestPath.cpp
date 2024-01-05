#include<iostream.h>
#include<conio.h>

class AllPairsShortestPath {
private:
    int s[10][10], a[10][10], i, j, k, n;

public:
    void get();
    int min(int, int);
    void find();
    void display();
};

int AllPairsShortestPath::min(int m, int n) {
    return (m < n ? m : n);
}

void AllPairsShortestPath::get() {
    cout << "\nEnter the size of the matrix: ";
    cin >> n;

    cout << "\nEnter the matrix elements (-1 for infinity):\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                s[i][j] = 9999;
            } else {
                s[i][j] = a[i][j];
            }
        }
    }
}

void AllPairsShortestPath::find() {
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++) {
                if (i == j) {
                    s[i][j] = 0;
                } else {
                    s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
                }
                if (s[i][j] >= 9999) {
                    s[i][j] = 0;
                }
            }
}

void AllPairsShortestPath::display() {
    cout << "\nMatrix after performing the operation:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }
}

void main() {
    clrscr();
    AllPairsShortestPath apsp;
    apsp.get();
    apsp.find();
    apsp.display();
    getch();
}
