#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct mata_kuliah {
    string Matkul[20], nHuruf[20], nAngka[20];
    int no[20], sks[20];
};
mata_kuliah data;

int main() {
    char nama[20],npm[20];
    int jumlah, i;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "               Kartu Hasil Studi[KHS] " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << " Nama Mahasiswa            : ";cin >> nama;
    cout << " Nomor Induk Mahasiswa     : ";cin >> npm;
    cout << endl;
    cout << " Mata Kuliah Yang Ditempuh : ";
    cin >> jumlah;
    for (i = 1; i <= jumlah; i++) {
        cout << endl;
        cout << "No            :";cin >> data.no[i];
        cout << "Mata Kuliah   :";cin >> data.Matkul[i];
        cout << "SKS           :";cin >> data.sks[i];
        cout << "Nilai Huruf   :";cin >> data.nHuruf[i];
        cout << "Nilai Angka   :";cin >> data.nAngka[i];
        cout << endl;
    }
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "| No |   Mata Kuliah   | SKS | Nilai Huruf | Nilai Angka |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (i = 1; i <= jumlah; i++) {
        cout << "|" << setw(3) << data.no[i] << " |" << setw(17) << data.Matkul[i] << " |" << setw(4) << data.sks[i] << " |";
        cout << setw(11) << data.nHuruf[i] << " |" << setw(12) << data.nAngka[i] << " |" << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cin.get();
}
