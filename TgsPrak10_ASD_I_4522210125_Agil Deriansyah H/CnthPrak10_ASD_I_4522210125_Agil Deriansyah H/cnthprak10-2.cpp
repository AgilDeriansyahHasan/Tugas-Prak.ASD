#include <iostream>
using namespace std;

struct canbtree {
    int *d;
    canbtree **cananakpointer;
    bool l;
    int n;
} *r = NULL, *np = NULL, *x = NULL;

canbtree* init() {
    int i;
    np = new canbtree;
    np->d = new int[6];
    np->cananakpointer = new canbtree*[7];
    np->l = true;
    np->n = 0;
    for (i = 0; i < 7; i++) {
        np->cananakpointer[i] = NULL;
    }
    return np;
}

void pohonb(canbtree *p) {
    if (!p) return;
    int i;
    for (i = 0; i < p->n; i++) {
        if (!p->l) {
            pohonb(p->cananakpointer[i]);
        }
        cout << " " << p->d[i];
    }
    if (!p->l) {
        pohonb(p->cananakpointer[i]);
    }
    cout << endl;
}

void urut(int *p, int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

int pecahanak(canbtree *x, int i) {
    int j, mid;
    canbtree *np3;
    np3 = init();
    np3->l = true;

    if (i == -1) {
        mid = x->d[2];
        x->d[2] = 0;
        x->n--;
    }
    return mid;
}

void sisip(int a) {
    int i, t;
    x = r;
    if (x == NULL) {
        r = init();
        x = r;
    } else {
        if (x->l == true && x->n == 6) {
            t = pecahanak(x, -1);
            x = r;
            for (i = 0; i < (x->n); i++) {
                if ((a > x->d[i]) && (a < x->d[i + 1])) {
                    i++;
                    break;
                } else if (a < x->d[0]) {
                    break;
                } else {
                    continue;
                }
            }
            x = x->cananakpointer[i];
        } else {
            while (x->l == false) {
                for (i = 0; i < (x->n); i++) {
                    if ((a > x->d[i]) && (a < x->d[i + 1])) {
                        i++;
                        break;
                    } else if (a < x->d[0]) {
                        break;
                    } else {
                        continue;
                    }
                }
                if ((x->cananakpointer[i])->n == 6) {
                    t = pecahanak(x, i);
                    x->d[x->n] = t;
                    x->n++;
                    urut(x->d, x->n);
                } else {
                    x = x->cananakpointer[i];
                }
            }
        }
    }
    x->d[x->n] = a;
    urut(x->d, ++x->n);
}

int main() {
    int i, n, t;
    cout << "Masukkan Jumlah Elemen yang akan diinput = ";
    cin >> n;
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << "Masukkan Isi Elemen = ";
        cin >> t;
        sisip(t);
    }
    cout << endl;
    cout << "Hasil Pengurutan Menggunakan Btree" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    pohonb(r);
}
