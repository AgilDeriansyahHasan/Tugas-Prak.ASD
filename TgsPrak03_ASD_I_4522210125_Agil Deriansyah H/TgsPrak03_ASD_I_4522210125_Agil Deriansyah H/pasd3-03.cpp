#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct node {
    string nama;
    int nilai;
    struct node* next;
};

typedef struct node simpul;
simpul* first, * last;

void buat_simpul(string nama, int nilai);
void awal();
void insertkanan();
void cetak();

int main() {
	int  i;
    string nama[5] = {"Fanny", "Tiara", "Ilham", "Cintyhya", "Candra"};
    int nilai[5] = {10, 63, 28, 66, 22};

    first = NULL;

    for ( i = 0; i < 5; i++) {
        buat_simpul(nama[i], nilai[i]);
        insertkanan();
    }

    cout << "Nama :";
    cetak();
    cout << endl;

    return 0;
}

void buat_simpul(string nama, int nilai) {
    simpul* P = new simpul();
    P->nama = nama;
    P->nilai = nilai;
    P->next = NULL;
    if (first == NULL) {
        first = P;
        last = P;
    }
    else {
        last->next = P;
        last = P;
    }
}

void insertkanan() {
}

void cetak() {
    simpul* Q = first;
    while (Q != NULL) {
        cout << " " << Q->nama << " --" << Q->nilai << " ";
        Q = Q->next;
    }
}
