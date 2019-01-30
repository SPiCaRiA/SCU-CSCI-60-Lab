# Lab 04 Report

## Code

[main.cpp](code/main.cpp):

```cpp
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
```


[dbiguint.h](code/dbiguint.h):

```cpp
#ifndef DBIGUINT_H
#define DBIGUINT_H

#include <cstdlib>
#include <string>

class dbiguint
{
public:
    // pre: none
    // post: creates a dynamic bigint value 0
    dbiguint();

    // pre: s[0], ..., s[s.size()-1] are digits
    // post: creates a dbiguint whose digits are given in s
    dbiguint(const std::string & s);
/*We aren't implementing this constructor yet
    // pre:  none    //NEW
    // post: copy constructor: creates a new dynamic bigint which is
    //                         a copy of given dynamic bigint
    dbiguint(const dbiguint &);
*/

    dbiguint(unsigned short *data, int size);

    // pre: none    //NEW
    // post: returns dynamically allocated memory to heap
    ~dbiguint();

    // pre: none    //NEW
    // post: makes this dynamic bigint a copy of given dynamic bigint
    void operator =(const dbiguint &);

    // pre: none    //NEW
    // post: returns the size of the memory block of this dbiguint
    std::size_t size() const;

    // pre: none
    // post: returns the digit at given pos (0 if does not exist)
    //       pos 0 is the least significant (units) digit
    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 0 if this dbiguint equals given dbiguint
    //               1 if this dbiguint >      given dbiguint
    //              -1 otherwise
    int compare(const dbiguint &) const;

    // pre: none
    // post: returns a string containing the digits and sign of this dbiguint
    std::string toStdString() const;

    // pre: none
    // post: adds/subtracts given dbiguint to this dbiguint
    void operator +=(const dbiguint &);
    void operator -=(const dbiguint &);
    void operator *=(const dbiguint &);

    // pre: none
    // post: if newcapacity_ <= capacity_ then do nothing (cannot shrink)
    //       else allocate a new block with size newcapacity_
    //       copy existing digits and fill the rest with 0
    void reserve(std::size_t newcapacity_);

private:
    unsigned short *data_;
    std::size_t capacity_;

    // INVARIANTS:
    //    data_ points to (has the address of) a dynamic array
    //    of capacity_ digits
    //    data_[0] = least significant (units) digits
    //    data_[k] = digit at position k (or 0 if not used)


};


// nonmember functions

dbiguint operator +(const dbiguint &, const dbiguint &);
dbiguint operator -(const dbiguint &, const dbiguint &);
dbiguint operator *(const dbiguint &, const dbiguint &);

bool operator < (const dbiguint &, const dbiguint &);
bool operator <= (const dbiguint &, const dbiguint &);
bool operator == (const dbiguint &, const dbiguint &);
bool operator != (const dbiguint &, const dbiguint &);
bool operator >= (const dbiguint &, const dbiguint &);
bool operator > (const dbiguint &, const dbiguint &);

std::ostream & operator << (std::ostream &, const dbiguint &);
std::istream & operator >> (std::istream &, dbiguint &);





#endif // DBIGUINT_H
```


[dbiguint.cpp](code/dbiguint.cpp):
```cpp
#include "dbiguint.h"
#include <cstdlib>
#include <iostream>

using namespace std;


dbiguint::dbiguint()
{
    this->capacity_ = 1;
    this->data_ = (unsigned short *) malloc(1 * sizeof(unsigned short));
    this->data_[0] = 0;
}

dbiguint::dbiguint(const string &num_str)
{
    this->capacity_ = num_str.size();
    this->data_ = (unsigned short *) malloc(this->capacity_ * sizeof(unsigned short));

    for (std::size_t i = 0; i < this->capacity_; i++) {
        this->data_[i] = 0;
    }

    for (int i = num_str.size() - 1; i >= 0; i--) {
        this->data_[i] = (unsigned short) std::stoi(std::string(1, num_str[num_str.size() - 1 - i]));
            }
}

dbiguint::dbiguint(unsigned short *data, int size)
{
    this->capacity_ = size;
    this->data_ = (unsigned short *) malloc(this->capacity_ * sizeof(unsigned short));

    for (int i = 0; i < size; i++) {
        this->data_[i] = data[i];
    }
}

dbiguint::~dbiguint()
{
    free(this->data_);
    this->capacity_ = 0;
}

void dbiguint::operator =(const dbiguint &rhs)
{
    this->capacity_ = rhs.size();
    this->data_ = (unsigned short *) malloc(this->capacity_ * sizeof(unsigned short));

    for (int i = 0; i < (int) this->capacity_; i++) {
        this->data_[i] = rhs.data_[i];
    }
}

size_t dbiguint::size() const
{
    return this->capacity_;
}

unsigned short dbiguint::operator [](size_t pos) const
{
    return this->data_[pos];
}

int dbiguint::compare(const dbiguint &rhs) const
{
    return this->toStdString().compare(rhs.toStdString());
}

string dbiguint::toStdString() const
{
    bool start = false;
    string result = "";

    for (int i = (int) this->capacity_ - 1; i >= 0; i--) {
        if (this->data_[i] == 0 && !start) {
            if (this->capacity_ == 1)
                result += to_string(this->data_[i]);
            continue;
        }

        else {
            start = true;
            result += to_string(this->data_[i]);
        }
    }

    return result;
}

void dbiguint::operator +=(const dbiguint &rhs)
{
    const dbiguint & cpy = dbiguint(this->data_, this->capacity_);
    dbiguint result = rhs + cpy;

    for (int i = this->capacity_ - 1; i >= 0; i--) {
        this->data_[i] = result[i];
    }
}

void dbiguint::reserve(size_t newcapacity_)
{
    if (newcapacity_ > this->capacity_) {
        unsigned short *new_data_ = (unsigned short *) malloc(newcapacity_ * sizeof(unsigned short));

        for (int i = 0; i < (int) newcapacity_; i++) {
            new_data_[i] = 0;
        }

        for (int i = 0; i < (int) this->capacity_; i++) {
            new_data_[i] = this->data_[i];
        }

        free(this->data_);
        this->data_ = new_data_;
        this->capacity_ = newcapacity_;
    }
}

dbiguint operator +(const dbiguint &lhs, const dbiguint &rhs)
{
    std::string result = "";
    std::string reverse_result = "";
    int temp;
    bool add_one = false;

    if (lhs.size() != rhs.size()) {
        return dbiguint("0");
    }

    for (int i = 0; i < (int) lhs.size(); i++) {
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

    return dbiguint(reverse_result);
}

ostream & operator << (ostream &out, const dbiguint &data)
{
    out << data.toStdString();
    return out;
}
```
