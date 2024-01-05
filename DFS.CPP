#include<iostream.h>
#include<conio.h>

class DFSTree {
	int a[20][20], visited[20], n, i, j;

public:

	void dfs(int);
	void get();
};

void DFSTree::get() {
	cout << "\nEnter the number of nodes: ";
	cin >> n;

	cout << "\nEnter the adjacency matrix: ";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			visited[i]=0;
			cin >> a[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}
}

void DFSTree::dfs(int v) {
	visited[v] = 1;
	cout << "\t" << v;

	for (j = 1; j <= n; j++) {
		if (a[v][j] == 1 && visited[j] == 0) {
			dfs(j);
		}
	}
}

void main() {
	clrscr();
    DFSTree d;
    d.get();
    getch();
}
