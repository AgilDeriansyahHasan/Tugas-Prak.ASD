#include <iostream>
#include <cstdlib>

using namespace std;

struct data {
    int key;
    int value;
};

struct data *array;
int capacity = 10;
int size = 0;

int hashcode(int key) {
    return key % capacity;
}

int if_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int get_prime(int n) {
    if (n % 2 == 0) n++;
    while (!if_prime(n)) n += 2;
    return n;
}

void init_array() {
    capacity = get_prime(capacity);
    array = (struct data*)malloc(capacity * sizeof(struct data));
    for (int i = 0; i < capacity; i++) {
        array[i].key = 0;
        array[i].value = 0;
    }
}

void insert(int key) {
    int index = hashcode(key);
    if (array[index].value == 0) {
        array[index].key = key;
        array[index].value = 1;
        size++;
        cout << "Kunci " << key << " telah di-insert." << endl;
    } else if (array[index].key == key) {
        array[index].value += 1;
        cout << "Kunci " << key << " telah di-update." << endl;
    } else {
        cout << "Elemen tidak dapat di-insert." << endl;
    }
}

void remove_element(int key) {
    int index = hashcode(key);
    if (array[index].value == 0) {
        cout << "Kunci tidak ada." << endl;
    } else {
        array[index].key = 0;
        array[index].value = 0;
        size--;
        cout << "Kunci " << key << " telah dihapus." << endl;
    }
}

void display() {
    for (int i = 0; i < capacity; i++) {
        if (array[i].value == 0) {
            cout << "Array [" << i << "] tidak ada elemen." << endl;
        } else {
            cout << "Array [" << i << "] mempunyai elemen kunci " << array[i].key << " dan nilai " << array[i].value << endl;
        }
    }
}

int size_of_hashtable() {
    return size;
}

int main() {
    int choice, key;
    init_array();
    do {
        cout << "Implementasi Penggunaan Hash Table" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "           M E N U               " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " 1. Sisip item pada hash table " << endl;
        cout << " 2. Hapus item pada hash table " << endl;
        cout << " 3. Cek Ukuran pada hash table " << endl;
        cout << " 4. Menampilkan hash table " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Sisip item pada hash table" << endl;
                cout << "Masukkan kunci: ";
                cin >> key;
                insert(key);
                break;
            case 2:
                cout << "Hapus item pada hash table" << endl;
                cout << "Masukkan kunci: ";
                cin >> key;
                remove_element(key);
                break;
            case 3:
                cout << "Ukuran pada hash table: " << size_of_hashtable() << endl;
                break;
            case 4:
                display();
                break;
            default:
                cout << "Salah input." << endl;
        }
        cout << "Melanjutkan (tekan 1 apabila ya): ";
        cin >> choice;
    } while (choice == 1);

    free(array);
    return 0;
}
