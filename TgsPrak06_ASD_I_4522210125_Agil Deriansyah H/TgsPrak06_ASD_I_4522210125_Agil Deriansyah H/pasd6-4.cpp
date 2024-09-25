#include <iostream>
#include <iomanip>
using namespace std;

struct Data {
    int value;
};

void Q_Sort(Data[], int, int);

int main() {
    Data dataList[9] = {65, 2, 44, 26, 19, 22, 5, 3, 12};

    cout << "Baca Sebelum Diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int d = 0; d < 9; d++) {
        cout << setw(3) << dataList[d].value;
    }
    cout << endl << endl;

    Q_Sort(dataList, 0, 8);

    cout << "Data Setelah Diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int iii = 0; iii < 9; iii++) {
        cout << setw(3) << dataList[iii].value;
    }

    cin.get();
    return 0;
}

void Q_Sort(Data data[], int left, int right) {
    int pivot, left_hold, right_hold;
    left_hold = left;
    right_hold = right;
    pivot = data[left].value;
    while (left < right) {
        while (data[right].value >= pivot && left < right)
            right--;
        if (left != right) {
            data[left].value = data[right].value;
            left++;
        }
        while (data[left].value <= pivot && left < right)
            left++;
        if (left != right) {
            data[right].value = data[left].value;
            right--;
        }
    }
    data[left].value = pivot;
    pivot = left;
    left = left_hold;
    right = right_hold;
    if (left < pivot)
        Q_Sort(data, left, pivot - 1);
    if (right > pivot)
        Q_Sort(data, pivot + 1, right);
}
