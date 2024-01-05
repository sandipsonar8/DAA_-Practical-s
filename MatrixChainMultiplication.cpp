#include<iostream.h>
#include<conio.h>

#define INF 30000

int p[100], m[100][100], s[100][100], k, n, j, q, i, l;

class MatrixChainMultiplication {
public:
    void get() {
        cout << "\nEnter total matrix count:\n";
        cin >> n;
        cout << "\nEnter Matrix Orders:\n";
        for (int i = 0; i <= n; i++) {
            cout << "\nP[" << i << "]=";
            cin >> p[i];
        }
        matrixChainOrder(p, n);
    }

    void matrixChainOrder(int p[], int n) {
        for (i = 1; i <= n; i++)
            m[i][i] = 0;

        for (l = 2; l <= n; l++) {
            for (i = 1; i <= n - l + 1; i++) {
                j = i + l - 1;
                m[i][j] = INF;
                for (k = i; k <= j - 1; k++) {
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }

        cout << "\nTotal Optimal Scalar Multiplications needed are: " << m[1][n];
        cout << "\nArray M[i][j] is:\n";
        for (i = 1; i <= n; i++) {
            cout << "\n";
            for (j = 1; j <= n; j++)
                cout << m[i][j] << "\t";
        }

        cout << "\nArray S[i][j] is:\n";
        for (i = 1; i <= n; i++) {
            cout << "\n";
            for (j = 1; j <= n; j++)
                cout << s[i][j] << "\t";
        }
    }

    void printOptimal(int i, int j) {
        if (i == j)
            cout << " A" << i;
        else {
            cout << " ( ";
            printOptimal(i, s[i][j]);
            printOptimal(s[i][j] + 1, j);
            cout << " ) ";
        }
    }
};

void main() {
    clrscr();
    MatrixChainMultiplication mcm;
    mcm.get();
    mcm.printOptimal(1, n);
    getch();
}
