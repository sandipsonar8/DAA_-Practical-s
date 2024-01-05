#include<iostream.h>
#include<conio.h>
#include<time.h>

class Knapsack {
    float p[20], w[20], x[20], i, j, sum;
    
public:
    void get();
    void order();
    void knap(int, int);
    void show();
};

void Knapsack::get() {
    cout << "\nEnter the element size & sack size: \n";
    cin >> n >> m;

    cout << "\nEnter the profit: \n";
    for (i = 1; i <= n; i++)
        cin >> p[i];

    cout << "\nEnter the weight: \n";
    for (i = 1; i <= n; i++)
        cin >> w[i];
}

void Knapsack::order() {
    for (i = 1; i <= n; i++)
        for (j = 1; j < n; j++) {
            if ((p[j] / w[j]) <= (p[j + 1] / w[j + 1])) {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
}

void Knapsack::knap(int m, int n) {
    int u;
    sum = 0.0;

    for (i = 1; i <= n; i++)
        x[i] = 0.0;

    u = m;

    for (i = 1; i <= n; i++) {
        if (w[i] > u)
            break;

        x[i] = 1.0;
        u = u - w[i];
    }

    if (i <= n)
        x[i] = u / w[i];

    for (i = 1; i <= n; i++)
        sum = sum + (p[i] * x[i]);
}

void Knapsack::show() {
    for (i = 1; i <= n; i++)
        cout << x[i] << " ";
    
    cout << "\n---------------------\n";
    cout << "Profit: " << sum << "\n";
    cout << "\n---------------------\n";
}

void main() {
    clrscr();
    cout << "\n\t*** Program for Knapsack Solution ***\n\t";
    Knapsack k;
    k.get();
    k.order();
    k.knap(m, n);
    k.show();
    getch();
}
