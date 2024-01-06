#include<iostream.h>
#include<conio.h>
#include<time.h>

class BinarySearch {
public:
    int binarySearch(int arr[], int low, int high, int key);
};

int BinarySearch::binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Element not found
}

int main() {
    clrscr();

    BinarySearch binarySearch;

    int nValues[] = {1000, 2000, 3000};

    for (int i = 0; i < 3; ++i) {
        int n = nValues[i];
        int* arr = new int[n];

        // Initialize array with sorted values
        for (int j = 0; j < n; ++j) {
            arr[j] = j + 1;
        }

        int key = n / 2; // Element to search for

        clock_t start = clock();
        int result = binarySearch.binarySearch(arr, 0, n - 1, key);
        clock_t stop = clock();
        
        double duration = (double)(stop - start) / CLOCKS_PER_SEC;

        if (result != -1)
            cout << "Element found at index " << result << " for n = " << n << endl;
        else
            cout << "Element not found for n = " << n << endl;

        cout << "Time taken for n = " << n << ": " << duration << " seconds" << endl;

        delete[] arr;
    }

    getch();
    return 0;
}
