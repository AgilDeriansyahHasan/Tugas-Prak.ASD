#include <iostream>
using namespace std;

typedef struct simpul *altsimpul;
typedef struct jalur *altjalur;

typedef struct simpul {
    char kontainersimpul;
    altsimpul nextsimpul;
    altjalur arc;
} cansimpul;

typedef struct jalur {
    int kontainerjalur;
    altjalur nextjalur;
    cansimpul *tujuan;
} canjalur;

typedef struct {
    cansimpul* first;
} graph;

void simpulbaru(graph *G, char c) {
    cansimpul *baru = new cansimpul;
    baru->kontainersimpul = c;
    baru->nextsimpul = NULL;
    baru->arc = NULL;
    if ((*G).first == NULL) {
        (*G).first = baru;
    } else {
        cansimpul *last = (*G).first;
        while (last->nextsimpul != NULL) {
            last = last->nextsimpul;
        }
        last->nextsimpul = baru;
    }
}

void tambahjalur(cansimpul *awal, cansimpul *tujuan, int beban) {
    canjalur *baru = new canjalur;
    baru->kontainerjalur = beban;
    baru->nextjalur = NULL;
    baru->tujuan = tujuan;
    if (awal->arc == NULL) {
        awal->arc = baru;
    } else {
        canjalur *last = awal->arc;
        while (last->nextjalur != NULL) {
            last = last->nextjalur;
        }
        last->nextjalur = baru;
    }
}

cansimpul* findsimpul(char c, graph G) {
    cansimpul *hasil = NULL;
    cansimpul *bantu = G.first;
    bool ketemu = false;
    while ((bantu != NULL) && (ketemu == false)) {
        if (bantu->kontainersimpul == c) {
            hasil = bantu;
            ketemu = true;
        } else {
            bantu = bantu->nextsimpul;
        }
    }
    return hasil;
}

void deljalur(char ctujuan, cansimpul *awal) {
    canjalur *hapus = awal->arc;
    if (hapus != NULL) {
        canjalur *prev = NULL;
        bool ketemu = false;
        while ((hapus != NULL) && (ketemu == false)) {
            if (hapus->tujuan->kontainersimpul == ctujuan) {
                ketemu = true;
            } else {
                prev = hapus;
                hapus = hapus->nextjalur;
            }
        }
        if (ketemu) {
            if (prev == NULL) {
                awal->arc = hapus->nextjalur;
            } else {
                prev->nextjalur = hapus->nextjalur;
            }
            delete hapus;
        }
    }
}

void tampilkanGraph(graph G) {
    cansimpul *simpul = G.first;
    while (simpul != NULL) {
        cout << "Simpul " << simpul->kontainersimpul << " terhubung dengan: ";
        canjalur *jalur = simpul->arc;
        while (jalur != NULL) {
            cout << jalur->tujuan->kontainersimpul << " (beban: " << jalur->kontainerjalur << "), ";
            jalur = jalur->nextjalur;
        }
        cout << endl;
        simpul = simpul->nextsimpul;
    }
}

int main() {
    graph G;
    G.first = NULL;

    simpulbaru(&G, 'A');
    simpulbaru(&G, 'B');
    simpulbaru(&G, 'C');

    cansimpul *nodeA = findsimpul('A', G);
    cansimpul *nodeB = findsimpul('B', G);
    cansimpul *nodeC = findsimpul('C', G);

    tambahjalur(nodeA, nodeB, 5);
    tambahjalur(nodeA, nodeC, 10);

    cout << "Graph sebelum menghapus jalur:" << endl;
    tampilkanGraph(G);

    deljalur('B', nodeA);

    cout << "Graph setelah menghapus jalur:" << endl;
    tampilkanGraph(G);

    return 0;
}
