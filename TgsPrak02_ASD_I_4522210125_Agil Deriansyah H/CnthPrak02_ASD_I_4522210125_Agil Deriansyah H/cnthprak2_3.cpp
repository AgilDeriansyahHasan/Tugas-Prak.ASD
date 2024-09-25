#include <iostream>
using namespace std;

struct mahasiswa{
	public:
	char npm[9];
	char nama[30];
	float ipk;
};
int main(){
	mahasiswa mhs;
	cout << "Nomor Pokok Mahasiswa ="; cin>>mhs.npm;
	cout << "Nama Mahasiswa ="; cin>>mhs.nama;
	cout << "Induk Prestasi Komulatif ="; cin>>mhs.ipk;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<< "      Data Anda  "<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Nomor Pokok Mahasiswa = "<<mhs.npm<<endl;
	cout<<"Nama Mahasiswa = "<<mhs.nama<<endl;
	cout<<"Induk Prestasi Komulatif = "<<mhs.ipk<<endl;
	cin.get();
}