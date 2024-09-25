#include <iostream>
using namespace std;

typedef struct node *alamatnode;
typedef struct node {
    char info;
    alamatnode right;
    alamatnode left;
} NODE;

typedef struct {
    NODE* root;
} TREE;

void BuatTree(char C, TREE *T) {
    NODE *baru = new NODE;
    baru->info = C;
    baru->right = NULL;
    baru->left = NULL;
    T->root = baru;
}

void TambahKanan(char C, NODE *root) {
    if (root->right == NULL) {
        NODE *baru = new NODE;
        baru->info = C;
        baru->right = NULL;
        baru->left = NULL;
        root->right = baru;
    } else {
        cout << "Sub Tree Kanan telah disisi" << endl;
    }
}

void TambahKiri(char C, NODE *root) {
    if (root->left == NULL) {
        NODE *baru = new NODE;
        baru->info = C;
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    } else {
        cout << "Sub Tree Kiri telah disisi" << endl;
    }
}

void HapusAll(NODE *root) {
    if (root != NULL) {
        HapusAll(root->left);
        HapusAll(root->right);
        delete root;
    }
}

void HapusKanan(NODE *root) {
    if (root != NULL && root->right != NULL) {
        HapusAll(root->right);
        root->right = NULL;
    }
}

void HapusKiri(NODE *root) {
    if (root != NULL && root->left != NULL) {
        HapusAll(root->left);
        root->left = NULL;
    }
}

void CetakTreePreOrder(NODE *root) {
    if (root != NULL) {
        cout << root->info << " ";
        CetakTreePreOrder(root->left);
        CetakTreePreOrder(root->right);
    }
}

void CetakTreeInOrder(NODE *root) {
    if (root != NULL) {
        CetakTreeInOrder(root->left);
        cout << root->info << " ";
        CetakTreeInOrder(root->right);
    }
}

void CetakTreePostOrder(NODE *root) {
    if (root != NULL) {
        CetakTreePostOrder(root->left);
        CetakTreePostOrder(root->right);
        cout << root->info << " ";
    }
}

void CopyTree(NODE *root1, NODE **root2) {
    if (root1 != NULL) {
        *root2 = new NODE;
        (*root2)->info = root1->info;
        (*root2)->left = NULL;
        (*root2)->right = NULL;
        CopyTree(root1->left, &(*root2)->left);
        CopyTree(root1->right, &(*root2)->right);
    }
}

bool isEqual(NODE *root1, NODE *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->info == root2->info &&
            isEqual(root1->left, root2->left) &&
            isEqual(root1->right, root2->right));
}

int main() {
    TREE T;
    BuatTree('R', &T);
    TambahKiri('S', T.root);
    TambahKanan('U', T.root);
    TambahKiri('V', T.root->left);
    TambahKanan('W', T.root->left);
    TambahKiri('Y', T.root->right);
    TambahKanan('Z', T.root->right);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~  PreOrder  ~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    CetakTreePreOrder(T.root);
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~  InOrder  ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    CetakTreeInOrder(T.root);
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~ PostOrder ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    CetakTreePostOrder(T.root);
    cout << endl;

    TREE T2;
    CopyTree(T.root, &T2.root);

    if (isEqual(T.root, T2.root)) {
        cout << "Tree yang sama" << endl;
    } else {
        cout << "Tree yang tidak sama" << endl;
    }

    HapusKanan(T.root->left);
    HapusKiri(T.root->left);
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "PreOrder Setelah Dihapus" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    CetakTreePreOrder(T.root);
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
