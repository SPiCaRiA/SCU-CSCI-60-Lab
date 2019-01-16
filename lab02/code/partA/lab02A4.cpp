#include <iostream>

using namespace std;


class ModInt
{
    private:
        int mod = 0;;
        int val = 0;

    public:
        ModInt()
        {
        }

        ModInt(int mod, int val)
        {
            this->mod = mod;
            this->val = val;
        }

        int getVal() const
        {
            return this->val;
        }

        int getMod() const
        {
            return this->mod;
        }

        ModInt &operator=(const int val)
        {
            this->val = val;

            return *this;
        }

        void operator+=(ModInt rhs)
        {
            if (rhs.getMod() != this->getMod()) {
                this->mod = -1;
                this->val = -1;
                return;
            }

            this->val = (this->getVal() + rhs.getVal()) % this->getMod();
        }

        string toString()
        {
            return  to_string(this->getVal()) + ", " + to_string(this->getMod());
        }
};

ModInt operator+(const ModInt &lhs, const ModInt &rhs)
{
    if (lhs.getMod() != rhs.getMod()) {
        return ModInt(-1, -1);
    }

    return ModInt(lhs.getMod(), (lhs.getVal() + rhs.getVal()) % lhs.getMod());
}

ModInt operator*(const ModInt &lhs, const ModInt &rhs)
{
    if (lhs.getMod() != rhs.getMod()) {
        return ModInt(-1, -1);
    }
    return ModInt(lhs.getMod(), (lhs.getVal() * rhs.getVal()) % lhs.getMod());
}

int main()
{
    ModInt a(3, 1);
    ModInt b(3, 2);
    ModInt c(4, 1);

    cout << "a + b: " << (a + b).toString() << endl;
    cout << "a * b: " << (a * b).toString() << endl;

    cout << "a + c: " << (a + c).toString() << endl;
    cout << "a * c: " << (a * c).toString() << endl;
}

