#include <iostream>
using namespace std;

bool isPrima(int n) {
    if(n <= 1) return 0;
    for(int i = 2; i < n; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int a;
    cout << "Masukkan angka: ";
    cin >> a;

    if(isPrima(a))
        cout << "Bilangan Prima" << endl;
    else
        cout << "Bukan Bilangan Prima" << endl;

    return 0;
}