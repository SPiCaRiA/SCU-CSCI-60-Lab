# Lab 03 Report

[biguint.h](code/partA/biguint.h):

```c++
#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this Biguint >, ==, < than given Biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>

class Biguint;
Biguint operator + (const Biguint &lhs, const Biguint &rhs);

class Biguint
{
    public:
        // CONSTANTS & TYPES

        static const std::size_t CAPACITY = 20;

        // CONSTRUCTORS

        // pre: none
        // post: creates a Biguint with value 0
        Biguint()
        {
            for (std::size_t i = 0; i < this->CAPACITY; i++) {
                this->data_[i] = 0;
            }
        }

        // pre: s contains only decimal digits
        // post: creates a Biguint whose value corresponds to given string of digits
        Biguint(std::string num_str)
        {
            for (std::size_t i = 0; i < this->CAPACITY; i++) {
                this->data_[i] = 0;
            }

            for (int i = num_str.size() - 1; i >= 0; i--) {
                this->data_[i] = (unsigned short) std::stoi(std::string(1, num_str[num_str.size() - 1 - i]));
            }
        }

        Biguint(unsigned short *data, int size)
        {
            for (int i = 0; i < size; i++) {
                this->data_[i] = data[i];
            }
        }

        // CONSTANT MEMBER FUNCTIONS

        // pre: pos < CAPACITY
        // post: returns the digit at position pos
        //          0 is the least significant (units) position

        unsigned short operator [](std::size_t pos) const
        {
            return this->data_[pos];
        }

        // pre: none
        // post: returns 1 if this Biguint > b
        //               0 if this Biguint == b
        //              -1 if this Biguint < b
        int compare(const Biguint & b) const;



        // MODIFICATION MEMBER FUNCTIONS


        // pre: none
        // post: b is added to this Biguint; ignore last carry bit if any
        void operator += (const Biguint & b)
        {
            const Biguint & cpy = Biguint(this->data_, (int) this->CAPACITY);
            Biguint result = b + cpy;
            for (std::size_t i = this->CAPACITY; i >= 0; i--) {
                this->data_[i] = result[i];
            }
        }

        void operator -= (const Biguint & b);

    private:

        unsigned short data_[CAPACITY];

        // INVARIANTS:
        //    data_[i] holds the i^th digit of this Biguint or 0 if not used
        //    data_[0] holds the least significant (units) digit
};

// nonmember functions
std::ostream &operator <<(std::ostream &out, const Biguint &data)
{
    bool start = false;

    for (int i = (int) data.CAPACITY - 1; i >= 0; i--) {
        if (data[i] == 0 && !start) {
            continue;
        }
        else {
            start = true;
            out << data[i];
        }
    }

    return out;
}

Biguint operator + (const Biguint &lhs, const Biguint &rhs)
{
    std::string result;
    std::string reverse_result;
    int temp;
    bool add_one = false;

    if (lhs.CAPACITY != rhs.CAPACITY) {
        return result;
    }

    for (int i = 0; i < (int) lhs.CAPACITY; i++) {
        temp = lhs[i] + rhs[i];

        if (add_one) {
            temp++;
            add_one = false;
        }

        if (temp < 10) {
            result += std::to_string(temp);
        }
        else {
            result += std::to_string(temp - 10);
            add_one = true;
        }
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        reverse_result += result[i];
    }

    return Biguint(reverse_result);
}

Biguint operator - (const Biguint &, const Biguint &);

bool operator < (const Biguint &, const Biguint &);
bool operator <= (const Biguint &, const Biguint &);
bool operator != (const Biguint &, const Biguint &);
bool operator == (const Biguint &, const Biguint &);
bool operator >= (const Biguint &, const Biguint &);
bool operator > (const Biguint &, const Biguint &);




#endif // BIGUINT_H

```

[lab03.cpp](code/partA/lab03A1.cpp):

```c++
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
```
