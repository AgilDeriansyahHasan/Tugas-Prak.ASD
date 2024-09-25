#include <iostream>
using namespace std;

int search01_a(int tika_a[], int jmlelemenarry_a, int elemen_a);

int main() {
    const int jmlelemenarry_a = 11;
    int tika_a[jmlelemenarry_a] = {22, 61, 15, 66, 18, 25, 24, 87, 55, 45, 10};

    cout << "--------------------------------------" << endl;
    cout << "'' Sequential Search ''" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Isi data nya adalah " << endl;
    cout << "--------------------" << endl;
    cout << endl;
    for (int count_a = 0; count_a < jmlelemenarry_a; count_a++) {
        cout << " " << " Data[" << count_a + 1 << "]" << "-->" << tika_a[count_a] << endl;
    }

    int searchelemen_a = 0;
    int flaq_a = 0;
    cout << "----------------------------------" << endl;
    cout << endl;
    cout << "Masukkan data yang akan anda cari ? ";
    cin >> searchelemen_a;
    flaq_a = search01_a(tika_a, jmlelemenarry_a, searchelemen_a);
    if (flaq_a != -1)
        cout << "Data yang dicari ditemukan pada posisi : Data[" << flaq_a << "]" << endl;
    else
        cout << "Data yang anda cari tidak ditemukan" << endl;
    cin.get();
    return 0;
}

int search01_a(int tika_a[], int jmlelemenarry_a, int elemen_a) {
    int flaq_a = -1;
    for (int count_a = 0; count_a < jmlelemenarry_a; count_a++) {
        if (elemen_a == tika_a[count_a]) {
            flaq_a = count_a + 1;
            break;
        }
    }
    return flaq_a;
}
