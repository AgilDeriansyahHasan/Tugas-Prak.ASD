#include <iostream>
using namespace std;

void merge(int arr[], int kiri, int mid, int kanan) {
    int n1 = mid - kiri + 1;
    int n2 = kanan - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[kiri + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = kiri;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int mid = kiri + (kanan - kiri) / 2;
        mergesort(arr, kiri, mid);
        mergesort(arr, mid + 1, kanan);
        merge(arr, kiri, mid, kanan);
    }
}

void cetakdata(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {65, 2, 44, 26, 19, 22, 5, 3, 12};
    int arrsize = sizeof(arr) / sizeof(arr[0]);

    cout << "Data Sebelum diurutkan:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cetakdata(arr, arrsize);

    mergesort(arr, 0, arrsize - 1);
    cout << endl << endl;
    cout << "Data Setelah diurutkan:" << endl;
    cetakdata(arr, arrsize);

    return 0;
}
