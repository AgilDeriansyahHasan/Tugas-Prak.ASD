#include <iostream>
using namespace std;

class BubbleSort {
private:
    int data[10];
    int n;

    void tukar(int a, int b) {
        int temp = data[b];
        data[b] = data[a];
        data[a] = temp;
    }

public:
    BubbleSort() {
        n = 0;
    }

    void inputData() {
        cout << "Masukkan jumlah data=";
        cin >> n;
        cout << "---------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Masukkan data ke-" << (i + 1) << "=";
            cin >> data[i];
        }
        cout << endl;
    }

    void tampilData() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void bubbleSortAscending() {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (data[j] > data[j + 1])
                    tukar(j, j + 1);
            }
            tampilData();
        }
        cout << endl;
    }
};

int main() {
    cout << "*------------------------------*" << endl;
    cout << "*Selamat datang di aplikasi *"<< endl;
    cout << "*Bubble Sort (Ascending)*"<< endl;
    cout << "*------------------------------*" << endl;

    BubbleSort bubbleSortObj;
    bubbleSortObj.inputData();

    cout << "Proses Bubble Sort (Ascending)....." << endl;
    cout << "-------------------------------" << endl;
    bubbleSortObj.tampilData();
    bubbleSortObj.bubbleSortAscending();
    cout << "-------------------------------" << endl;
    cout << "Terima Kasih" << endl;
    cout << "-------------------------------" << endl;

    return 0;
}
