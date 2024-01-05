#include<iostream.h>
#include<conio.h>

class SingleSourceShortestPath {
    int n, v, cost[10][10], i, j, s[10];
    float dist[10];

public:
    void get();
    void sisource();
    void display();
};

void SingleSourceShortestPath::get() {
    cout << "\nEnter the number of vertices: \n";
    cin >> n;
    
    cout << "\nEnter the adjacency matrix: \n";
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == -1)
                cost[i][j] = 9999;
        }
    }
}

void SingleSourceShortestPath::sisource() {
    v = 1;

    for (i = 1; i <= n; i++) {
        s[i] = 0;
        dist[i] = cost[v][i];
    }

    s[v] = 1;
    dist[v] = 0.0;
    int minu, u;

    for (int num = 2; num <= n; num++) {
        for (i = 1; i <= n; i++)
            if (s[i] == 0)
                minu = dist[i];

        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && dist[i] < minu) {
                minu = dist[i];
                u = i;
            }
        }

        s[u] = 1;

        for (i = 1; i <= n; i++) {
            if (cost[u][i] > 0 && cost[u][i] < 9999 && s[i] == 0) {
                if (dist[i] > (dist[u] + cost[u][i])) {
                    dist[i] = dist[u] + cost[u][i];
                }
            }
        }
    }
}

void SingleSourceShortestPath::display() {
    cout << endl;

    for (i = 1; i <= n; i++) {
        cout << "Distance from 1 to " << i << ": " << dist[i] << " ";
        cout << endl;
    }
}

void main() {
    clrscr();
    SingleSourceShortestPath g;
    g.get();
    g.sisource();
    g.display();
    getch();
}
