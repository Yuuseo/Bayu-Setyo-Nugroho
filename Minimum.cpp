#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int data[n];
    for(int i=0; i<n; i++){
        cin >> data[i];
    }
       
    int min = data[0];
    for(int i=1; i<n; i++) {
        if(data[i] < min)
            min = data[i];
    }

    cout << "Nilai minimum: " << min << endl;
    return 0;
}