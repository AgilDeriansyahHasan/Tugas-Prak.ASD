#include <iostream>
#include <string.h>
using namespace std;

int data[10], data2[10];
int n;

void tukar(int a, int b) {
    int t;
    t = data[b];
    data[b] = data[a];
    data[a] = t;
}

void input() {
    cout << "Masukkan jumlah data=";
    cin >> n;
    cout << "---------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << (i + 1) << "=";
        cin >> data[i];
        data2[i] = data[i];
    }
    cout << endl;
}

void tampil() {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void bubble_sort() {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (data[j] < data[j - 1])
                tukar(j, j - 1);
        }
        tampil();
    }
    cout << endl;
}

int main() {
    cout << "*------------------------------*" << endl;
    cout << "*Selamat datang di aplikasi *"<< endl;
    cout << "*Bubble Sort*"<< endl;
    cout << "*------------------------------*" << endl;
    input();
    cout << "Proses Bubble Sort....." << endl;
    cout << "-------------------------------" << endl;
    tampil();
    bubble_sort();
    cout << "-------------------------------" << endl;
    cout << "Terima Kasih" << endl;
    cout << "-------------------------------" << endl;
    cin.get();
    return 0;
}
