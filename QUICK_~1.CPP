#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do {
		while (arr[i] <= pivot && i <= j) {
			i++;
		}
		while (arr[j] >= pivot && i <= j) {
			j--;
		}
		if (i < j) {
			swap(arr[i], arr[j]);
		}

	} while (i <= j);

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    clrscr();

    int nValues[] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        int n = nValues[i];
        int* arr = new int[n];

        // Fill the array with random values
        for (int j = 0; j < n; j++) {
            arr[j] = random(100);  // Adjust the range of random values as needed
        }

        // Measure execution time
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        // Calculate and print execution time
        double timeTaken = double(end - start) / CLK_TCK;
        cout << "Execution time for n = " << n << ": " << timeTaken << " seconds" << endl;

        // Optionally, print the sorted array
         for (int k = 0; k < n; k++) {
             cout << arr[k] << "\t";
         }

        delete[] arr;
        cout << "\n";
    }

    getch();
    return 0;
}
