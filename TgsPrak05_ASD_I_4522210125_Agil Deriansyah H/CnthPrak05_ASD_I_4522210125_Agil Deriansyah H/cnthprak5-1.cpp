#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
}nilaimk;

typedef struct elm *alamatelm;
typedef struct elm{
	nilaimk kontainer;
	alamatelm next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

void buatqukosong(queue *Q){
	(*Q).first=NULL;
	(*Q).last=NULL;
}

int iskosong(queue Q){
	bool hasil=false;
	
	if(Q.first==NULL){
		hasil=true;
	}
	return hasil;
}

int jmlelemen(queue Q){
	int hasil=0;
	
	if(Q.first != NULL){
		elemen *bantu;
		bantu = Q.first;
		
		while(bantu != NULL){
			hasil = hasil+1;
			bantu=bantu->next;
		}
	}
	return hasil;
}

void add(string npm, string nama_mhs, double nilai, queue *Q){
	elemen *info;
	info = new elemen;
	info -> kontainer.npm = npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	info -> next=NULL;
	
	if((*Q).first==NULL){
		(*Q).first=info;
	}
	else{
		(*Q).last -> next =info;
	}
	(*Q).last=info;
	info=NULL;
}

void del(queue *Q){
	if((*Q).first != NULL){
		elemen *hapus =(*Q).first;
		
		if(jmlelemen(*Q)==1){
			(*Q).first=NULL;
			(*Q).last=NULL;
		}
		else{
			(*Q).first=(*Q).first->next;
			hapus -> next=NULL;
		}
		delete hapus;
	}
}

void cetakqueue(queue Q)
{
	if(Q.first!=NULL){
		cout<<"Menampilkan Queue"<<endl;
		elemen *bantu = Q.first;
		int i =1;
		while(bantu!=NULL){
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Elemen Ke :"<<i<<endl;
			cout<<"Nomor Pokok Mahasiswa :"<< bantu->kontainer.npm<<endl;
			cout<<"Nama Mahasiswa :"<< bantu->kontainer.nama_mhs<<endl;
			cout<<"Nilai Mahasiswa :"<< bantu->kontainer.nilai<<endl;
			bantu=bantu->next;
			i=i+1;
		}
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	}
	else{
		cout<<"Queue Kosong"<<endl;
	}
}

int main(){
	queue Q;
	buatqukosong (&Q);
	cetakqueue(Q);
	cout<<endl;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
	add("4523210666","Budi",88.75,&Q);
	add("4523210777","Susi",78.85,&Q);
	add("4523210888","Nuri",98.65,&Q);
	add("4523210999","Bimo",68.55,&Q);
	add("4523210555","Arif",78.85,&Q);
	add("4523210444","Rido",98.65,&Q);
	add("4523210222","Ella",68.55,&Q);
	cetakqueue(Q);
	cout<<"=================="<<endl;
	cout<<endl;
	cout<<endl;
	del(&Q);
	cetakqueue(Q);
	cout<<endl;
	cout<<endl;
	del(&Q);
	cetakqueue(Q);
	cout<<"================="<<endl;
	return 0;
}