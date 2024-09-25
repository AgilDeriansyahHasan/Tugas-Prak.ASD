#include <iostream>
#include <string.h>
using namespace std;

struct Data {
    int nilai;
};

Data data[10] = {9, 3, 7, 1, 5, 8, 2, 6, 4, 0};
int n = 10;

void tukar(int a, int b) {
    Data temp = data[b];
    data[b] = data[a];
    data[a] = temp;
}

void tampil() {
    for (int i = 0; i < n; i++) {
        cout << data[i].nilai << " ";
    }
    cout << endl;
}

void bubble_sort() {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (data[j].nilai > data[j - 1].nilai)
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
    cout << "Data sebelum diurutkan: ";
    tampil();
    cout << "Proses Bubble Sort....." << endl;
    cout << "-------------------------------" << endl;
    bubble_sort();
    cout << "-------------------------------" << endl;
    cout << "Terima Kasih" << endl;
    cout << "-------------------------------" << endl;
    cin.get();
    return 0;
}
