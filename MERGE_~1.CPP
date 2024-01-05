#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

class MergeSort {
public:
	void merge(int arr[], int l, int m, int h);
	void mergeSort(int arr[], int l, int h);
	void get(int n);
};

void MergeSort::merge(int arr[], int l, int m, int h) {
    int temp[50];
    int i = k = l;
    int j = m + 1;
    

    while ((i <= m) && (j <= h)) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= h) {
        temp[k++] = arr[j++];
    }

    for (i = l; i <= h; i++) {
        arr[i] = temp[i];
    }
}


void MergeSort::mergeSort(int arr[], int l, int h) {
	if (l < h) {
		int m = l + (h-l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, h);
		merge(arr, l, m, h);
	}
}

void MergeSort::get(int n) {
	int* arr = new int[n];
	for (int j = 0; j < n; j++) {
		arr[j] = random(100);
	}

	// Measure execution time
	clock_t start = clock();
	mergeSort(arr, 0, n - 1);
	clock_t end = clock();

	// Calculate and print execution time
	double timeTaken = double(end - start) / CLK_TCK;
	cout << "Execution time for n = " << n << ": " << timeTaken << " seconds" << endl;

	// Optionally, print the sorted array
	for (j = 0; j < n; j++) {
		cout << arr[j] << "\t";
	}

	delete[] arr;
	cout << "\n";
}

int main() {
	clrscr();
	int nValues[] = {10, 20, 30};
	MergeSort obj;

	for (int i = 0; i < 3; i++) {
		int n = nValues[i];
		obj.get(n);
	}

	getch();
	return 0;
}
