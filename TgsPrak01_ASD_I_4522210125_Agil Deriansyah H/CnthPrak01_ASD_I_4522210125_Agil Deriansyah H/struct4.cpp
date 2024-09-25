#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
	int i;
	char *namaku,nm[4]={'A','G','I','L'};
	cout<<"Nama Ku" << endl;
	cout<<"~~~~~~~"<<endl;
	for(i=0;i<4;i++){
		namaku=&nm[i];
	cout << " "<<*namaku<<endl;}
	cin.get();
}