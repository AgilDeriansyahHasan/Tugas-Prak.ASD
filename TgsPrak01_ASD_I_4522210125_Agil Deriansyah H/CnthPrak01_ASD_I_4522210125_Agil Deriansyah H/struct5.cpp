#include <iostream> 
using namespace std;

int main() {
	int n, *pn, **ppn;
	n=44;
//inisialisasi pointer pn dengan alamat address n
	pn = &n;
//inisialisasi pointer ppn dengan isi variabel dalam hexa ppn &pn;
	ppn = &pn;
//menampilkan isi variabel, address dan isi variabel dalam hexa n cout << endl;
	cout<<endl;
	cout<<" Isi variabel [n*pn *ppn] = "<<n<<" - "<<*pn<<" - "<<*ppn<< endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<< endl;
	cout<<"Alamat variabel [sn &pn &ppn] = "<<&n<<" - "<<&pn<<" - "<<&ppn<< endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << endl;
	cout<<" Isi variabel dalam HEXA [n-pn-ppn] = " <<n<<" - "<<pn<<" - "<<ppn<< endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << endl; 
cin.get();}