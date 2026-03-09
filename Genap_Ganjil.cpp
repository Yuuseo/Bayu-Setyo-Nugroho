#include <iostream>
using namespace std;

int main() {
    int data;
    cout << "Masukkan angka: ";
    cin >> data;

    if (data % 2 == 0) cout << "Bilangan Genap" << endl;
    else cout << "Bilangan Ganjil" << endl;

    return 0;
}