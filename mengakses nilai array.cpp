#include <iostream>
using namespace std;

int main()
{
    int matriks[3][4] = {
        {255, 255, 250, 240},
        {150, 200, 255, 255},
        {0, 50, 150, 200}
    };

    for(int brs = 0; brs < 3; brs++)
    {
        for(int klm = 0; klm < 4; klm++)
        {
            cout << matriks[brs][klm] << endl;
        }
    }

    return 0;
}
