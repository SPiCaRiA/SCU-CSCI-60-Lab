#include "dbiguint.h"
#include <iostream>

using namespace std;


int main()
{
    dbiguint i0 = dbiguint();
    dbiguint i1124 = dbiguint("1124");
    dbiguint i1111 = dbiguint("1111");
    string s= "";

    cout << "0: " << i0 << endl << "1124: " << i1124 << endl;
    cout << "Second digit in 1124: " << i1124[2] << endl;
    cout << "Size of 1124: " << i1124.size() << endl;

    i0.reserve(4);
    cout << "Size of 0000: " << i0.size() << endl;

    i1111 += i1124;
    cout << "1111 + 1124: " << i1111 << endl;

    return 0;
}
