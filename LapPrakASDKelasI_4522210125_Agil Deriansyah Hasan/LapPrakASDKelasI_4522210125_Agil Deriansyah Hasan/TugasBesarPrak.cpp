/* 
	Nama		  : Agil Deriansyah Hasan
	NPM	              : 4522210125
	Mata Kuliah      : Prak. Algoritma dan Struktur Data
	Kelas                 : I
	Dosen Pengajar : Dra.SRI REZEKI CANDRA NURSARI,M.Kom

01 - Si Penjualan Toko Elektonik 

Tidak Menggunakan Perintah Inputan

Materi :
- Struktur/Class
- Pointer
- SDL - Stack Menggunakan Linked List
- Heap Sort - Descending
- Sequential Search
- Binary Tree Penelusuran PostOrder
*/

#include <iostream>
#include <string>
using namespace std;

typedef struct stackbarang{
	string kode;
	string nama_barang;
	double harga;
} stackbarang1;
typedef struct elm *alamatelm;
typedef struct elm{
	stackbarang1 kontainer;
	alamatelm next;
} elemen;

typedef struct{
	elemen* top;
} stack;

typedef struct node *alamatnode;
typedef struct node {
    char info;
    alamatnode right;
    alamatnode left;
} NODE;

typedef struct {
    NODE* root;
} TREE;

char Nama[50], No_Telp[15], Email[50], Kode_Barang[10],Nama_Barang[20]; 
int Jumlah_Barang, Harga_Barang;
int search01_a(string data[], int jumlahElemen, string elemen_a);
string getItemName(string searchelemen_a);
void menupilihan();

void buatstack(stack* S) {
    (*S).top = NULL;
}

bool stackkosong(stack S) {
    return S.top == NULL;
}

