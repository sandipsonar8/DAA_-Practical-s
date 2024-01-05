#include<iostream.h>
#include<conio.h>
class BFSTree {
 private:
	int visited[20], a[20][20], q[20], n, i, j, f, r;
 public:
	BFSTree() {
		f=r=0;
	}
	void get();
	void bfs(int);
};

void BFSTree::get() {
	cout << "\nEnter number of vertices: ";
	cin >> n;

	cout << "\nEnter Adjacency matrix: ";
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			visited[i] = 0;
			cin >> a[i][j];
		}

	for (i = 1; i <= n; i++)
		if (visited[i] == 0)
			bfs(i);
}

void BFSTree::bfs(int v) {
	f=r=0;
	visited[v]=1;
	f++;
	r++;
	q[r]=v;

	while(f<=r){
		v=q[f];
		f++;
		cout<<v<<"\t";

		for(j=1;j<=n;j++){

			if (a[v][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				r++;
				q[r] = j;
			}
		}
	}
}

void main() {
	clrscr();
	BFSTree b;
	b.get();
	getch();
}
