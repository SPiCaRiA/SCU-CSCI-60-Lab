#include <iostream>

using namespace std;


class ModInt
{
    private:
        int mod = 1;;
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

int main()
{
    ModInt a(3, 1);
    ModInt b(3, 1);
    ModInt c(4, 1);

    a += b;
    cout << "a += b: " << a.toString() << endl;

    a += c;
    cout << "a += c: " << a.toString() << endl;
}

