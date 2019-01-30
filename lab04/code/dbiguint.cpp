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