int jmlelemen(stack S) {
    int hasil = 0;

    if (S.top != NULL) {
        elemen* bantu = S.top;

        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(string kode, string nama_barang, double harga, stack* S) {
    elemen* info = new elemen;
	info->kontainer.kode = kode;
	info->kontainer.nama_barang = nama_barang;
    info->kontainer.harga = harga;

    info->next = (*S).top;
    (*S).top = info;
}

void pop(stack* S) {
    if ((*S).top != NULL) {
        elemen* hapus = (*S).top;

        if (jmlelemen(*S) == 1) {
            (*S).top = NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        delete hapus;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void cetakstack(stack S) {
    if (S.top != NULL) {
        cout << "Menampilkan Stack" << endl;
        elemen* bantu = S.top;
        int i = 1;
        while (bantu != NULL) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Barang Ke :" << i << endl;
			cout << "Nama Barang  :" << bantu->kontainer.nama_barang << endl;
            cout << "Harga Barang :" << bantu->kontainer.harga << endl;
			cout << "Kode Barang  :" << bantu->kontainer.kode << endl;
            bantu = bantu->next;
            i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

void cetakstack1() {
    stack S;
    buatstack(&S);
    cetakstack(S);
	push("P010", "Mouse", 80000, &S);
	push("P009", "Printer", 120000, &S);
	push("P008", "Headset", 50000, &S);
	push("P007", "Speaker", 75000, &S);
	push("P006", "Tablet", 350000, &S);
    push("P005", "Kamera", 500000, &S);
	push("P004", "Jam Tangan", 200000, &S);
	push("P003", "Komputer", 800000, &S);
	push("P002", "Laptop", 650000, &S);
    push("P001", "Handphone", 150000, &S);
	cetakstack(S);
	menupilihan();
}

void heap(int canarray[], int n, int i) {
    int temp;
    int cankecil = i; 
    int kiri = 2 * i + 1;
    int kanan = 2 * i + 2;

    if (kiri < n && canarray[kiri] < canarray[cankecil])
        cankecil = kiri;
    if (kanan < n && canarray[kanan] < canarray[cankecil])
        cankecil = kanan;

    if (cankecil != i) {
        temp = canarray[i];
        canarray[i] = canarray[cankecil];
        canarray[cankecil] = temp;
        heap(canarray, n, cankecil);
    }
}

void sortheap(int canarray[], int n) {
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(canarray, n, i);
    for (int i = n - 1; i >= 0; i--) {
        temp = canarray[0];
        canarray[0] = canarray[i];
        canarray[i] = temp;
        heap(canarray, i, 0);
    }
}

void heaps() {
    int canarray[] = {50000, 75000, 80000, 120000, 150000, 200000, 350000, 650000, 800000, 5000000};
    int n = 10;
    int i;

    cout << "Menampilkan Data Sebelum Diurutkan" << endl;
    cout << "----------------------------------" << endl;
    for (i = 0; i < n; i++)
        cout << canarray[i] << " ";
    cout << endl;

    sortheap(canarray, n);

    cout << endl;
    cout << "Menampilkan Data Setelah Diurutkan - HEAP SORT" << endl;
    cout << "----------------------------------------------" << endl;
    for (i = 0; i < n; i++)
        cout << canarray[i] << " ";
    cout << endl;
	menupilihan();
}

int search01_a(string data[], int jumlahElemen, string elemen_a) {
    int flaq_a = -1;
    for (int count_a = 0; count_a < jumlahElemen; count_a++) {
        if (elemen_a == data[count_a]) {
            flaq_a = count_a;
            break;
        }
    }
    return flaq_a;
}

int search01(string data[], int jumlahElemen, string elemen) {
    int flaq = -1;
    for (int count = 0; count < jumlahElemen; count++) {
        if (elemen == data[count]) {
            flaq = count;
            break;
        }
    }
    return flaq;
}

void sequintal() {
    string data[10] = {"P001", "P002", "P003", "P004", "P005", "P006", "P007", "P008", "P009", "P010"};
    int jumlahElemen = 10;

    cout << "=============================================" << endl;
    cout << "|| Silahkan Cari Barang yang anda inginkan ||" << endl;
    cout << "=============================================" << endl;
    cout << "Isi Kode Barang nya adalah " << endl;
    cout << "---------------------------" << endl;
    cout << endl;

    for (int count = 0; count < jumlahElemen; count++) {
        cout << " " << " Posisi Barang[" << count + 1 << "] --> " << data[count] << endl;
    }

    string searchelemen;
    cout << "----------------------------------" << endl;
    cout << endl;
    cout << "Masukkan Barang yang akan anda cari? ";
    cin >> searchelemen;

    int flaq = search01(data, jumlahElemen, searchelemen);
    if (flaq != -1) {
        string itemName = getItemName(searchelemen);
        cout << "Kode Barang yang anda cari adalah = " << itemName << endl;
        cout << "Ditemukan pada posisi: Laci Barang[" << flaq + 1 << "]" << endl;
    } else {
        cout << "Barang tidak ditemukan." << endl;
    }
    menupilihan();
}

string getItemName(string searchelemen) {
    if (searchelemen == "P001") return "Handphone";
    if (searchelemen == "P002") return "Laptop";
    if (searchelemen == "P003") return "Komputer";
    if (searchelemen == "P004") return "Jam Tangan";
    if (searchelemen == "P005") return "Kamera";
	if (searchelemen == "P006") return "Tablet";
	if (searchelemen == "P007") return "Speaker";
	if (searchelemen == "P008") return "Headset";
	if (searchelemen == "P009") return "Printer";
	if (searchelemen == "P010") return "Mouse";
}

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

void cetaktree1(){
	TREE T;
    BuatTree('R', &T);
    TambahKiri('S', T.root);
    TambahKanan('U', T.root);
    TambahKiri('V', T.root->left);
    TambahKanan('W', T.root->left);
    TambahKiri('Y', T.root->right);
    TambahKanan('Z', T.root->right);
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
    cout << "PostOrder Setelah Dihapus" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	CetakTreePostOrder(T.root);
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	menupilihan();
}

void Pemilihan(){
	cout << "Nama Pembeli    : "; cin >> Nama ;
    cout << "No Telp         : "; cin >> No_Telp ;
    cout << "Email           : "; cin >> Email ;
	cout << "Nama Barang     : "; cin >> Nama_Barang ;
    cout << "Jumlah Barang   : "; cin >> Jumlah_Barang ;
    cout << "Kode Barang     : "; cin >> Kode_Barang ;
	cout << "Harga Barang    : "; cin >> Harga_Barang ;
	menupilihan();
}

void bayar(){
	double Total_Harga;
	Total_Harga = Jumlah_Barang * Harga_Barang;
	cout << "Nama Pembeli    : " << Nama <<endl;
	cout << "No Telp         : " << No_Telp << endl;
    cout << "Email           : " << Email << endl;
	cout << "Nama Barang     : " << Nama_Barang << endl;
    cout << "Jumlah Barang   : " << Jumlah_Barang << endl ;
    cout << "Kode Barang     : " << Kode_Barang << endl ;
	cout << "Harga Barang    : " << Harga_Barang << endl ;
	cout << "Total_Harga     : " << Total_Harga << endl;
	menupilihan();
}
	
void menupilihan(){
	int cn;
	cout<<endl;
    cout << "=====================================" << endl;
    cout << "==   SILAHKAN PILIH MENU BERIKUT   ==" << endl;
    cout << "=====================================" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1. List Barang Menggunakan Linked List "<< endl;
	cout << "2. Urutan Harga Barang Elektronik (Heap Sort - Descending)" << endl;
    cout << "3. Mencari Barang (Sequential Search)" << endl;
	cout << "4. Pencarian Inisial Barang (Binary Tree Penelusuran PostOrder)"<< endl;
	cout << "5. Membeli Barang ditoko " <<endl;
	cout << "6. Membayar Barang Yang Beli "<<endl;
	cout << "0. Keluar Dari Toko " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Menu Pilihan Anda: "; cin >> cn;
    cout << endl;
    switch (cn) {
        case 1:
        cetakstack1();
            break;
        case 2:
        heaps();
            break;
        case 3:
		sequintal();
            break;
		case 4 : 
		cetaktree1();
			break;
		case 5:
		Pemilihan();
			break;
		case 6 :
		bayar();
			break;
		case 0 :
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "|| Terima Kasih telah berbelanja Toko Elektonik Deriansyah ||" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
        default:
            cout << "Pilihan anda tidak valid" << endl;
            break;
		}
}
	
int main() {
	cout << "===========================================================" << endl;
    cout << "|     Tugas Besar Praktikum Algoritma dan Pemrograman     |" << endl;
    cout << "===========================================================" << endl;
    cout << "|                    Agil Deriansyah Hasan                |" << endl;
    cout << "|                        4522210125                       |" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
	cout << "==============================================================================" << endl;
	cout << "|                Selamat Datang Di Toko Elektonik Deriansyah                 |" << endl;
	cout << "|                  Jln.Bintara14, No 25 Telp 087833160661                    |" << endl;
	cout << "|        Jl. Kp.Bojong, Kec. Bekasi Bar., Kota Bekasi, Jawa Barat, 17134     |" << endl;
	cout << "==============================================================================	" << endl;
	cout<<endl;
	menupilihan();
}
