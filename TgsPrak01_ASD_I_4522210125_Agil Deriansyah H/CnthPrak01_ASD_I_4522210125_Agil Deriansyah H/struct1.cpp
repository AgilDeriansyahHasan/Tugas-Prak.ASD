#include <iostream>
#include <string>
using namespace std;

int main(){
	struct matakuliah{
		string nama;
		int sks;
		char nHuruf;
	float nAngka;};
	matakuliah data_mk;
	data_mk.nama="Algoritma dan Pemograman 2";
	data_mk.sks=3;
	data_mk.nHuruf='A';
	data_mk.nAngka=4.00;
	cout<<endl;
	cout<<endl;
	cout<<"Mata Kuliah ="<<data_mk.nama<<endl;
	cout<<"Jumlah sks  ="<<data_mk.sks<<endl;
	cout<<"Nilai       ="<<data_mk.nHuruf<<endl;
	cout<<"Indeks      ="<<data_mk.nAngka<<endl;
cin.get();}
