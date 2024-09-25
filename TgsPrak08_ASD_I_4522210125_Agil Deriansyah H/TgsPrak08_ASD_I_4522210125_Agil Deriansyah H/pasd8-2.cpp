#include <iostream>
using namespace std;

class SequentialSearch {
private:
    int* data;
    int size;

public:
    SequentialSearch(int arr[], int len) {
        size = len;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
    }

    SequentialSearch() {
        delete[] data;
    }

    int search(int element) {
        for (int i = 0; i < size; i++) {
            if (data[i] == element) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    const int array_size = 11;
    int arr[array_size] = {22, 61, 15, 66, 18, 25, 24, 87, 55, 45, 10};

    SequentialSearch searchObj(arr, array_size);

    cout << "--------------------------------------" << endl;
    cout << "'' Sequential Search ''" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Isi data nya adalah " << endl;
    cout << "--------------------" << endl;
    cout << endl;
    for (int i = 0; i < array_size; i++) {
        cout << " Data[" << i + 1 << "]" << "-->" << arr[i] << endl;
    }

    int searchElement;
    cout << "----------------------------------" << endl;
    cout << endl;
    cout << "Masukkan data yang akan anda cari ? ";
    cin >> searchElement;

    int position = searchObj.search(searchElement);
    if (position != -1)
        cout << "Data yang dicari ditemukan pada posisi : Data[" << position + 1 << "]" << endl;
    else
        cout << "Data yang anda cari tidak ditemukan" << endl;

    return 0;
}
