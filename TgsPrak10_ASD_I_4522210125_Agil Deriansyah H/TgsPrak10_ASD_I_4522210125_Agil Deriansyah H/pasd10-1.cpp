#include <iostream>
using namespace std;

class btreenode {
    char *keys;
    int t, n;
    bool leaf;
    btreenode **children;

public:
    btreenode(int t, bool leaf);
    void insertNonFull(char k);
    void splitChild(int i, btreenode *y);
    void traverse();
    btreenode *search(char k);
    friend class btree;
};

class btree {
    int t;
    btreenode *root;

public:
    btree(int t) : t(t), root(nullptr) {}
    void traverse() { if (root != nullptr) root->traverse(); }
    btreenode* search(char k) { return (root == nullptr) ? nullptr : root->search(k); }
    void insert(char k);
};

btreenode::btreenode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    keys = new char[2 * t - 1];
    children = new btreenode *[2 * t];
    n = 0;
}

void btreenode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) {
            children[i]->traverse();
        }
        cout << " " << keys[i];
    }
    if (!leaf) {
        children[i]->traverse();
    }
}

btreenode *btreenode::search(char k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;
    if (keys[i] == k)
        return this;
    if (leaf)
        return nullptr;
    return children[i]->search(k);
}

void btree::insert(char k) {
    if (root == nullptr) {
        root = new btreenode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            btreenode *s = new btreenode(t, false);
            s->children[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

void btreenode::insertNonFull(char k) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;
        if (children[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < k)
                i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

void btreenode::splitChild(int i, btreenode *y) {
    btreenode *z = new btreenode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];
    children[i + 1] = z;
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n++;
}

int main() {
    btree t(3);
    t.insert('F');
    t.insert('L');
    t.insert('A');
    t.insert('G');
    t.insert('K');
    t.insert('M');
    t.insert('C');
    t.insert('D');
    t.insert('E');
    t.insert('H');
    t.insert('I');
    
    cout << "Pohon Dengan Menggunakan B-Tree" << endl;
	cout << "        (t = 5):" << endl;
    t.traverse();
    cout << endl;

    char k = 'A';
    (t.search(k) != NULL)?cout<<"Kunci yang dicari "<< k << "= Ditemukan" : cout<<"Kunciyang dicari "<<k<<"= Tidak Ditemukan";
    cout << endl;
    k = 'Z';
    (t.search(k) != NULL)?cout<<"Kunci yang dicari "<< k << "= Ditemukan" : cout<<"Kunciyang dicari "<<k<<"= Tidak Ditemukan";
    cout << endl;

    return 0;
}
