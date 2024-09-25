#include <iostream>
#include <cstring> 
#include <cstdlib>
#define hashsize 5

using namespace std;

typedef struct _node {
    char *nama;
    char *desc;
    struct _node *next;
} node;

static node *hashtab[hashsize];

void inithashtab() {
    for (int i = 0; i < hashsize; i++) {
        hashtab[i] = NULL;
    }
}

unsigned int hashfunc(char *s) {
    unsigned int h = 0;
    while (*s) {
        h = *s + h * 31;
        s++;
    }
    return h % hashsize;
}

node* lookup(char *n) {
    unsigned int hi = hashfunc(n);
    node* np = hashtab[hi];
    while (np != NULL) {
        if (strcmp(np->nama, n) == 0) {
            return np;
        }
        np = np->next;
    }
    return NULL;
}

char* m_strdup(const char *o) {
    int l = strlen(o) + 1;
    char *ns = (char*)malloc(l * sizeof(char));
    if (ns != NULL) {
        strcpy(ns, o);
    }
    return ns;
}

char* get(char* nama) {
    node* n = lookup(nama);
    if (n == NULL) {
        return NULL;
    } else {
        return n->desc;
    }
}

int install(char* nama, char* desc) {
    unsigned int hi;
    node* np;
    if ((np = lookup(nama)) == NULL) {
        hi = hashfunc(nama);
        np = (node*)malloc(sizeof(node));
        if (np == NULL) {
            return 0;
        }
        np->nama = m_strdup(nama);
        if (np->nama == NULL) return 0;
        np->desc = NULL;
        np->next = hashtab[hi];
        hashtab[hi] = np;
    } else {
        free(np->desc);
    }
    np->desc = m_strdup(desc);
    if (np->desc == NULL) return 0;
    return 1;
}

void displaytable() {
    for (int i = 0; i < hashsize; i++) {
        if (hashtab[i] != NULL) {
            node* t = hashtab[i];
            while (t != NULL) {
                cout << t->nama << ": " << t->desc << endl;
                t = t->next;
            }
        }
    }
}

void cleanup() {
    for (int i = 0; i < hashsize; i++) {
        node* np = hashtab[i];
        while (np != NULL) {
            node* t = np->next;
            free(np->nama);
            free(np->desc);
            free(np);
            np = t;
        }
        hashtab[i] = NULL;
    }
}

void data() {
    const char* nama[] = {"nama", "alamat", "telepon", "cita-cita", "sekolah"};
    const char* descs[] = {"ichan", "Depok", "08999999991", "Dosen", "Mahasiswa"};
    inithashtab();
    for (int i = 0; i < 5; i++) {
        install((char*)nama[i], (char*)descs[i]);
    }
    install((char*)"telpon", (char*)"9999999");
    cout << "Hasilnya adalah:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << nama[i] << ": " << get((char*)nama[i]) << endl;
    }
    cout << "telpon: " << get((char*)"telpon") << endl;
}

int main() {
    int pilihan;
    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~++++++++++++++" << endl;
        cout << "| Nama || Alamat || Telpon || Cita-Cita || Sekolah |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~++++++++++++++" << endl;
        cout << "~~~~~~~~~~~~~~~~" << endl;
        cout << "| Menu Pilihan |" << endl;
        cout << "~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Tampilan Data" << endl;
        cout << "2. Display Data" << endl;
        cout << "3. CleanUp" << endl;
        cout << "4. Exit" << endl;
        cout << "| Pilihan Anda? |" << endl;
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                data();
                break;
            case 2:
                displaytable();
                break;
            case 3:
                cleanup();
                cout << "Data telah dibersihkan." << endl;
                break;
            case 4:
                cleanup();
                cout << "Terima Kasih! " << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);
    return 0;
}
