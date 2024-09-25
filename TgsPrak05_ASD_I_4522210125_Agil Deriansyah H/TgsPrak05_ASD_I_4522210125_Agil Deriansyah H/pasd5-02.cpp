#include <iostream>
#include <string>
using namespace std;

struct NilaiMK {
    string npm;
    string nama_mhs;
    double nilai;
};

class Queue {
private:
    struct Elemen {
        NilaiMK kontainer;
        Elemen* next;
    };

    Elemen* first;
    Elemen* last;

public:
    Queue() : first(NULL), last(NULL) {}

    bool isKosong() {
        return first == NULL;
    }

    int jmlelemen() {
        int hasil = 0;
        if (first != NULL) {
            Elemen* bantu = first;
            while (bantu != NULL) {
                hasil = hasil + 1;
                bantu = bantu->next;
            }
        }
        return hasil;
    }

    void add(string npm, string nama_mhs, double nilai) {
        Elemen* info = new Elemen;
        info->kontainer.npm = npm;
        info->kontainer.nama_mhs = nama_mhs;
        info->kontainer.nilai = nilai;
        info->next = NULL;

        if (first == NULL) {
            first = info;
        } else {
            last->next = info;
        }
        last = info;
    }

    void del() {
        if (first != NULL) {
            Elemen* hapus = first;

            if (jmlelemen() == 1) {
                first = NULL;
                last = NULL;
            } else {
                first = first->next;
                hapus->next = NULL;
            }
            delete hapus;
        }
    }

    void cetakQueue() {
        if (first != NULL) {
            cout << "Menampilkan Queue" << endl;
            Elemen* bantu = first;
            int i = 1;
            while (bantu != NULL) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "Elemen Ke :" << i << endl;
                cout << "Nomor Pokok Mahasiswa :" << bantu->kontainer.npm << endl;
                cout << "Nama Mahasiswa :" << bantu->kontainer.nama_mhs << endl;
                cout << "Nilai Mahasiswa :" << bantu->kontainer.nilai << endl;
                bantu = bantu->next;
                i = i + 1;
            }
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        } else {
            cout << "Queue Kosong" << endl;
        }
    }
};

int main() {
    Queue Q;
    cout << "Memulai dengan Queue Kosong" << endl;
    Q.cetakQueue();
    cout << endl;
    cout << "===========================" << endl;

    Q.add("4523210666", "Budi", 88.75);
    Q.add("4523210777", "Susi", 78.85);
    Q.add("4523210888", "Nuri", 98.65);
    Q.add("4523210999", "Bimo", 68.55);
    Q.add("4523210555", "Arif", 78.85);
    Q.add("4523210444", "Rido", 98.65);
    Q.add("4523210222", "Ella", 68.55);

    cout << "Menambahkan elemen ke dalam Queue" << endl;
    Q.cetakQueue();
    cout << "===========================" << endl;
    cout << endl;

    Q.del();
    cout << "Menghapus satu elemen dari Queue" << endl;
    Q.cetakQueue();
    cout << "===========================" << endl;
    cout << endl;

    Q.del();
    cout << "Menghapus satu elemen dari Queue lagi" << endl;
    Q.cetakQueue();
    cout << "===========================" << endl;

    return 0;
}
