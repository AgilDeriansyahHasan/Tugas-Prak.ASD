#include <iostream>
#include <string> 
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} nilaiMk;

typedef struct elm *alamatelm;
typedef struct elm{
	nilaiMk kontainer;
	alamatelm next;
} elemen;

typedef struct{
	elemen* top;
} stack;

void buatstkosong(stack *S){
	(*S) .top = NULL;
}
int iskosong(stack S){
	bool hasil = false;
	
	if(S.top == NULL){
		hasil = true;
	}
	return hasil;
}

int jmlelemen(stack S){
	int hasil = 0;
	
	if(S.top != NULL){
		elemen *bantu;
		bantu = S.top;
		
		while (bantu != NULL){
			hasil = hasil +1;
			bantu = bantu -> next;
		}
	}
	return hasil;
}
	
	void push (string npm, string nama_mhs, double nilai, stack *S) {
		elemen *info;
		info = new elemen;
		info -> kontainer.npm = npm;
		info -> kontainer.nama_mhs = nama_mhs;
		info -> kontainer.nilai = nilai;
		
		if((*S).top == NULL) {
			cout<<"Stack Penuh"<<endl;
			info -> next = NULL;
		}
		else{
			info -> next = (*S).top;
		}
		(*S).top = info;
		info = NULL;
	}
	
	void pop(stack *S){
		if((*S).top != NULL){
			elemen *hapus = (*S).top;
			
			if(jmlelemen(*S)==1){
				(*S).top=NULL;
			}
			else {
				(*S).top =(*S).top -> next;
			}
			hapus -> next = NULL;
			delete hapus;
		}
		else{
			cout<<"Stack Kosong"<<endl;
		}
	}
	
	void cetakstack(stack S)
	{
		if(S.top != NULL)
		{
			cout<<"Menampilkan Stack"<<endl;
			elemen *bantu = S.top;
			int i=1;
			while(bantu != NULL)
			{
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"Elemen Ke :"<<i<<endl;
				cout<<"Nomor Pokok Mahasiswa :"<<bantu -> kontainer.npm<<endl;
				cout<<"Nama Mahasiswa :"<<bantu -> kontainer.nama_mhs<<endl;
				cout<<"Nilai Mahasiswa :"<<bantu -> kontainer.nilai<<endl;
				bantu=bantu -> next;
				i=i+1;
			}
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}
		else
		{
			cout<<"Stack Kosong"<<endl;
		}
	}
	
	int main(){
		stack S;
		
		buatstkosong(&S);
		cetakstack(S);
		cout<<endl;
		cout<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~"<<endl;
		push("4523210666","Budi",88.75,&S);
		push("4523210777","Susi",78.85,&S);
		push("4523210888","Nuri",98.65,&S);
		push("4523210999","Bimo",68.55,&S);
		push("4523210555","Arif",78.85,&S);
		push("4523210444","Rido",98.65,&S);
		push("4523210222","Ella",68.55,&S);
		cetakstack(S);
		cout<<"================="<<endl;
		cout<<endl;
		cout<<endl;
		pop(&S);
		cetakstack(S);
		cout<<endl;
		cout<<endl;
		pop(&S);
		cetakstack(S);
		cout<<"================"<<endl;
		return 0;
	}