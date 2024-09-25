#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cstring>

#define hashsize 100
#define kodemk 30
#define namamk 13

using namespace std;

struct hashdata {
    char kode[kodemk];
    char nama[namamk];
};

static hashdata *hashtable[hashsize];

void clear();
void insert(hashdata *);
void searching(hashdata *);
int searchingprocess(hashdata *, int);
void deleting(hashdata *);
int hashfunction(hashdata *);
bool isindexempty(int);
int characteramount(char []);
void displaytable();

int main() {
    char ulang = 'Y', menu;
    clear();
    do {
        system("cls");
        puts("Proses Hash Table");
        puts("");
        puts("1. Input");
        puts("2. Delete");
        puts("3. Find");
        puts("4. Display");
        puts("5. Clear");
        puts("x. Keluar");
        puts("");
        cout << "Menu Pilihan Anda : "; cin >> menu;
        
        switch (menu) {
            case '1': {
                hashdata *array; 
				array = new hashdata;
                puts("");
                cout << "KodeMK :"; cin >> array->kode;
                cout << "MataKuliah :"; cin >> array->nama;
                cout << endl;
                insert(array);
                break;
            }
            case '2': {
                hashdata *hapus; 
				hapus = new hashdata;
                cout << "Hapus MataKuliah(KodeMK) :"; cin >> hapus->kode;
                deleting(hapus);
                delete hapus;
                break;
            }
            case '3': {
                hashdata *cari;
				cari = new hashdata;
                cout << "Cari MataKuliah (KodeMK) : "; cin >> cari->kode;
                searching(cari);
                delete cari; 
                break;
            }
            case '4':
                displaytable();
                break;
            case '5':
                clear();
                puts("Tabel Hash telah dikosongkan.");
                break;
            case 'x':
            case 'X':
                ulang = 'T';
                break;
            default:
                puts("Pilihan diluar Menu yang Tersedia");
                break;
        }
        cin.get();
    } 
	while (toupper(ulang) == 'Y');
}

void clear() {
    for (int i = 0; i < hashsize; i++)
        hashtable[i] = NULL;
}

void insert(hashdata *array) {
    int rec;
    rec = hashfunction(array);
    hashtable[rec] = array;
    cout << "Input Successfully" << endl;
    cout << "Data DiSimpan pada record indeks " << rec << endl;
    cin.get();
}

void searching(hashdata *cari) {
    int rec;
    rec = hashfunction(cari);
    rec = searchingprocess(cari, rec);
    if (rec >= 0) {
        cout << "Data ditemukan pada record indeks " << rec << endl;
        cout << "Isi data :" << endl;
        cout << "=> KodeMK :" << hashtable[rec]->kode << endl;
        cout << "=> MataKuliah :" << hashtable[rec]->nama << endl;
    } else
        cout << "Maaf Data tidak ditemukan." << endl;
    cin.get();
}

int searchingprocess(hashdata *cari, int rec) {
    int m, n, j = 0;
    bool equal = true;
    if (isindexempty(rec) == false) {
        n = characteramount(cari->kode);
        m = characteramount(hashtable[rec]->kode);
        if (n == m) {
            while ((equal == true) && (cari->kode[j] != '\0')) {
                if (tolower(cari->kode[j]) != tolower(hashtable[rec]->kode[j]))
                    equal = false;
                j++;
            }
            if (equal == true)
                return rec;
            else
                return -1;
        } else return -1;
    } else
        return -1;
    cin.get();
}

void deleting(hashdata *hapus) {
    int rec;
    rec = hashfunction(hapus);
    rec = searchingprocess(hapus, rec);
    if (rec >= 0) {
        cout << "Data :" << endl;
        cout << "=> KodeMK :" << hashtable[rec]->kode << endl;
        cout << "=> MataKuliah :" << hashtable[rec]->nama << endl;
        cout << "Terhapus" << endl;
        hashtable[rec] = NULL;
    } else
        cout << "Maaf Data tidak ditemukan" << endl;
    cin.get();
}

int hashfunction(hashdata *array) {
    int value = 0, rec, n;
    n = characteramount(array->kode);
    for (int i = 0; i < n; i++)
        value += array->kode[i];
    rec = value % hashsize;
    return rec;
}

bool isindexempty(int rec) {
    if (hashtable[rec] == NULL)
        return true;
    else
        return false;
}

int characteramount(char array[]) {
    int jumlah = 0;
    for (int i = 0; array[i] != '\0'; i++)
        jumlah++;
    return jumlah;
}

void displaytable() {
    cout << "\n";
    cout << "|~~~~~~~~|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "| Indeks |   KodeMK  |    Nama Mata Kuliah    |" << endl;
    cout << "|~~~~~~~~|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    for (int i = 0; i < hashsize; i++) {
        if (isindexempty(i) == false)
            cout << setw(6) << i << " " << hashtable[i]->kode << "\t " << hashtable[i]->nama << endl;
    }
    cin.get();
}
