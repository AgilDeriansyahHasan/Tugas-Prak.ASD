#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>

struct Node {
    struct Node *left;
    struct Node *right;
    char info;
    struct Node *link;
};

typedef struct Node simpul;
simpul *root, *P, *Q, *lastcurrent, *current, *lastkiri;
const int kiri = 0, kanan = 1;
int i, n, flaq, flaqhabis, level;
char X;
char A[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void inisialisasi() {
    root = NULL;
}

void buatsimpul(char item) {
    P = (simpul*)malloc(sizeof(simpul));
    if (P != NULL) {
        P->info = item;
        P->left = NULL;
        P->right = NULL;
        P->link = NULL;
    } else {
        std::cout << "Memory Penuh" << std::endl;
        exit(1);
    }
}

void buatsimpulakar() {
    if (root == NULL) {
        root = P;
        lastcurrent = root;
        lastkiri = root;
        flaq = kiri;
        level = 0;
        n = 1;
        flaqhabis = 1;
    } else {
        std::cout << "Pohon Sudah Ada" << std::endl;
        exit(1);
    }
}

void tambahsimpul() {
    if (root != NULL) {
        n = n + 1;
        if (flaqhabis == 1) {
            flaqhabis = 0;
            current = P;
            lastcurrent->left = P;
            flaq = kanan;
            level = level + 1;
        } else {
            if (flaq == kiri) {
                flaq = kanan;
                lastcurrent->left = P;
                current->link = P;
                current = P;
            } else {
                lastcurrent->right = P;
                current->link = P;
                flaq = kiri;
                if (n == (pow(2, level + 1) - 1)) {
                    flaqhabis = 1;
                    lastcurrent = lastkiri->left;
                    lastkiri = lastkiri->left;
                }
            }
        }
    }
}

void bacaurutnomor() {
    int i, j;
    simpul *Q[125], *current;
    i = 1;
    j = 1;
    Q[i] = root;
    while (Q[i] != NULL) {
        current = Q[i];
        std::cout << current->info << std::endl;
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
}

int main() {
    int i, n;
    char X;
    int num[20] = {0, 22, 66, 28, 11, 7, 63, 14, 4, 10};
    char infox[20] = "PANCASILA";
    inisialisasi();
    X = infox[0];
    buatsimpul(X);
    buatsimpulakar();
    for (i = 1; i < 9; i++) {
        n = num[i];
        X = infox[i];
        buatsimpul(X);
        tambahsimpul();
    }
    bacaurutnomor();
    std::cin.get();
    return 0;
}
