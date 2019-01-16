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

        string toString()
        {
            return  to_string(this->getVal()) + ", " + to_string(this->getMod());
        }
};

bool operator==(const ModInt &lhs, const ModInt &rhs)
{
    return ((lhs.getMod() == rhs.getMod()) && (lhs.getVal() == rhs.getVal()));
}


int main()
{
    ModInt a(1, 2);
    ModInt b(1, 2);

    cout << "a == b: " << (a == b) << endl;;
}

