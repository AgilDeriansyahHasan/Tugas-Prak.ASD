#include <iostream>
#include <iomanip>
using namespace std;

void Q_Sort(int[], int, int);

int main() {
    int numlist[9] = {65, 2, 44, 26, 19, 22, 5, 3, 12};
    cout << "Baca Sebelum Diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int d = 0; d < 9; d++) {
        cout << setw(3) << numlist[d];
    }
    cout << endl << endl;
    Q_Sort(numlist, 0, 9);
    cout << "Data Setelah Diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int iii = 0; iii < 9; iii++) {
        cout << setw(3) << numlist[iii];
    }
    cin.get();
    return 0;
}

void Q_Sort(int angka[], int kiri, int kanan) {
    int pivot, kiri_hold, kanan_hold;
    kiri_hold = kiri;
    kanan_hold = kanan;
    pivot = angka[kiri];
    while (kiri < kanan) {
        while (angka[kanan] >= pivot && kiri < kanan)
            kanan--;
        if (kiri != kanan) {
            angka[kiri] = angka[kanan];
            kiri++;
        }
        while (angka[kiri] <= pivot && kiri < kanan)
            kiri++;
        if (kiri != kanan) {
            angka[kanan] = angka[kiri];
            kanan--;
        }
    }
    angka[kiri] = pivot;
    pivot = kiri;
    kiri = kiri_hold;
    kanan = kanan_hold;
    if (kiri < pivot)
        Q_Sort(angka, kiri, pivot - 1);
    if (kanan > pivot)
        Q_Sort(angka, pivot + 1, kanan);
}
