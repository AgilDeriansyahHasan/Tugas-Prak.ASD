#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100

struct biodata {
    char nama[20];
    int usia;
};

class Queue {
private:
    biodata queue[MAX];
    int awal, akhir;

public:
    Queue() {
        init();
    }

    void init() {
        awal = -1;
        akhir = -1;
    }

    bool full() {
        return akhir == MAX - 1;
    }

    bool empty() {
        return akhir == -1;
    }

    void enqueue(biodata mhs) {
        if (empty()) {
            awal = 0;
            akhir = 0;
            queue[awal] = mhs;
        } else if (!full()) {
            akhir++;
            queue[akhir] = mhs;
        } else {
            cout << "Queue sudah penuh...\n";
        }
    }

    biodata dequeue() {
        int i;
        biodata mhs;
        if (!empty()) {
            mhs = queue[awal];
            for (i = awal; i < akhir; i++)
                queue[i] = queue[i + 1];
            akhir--;
            return mhs;
        } else {
            cout << "Queue Kosong...\n";
            return mhs; // Return mhs kosong jika queue kosong
        }
    }

    void display() {
        int i;
        cout << "\nIsi Queue :\n";
        if (!empty()) {
            for (i = awal; i <= akhir; i++) {
                cout << "Nama: " << queue[i].nama << ", Usia: " << queue[i].usia << "\n";
            }
        } else {
            cout << "Data Kosong.\n";
        }
        cout << "\n";
    }

    biodata entridata() {
        biodata mhs;
        cout << "\n";
        cout << "Masukkan Nama :";
        cin >> mhs.nama;
        cout << "Masukkan Usia :";
        cin >> mhs.usia;
        return mhs;
    }
};

int main() {
    char pilih;
    Queue q;
    biodata mhs;
    cout << "== Program Entri Data Mahasiswa ==\n";
    do {
        cout << "Menu Pilihan :\n";
        cout << "1. Input Data \n";
        cout << "2. Hapus Data \n";
        cout << "3. Lihat Daftar Mahasiswa \n";
        cout << "4. Hapus Semua Data \n";
        cout << "5. Selesai \n";
        cout << "Pilih 1 s.d 5 :";
        cin >> pilih;
        switch (pilih) {
            case '1':
                mhs = q.entridata();
                q.enqueue(mhs);
                break;
            case '2':
                cout << "\nData Yang DiHapus :\n";
                mhs = q.dequeue();
                q.display();
                break;
            case '3':
                q.display();
                break;
            case '4':
                q.init();
                cout << "\nData Telah Dikosongkan\n";
                break;
            case '5':
                break;
            default:
                cout << "Pilih 1 s.d 5 !";
                break;
        }
        cout << "\n";
    } while (pilih != '5');
    return 0;
}
