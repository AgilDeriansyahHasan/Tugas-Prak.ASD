#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int maxi = 7;

struct pelanggan_toko {
    string nama[maxi], alamat[maxi], kelamin[maxi], telp[maxi];
    int umur[maxi];
};

int main() {
    pelanggan_toko data;
    int jumlah = maxi;
	
    // Mengisi data
    data.nama[0] = "Agil";
    data.alamat[0] = "Jl. Bintara";
    data.umur[0] = 20;
    data.kelamin[0] = "Laki-laki";
    data.telp[0] = "0878";

    data.nama[1] = "Deri";
    data.alamat[1] = "Jl. Layang";
    data.umur[1] = 21;
    data.kelamin[1] = "Laki-laki";
    data.telp[1] = "0812";

    data.nama[2] = "Arneyva";
    data.alamat[2] = "Jl. Samudra";
    data.umur[2] = 18;
    data.kelamin[2] = "Perempuan";
    data.telp[2] = "0878";
	
	data.nama[3] = "Alveria";
    data.alamat[3] = "Jl. Flowres";
    data.umur[3] = 19;
    data.kelamin[3] = "Perempuan";
    data.telp[3] = "0812";
	
	data.nama[4] = "Hye";
    data.alamat[4] = "Jl. Matahari";
    data.umur[4] = 26;
    data.kelamin[4] = "Perempuan";
    data.telp[4] = "0878";
	
	data.nama[5] = "Tenz";
    data.alamat[5] = "Jl. Sentinel";
    data.umur[5] = 28;
    data.kelamin[5] = "Laki-laki";
    data.telp[5] = "0812";
	
	data.nama[6] = "Jane";
    data.alamat[6] = "Jl. Forest";
    data.umur[6] = 30;
    data.kelamin[6] = "Perempuan";
    data.telp[6] = "0878";

	cout<<endl;
    cout << "Data Pelanggan Toko :\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "| Nama      | Alamat          | Umur | Kelamin   | No Telp      |"<<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    for (i = 0; i < jumlah; i++) {
        cout << "| " << setw(10) << data.nama[i] << " | "
             << setw(15) << data.alamat[i] << " | "
             << setw(4) << data.umur[i] << " | "
             << setw(9) << data.kelamin[i] << " | "
             << setw(12) << data.telp[i] << " |\n";
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return 0;
}
