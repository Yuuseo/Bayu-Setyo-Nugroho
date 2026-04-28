#include <iostream>
#include <string>

using namespace std;

#define MAKS 100 

class QueueAkademik {
private:
    string antrian[MAKS];
    int front, rear;

public:

    QueueAkademik() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAKS - 1);
    }

    void enqueue(string nama) {
        if (isFull()) {
            cout << "Antrian Penuh!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        antrian[rear] = nama;
        cout << "[Enqueue] Mahasiswa " << nama << " mengambil nomor antrian.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "[Dequeue] Antrian Kosong! Tidak ada yang bisa dilayani.\n";
            return;
        }
        cout << "[Dequeue] Memanggil dan melayani mahasiswa: " << antrian[front] << "\n";

        if (front == rear) { 
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void tampilkanAntrian() {
        if (isEmpty()) {
            cout << "[Info] Kondisi antrian saat ini: KOSONG\n";
            return;
        }
        cout << "[Info] Kondisi antrian saat ini: ";
        for (int i = front; i <= rear; i++) {
            cout << antrian[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    QueueAkademik q;

    cout << "--- Mulai Simulasi ---\n";
    q.enqueue("A");
    q.enqueue("B");
    q.enqueue("C");
    
    q.dequeue(); 
    
    q.enqueue("D"); 
    
    q.tampilkanAntrian(); 

    return 0;
}