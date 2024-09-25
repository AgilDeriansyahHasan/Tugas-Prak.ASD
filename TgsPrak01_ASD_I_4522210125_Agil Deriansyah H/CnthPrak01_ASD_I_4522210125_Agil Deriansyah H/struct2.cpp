#include <iostream>
#include <string>
using namespace std;

struct koordinat{
	int X;
	int Y;};
	void tampil_posisi(koordinat posisi);
	
	int main(){
		koordinat posisi ;
		posisi.X=56;
		posisi.Y=53;
		cout<<endl;
		tampil_posisi(posisi);
	cin.get();}
	
	void tampil_posisi(koordinat posisi){
		cout<<"Posisi Ordinat X adalah = "<<posisi.X<<endl;
	cout<<"Posisi Ordinat Y adalah = "<<posisi.Y<<endl;}