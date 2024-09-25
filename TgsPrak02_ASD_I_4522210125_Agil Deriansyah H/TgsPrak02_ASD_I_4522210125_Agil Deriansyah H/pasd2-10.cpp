#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct {
    int top;
    NilaiMK Dat[10];
} stack;

void buatSTkosong(stack *S) {
    (*S).top = -1;
}

bool isKosong(stack S) {
    return (S.top == -1);
}

bool isPenuh(stack S) {
    return (S.top == 9);
}

void push(stack *S) {
    if (isPenuh(*S)) {
        cout << "Stack Penuh" << endl;
        return;
    }

    string npm, nama_mhs;
    double nilai;

    cout << "Masukkan Nomor Pokok Mahasiswa: ";
    cin >> npm;
    cout << "Masukkan Nama Mahasiswa: ";
    cin  >> nama_mhs;
    cout << "Masukkan Nilai Mahasiswa: ";
    cin >> nilai;

    if (isKosong(*S)) {
        (*S).top = 0;
    } else {
        (*S).top++;
    }

    (*S).Dat[(*S).top].npm = npm;
    (*S).Dat[(*S).top].nama_mhs = nama_mhs;
    (*S).Dat[(*S).top].nilai = nilai;
}

void pop(stack *S) {
    if (isKosong(*S)) {
        cout << "Stack Kosong" << endl;
        return;
    }

    (*S).top--;
}

void cetakstack(stack S) {
	int i ;
    if (isKosong(S)) {
        cout << "Stack Kosong" << endl;
        return;
    }

    cout << "Menampilkan Stack" << endl;
    for (i = S.top; i >= 0; i--) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout<<endl;
        cout << "Elemen Ke : " << i << endl;
        cout << "Nomor Pokok Mahasiswa :" << S.Dat[i].npm << endl;
        cout << "Nama Mahasiswa :" << S.Dat[i].nama_mhs << endl;
        cout << "Nilai Mahasiswa :" << S.Dat[i].nilai << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

int main() {
    stack S;

    buatSTkosong(&S);
    cetakstack(S);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    push(&S);
    push(&S);
    push(&S);
    push(&S);
    cetakstack(S);
    cout << "=================================" << endl;
    cout << endl;
    cout << endl;
    pop(&S);
    cetakstack(S);
    cout << endl;
    cout << endl;
    pop(&S);
    cetakstack(S);
    cout << "=================================" << endl;
    return 0;
}
