#include <iostream>
using namespace std;

struct mahasiswa {
    public:
    char npm[9];
    char nama[30];
    float ipk;
};

int main() {
    mahasiswa mhs;
    cout << "Nomor Pokok Mahasiswa = "; cin >> mhs.npm;
    cout << "Nama Mahasiswa = "; cin >> mhs.nama;
    cout << "Induk Prestasi Komulatif = "; cin >> mhs.ipk;
    cout << endl;
    
	string kelas_nilai;
    if (mhs.ipk >= 3.5) {
        kelas_nilai = "A (Sangat Baik)";
    } 
	else 
	if (mhs.ipk >= 3.0) {
        kelas_nilai = "B (Baik)";
    } 
	else 
	if (mhs.ipk >= 2.5) {
        kelas_nilai = "C (Cukup)";
    } 
	else 
	if (mhs.ipk >= 2.0) {
        kelas_nilai = "D (Kurang)";
    } 
	else {
        kelas_nilai = "E (Gagal)";
    }
	
	cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "      Data Anda  " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Nomor Pokok Mahasiswa = " << mhs.npm << endl;
    cout << "Nama Mahasiswa = " << mhs.nama << endl;
    cout << "Induk Prestasi Komulatif = " << mhs.ipk << " (" << kelas_nilai << ")" << endl;
	
    cin.get();
}