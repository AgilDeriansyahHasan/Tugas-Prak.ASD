#include <iostream>
using namespace std;

struct node {
    node* left;
    char data;
    node* right;
};

typedef node simpul;
simpul* root, *P, *current;
simpul* Q[129];

void inisialisasi() {
    root = NULL;
    P = NULL;
}

void buatSimpul(char X) {
    P = new simpul;
    if (P != NULL) {
        P->data = X;
        P->left = NULL;
        P->right = NULL;
    } else {
        cout << "Memory Heap Full" << endl;
        exit(1);
    }
}

void buatSimpulakar() {
    if (root == NULL) {
        if (P != NULL) {
            root = P;
            root->left = NULL;
            root->right = NULL;
        } else {
            cout << "Simpul Belum Dibuat" << endl;
        }
    } else {
        cout << "Pohon Sudah Ada!!!!!!" << endl;
    }
}

void inserturutnomor() {
    int i = 1, j = 1, flaq = 0;
    char X;
    Q[i] = root;
    while (flaq == 0 && j < 129) {
        cout << "Masukkan karakter (0 untuk berhenti): ";
        cin >> X;
        if (X != '0') {
            buatSimpul(X);
            current = Q[i];
            if (current->left == NULL) {
                current->left = P;
            } else if (current->right == NULL) {
                current->right = P;
            } else {
                cout << "Subtree penuh!" << endl;
                continue;
            }
            j++;
            Q[j] = P;
        } else {
            flaq = 1;
            j++;
            Q[j] = NULL;
        }
        i++;
    }
}

void bacaurutnomor() {
    int i = 1, j = 1, n = 1, counter = 0;
    while (Q[i] != NULL) {
        current = Q[i];
        cout << current->data << " ";
        counter++;
        if (counter == n) {
            cout << endl;
            counter = 0;
            n = n + 2;
        }
        if (current->left != NULL) {
            j++;
            Q[j] = current->left;
        }
        if (current->right != NULL) {
            j++;
            Q[j] = current->right;
        }
        i++;
    }
    cout << endl;
}

int main() {
    inisialisasi();
    char akar;
    cout << "Masukkan karakter untuk akar: ";
    cin >> akar;
    buatSimpul(akar);
    buatSimpulakar();
    inserturutnomor();
    bacaurutnomor();
    return 0;
}
