#include <iostream>
using namespace std;

void cekHuruf(char huruf) {
    if(huruf=='a'||huruf=='i'||huruf=='u'||huruf=='e'||
        huruf=='o'||huruf=='A'||huruf=='I'||huruf=='U'||
        huruf=='E'||huruf=='O')
        cout << "Huruf Vokal" << endl;
    else
        cout << "Huruf Konsonan" << endl;
}

int main() {
    char h;
    cout << "Masukkan huruf: ";
    cin >> h;
    cekHuruf(h);
    return 0;
}