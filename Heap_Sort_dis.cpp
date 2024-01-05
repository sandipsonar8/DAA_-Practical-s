#include<iostream.h>
#include<time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int nValues[] = {1000, 2000, 3000};

    for (int i = 0; i < 3; i++) {
        int n = nValues[i];
        int arr[3000];  // Adjust the size as per the maximum value in nValues

        // Fill the array with random values (optional)
        // ...

        clock_t start = clock();
        heapSort(arr, n);
        clock_t end = clock();

        double timeTaken = double(end - start) / CLOCKS_PER_SEC;

        cout << "Execution time for n = " << n << ": " << timeTaken << " seconds" << endl;

        // Optionally, print the sorted array
        // ...
    }

    return 0;
}
