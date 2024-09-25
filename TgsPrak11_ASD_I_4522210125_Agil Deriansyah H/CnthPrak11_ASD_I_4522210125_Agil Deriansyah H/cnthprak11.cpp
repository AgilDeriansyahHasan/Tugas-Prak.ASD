#include <iostream>
using namespace std;

void heap(int canarray[], int n, int i) {
    int temp;
    int canbesar = i;
    int kiri = 2 * i + 1;
    int kanan = 2 * i + 2;

    if (kiri < n && canarray[kiri] > canarray[canbesar])
        canbesar = kiri;
    if (kanan < n && canarray[kanan] > canarray[canbesar])
        canbesar = kanan;

    if (canbesar != i) {
        temp = canarray[i];
        canarray[i] = canarray[canbesar];
        canarray[canbesar] = temp;
        heap(canarray, n, canbesar);
    }
}

void sortheap(int canarray[], int n) {
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(canarray, n, i);
    for (int i = n - 1; i >= 0; i--) {
        temp = canarray[0];
        canarray[0] = canarray[i];
        canarray[i] = temp;
        heap(canarray, i, 0);
    }
}

int main() {
    int canarray[] = {22, 7, 66, 28, 11, 63, 24, 12, 77, 99};
    int n = 10;
    int i;

    cout << "Menampilkan Data Sebelum Diurutkan" << endl;
    cout << "----------------------------------" << endl;
    for (i = 0; i < n; i++)
        cout << canarray[i] << " ";
    cout << endl;

    sortheap(canarray, n);

    cout << endl;
    cout << "Menampilkan Data Setelah Diurutkan - HEAP SORT" << endl;
    cout << "----------------------------------------------" << endl;
    for (i = 0; i < n; i++)
        cout << canarray[i] << " ";
    cout << endl;

    return 0;
}
