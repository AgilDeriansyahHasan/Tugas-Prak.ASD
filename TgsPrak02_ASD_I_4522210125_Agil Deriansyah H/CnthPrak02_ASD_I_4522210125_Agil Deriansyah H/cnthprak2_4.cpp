#include <iostream> 
#include <string.h>
using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct{
    int top;
    NilaiMK Dat [10];
} stack;

void buatSTkosong(stack *S) { 
    (*S).top = -1;
}

bool isKosong(stack S){ 
    return (S.top == -1);
}

bool isPenuh(stack S){
    return (S.top == 9);
}

void push(string npm, string nama_mhs, double nilai, stack *S){
    if(isPenuh(*S)){
        cout << "Stack Penuh" << endl;
    }
    else{
        (*S).top = (*S).top + 1;
        (*S).Dat[(*S).top].npm = npm;
        (*S).Dat[(*S).top].nama_mhs = nama_mhs;
        (*S).Dat[(*S).top].nilai = nilai;
    }
}

void pop(stack *S){
    if(!isKosong(*S)){
        (*S).top = (*S).top - 1;
    }
}

void cetakstack(stack S){
    if(!isKosong(S)){
        cout << "Menampilkan Stack" << endl;
        for(int i = S.top; i >= 0; i--){
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen Ke : " << i << endl;
            cout << "Nomor Pokok Mahasiswa : " << S.Dat[i].npm << endl;
            cout << "Nama Mahasiswa : " << S.Dat[i].nama_mhs << endl;
            cout << "Nilai Mahasiswa : " << S.Dat[i].nilai << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    else{
        cout << "Stack Kosong" << endl;
    }
}   

int main(){
    stack S;
    
    buatSTkosong(&S);
    cetakstack(S);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    push("4523210666","Budi",88.75,&S);
    push("4523210777","Susi",78.85,&S);
    push("4523210888","Sari",98.65,&S);
    push("4523210999","Bimo",68.55,&S);
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