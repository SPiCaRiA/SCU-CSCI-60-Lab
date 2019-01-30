#include "biguint.h"
#include <iostream>

using namespace std;


int main()
{
    Biguint defaultzero = Biguint();
    Biguint n1472 = Biguint("1472");
    Biguint n1124 = Biguint("1124");

    cout << n1472 << endl;
    cout << n1472 + n1124 << endl;

    return 0;
}
