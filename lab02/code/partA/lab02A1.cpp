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

        string toString()
        {
            return  to_string(this->getVal()) + ", " + to_string(this->getMod());
        }

};

int main()
{
    ModInt a = ModInt();
    ModInt b = ModInt(5, 2);

    cout << "a: " << a.toString() << endl
         << "b: " << b.toString() << endl;

    a = 10;
    cout << "a = 10: " << a.toString() << endl;

    return 0;
}

