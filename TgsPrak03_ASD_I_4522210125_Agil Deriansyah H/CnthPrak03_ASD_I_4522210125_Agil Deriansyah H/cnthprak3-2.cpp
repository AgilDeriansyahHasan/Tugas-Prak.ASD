#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void buat_simpul(int X);
void awal();
void cetak();
void insertkanan();
struct node{
	int info;
	struct node *link;};
typedef struct node simpul;
simpul *P, *first, *last, *Q;
int X;

int main(){
	int A[7] = {22,28,7,11,66,63,10};
	int I;
	first = NULL;
	I=0;
	X=A[I];
	buat_simpul(X);
	awal();
	for(I=1;I<=6;I++)
	{
		X=A[I];
		buat_simpul(X);
	insertkanan();}
	cout<<"Nilai Sebelum Dilakukan Insert Kanan :";
	cetak();
	X=100;
	buat_simpul(X);
	insertkanan();
	cout<<endl;
	cout<<"Nilai Setelah Dilakukan Insert Kanan :";
	cetak();
	cout<<endl;
cin.get();}

void buat_simpul(int X){
	P=(simpul*) malloc(sizeof(simpul));
	if(P!=NULL){
	P -> info =X;}
	else {
		cout<<"Pembuatan Simpul Tidak Berhasil"<<endl;
		cin.get();
exit(1);}}

void awal(){
	first=P;
	last=P;
P -> link=NULL;}

void insertkanan(){
	last -> link = P;
	last=P;
P->link=NULL;}

void cetak(){
	int X;
	Q=first;
	while(Q!=NULL){
		X=Q->info;
		cout<<" "<<X;
Q=Q->link;}}