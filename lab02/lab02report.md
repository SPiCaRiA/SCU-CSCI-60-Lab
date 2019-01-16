# Lab 02 Report

## Part A

### 1.

[lab02A1.cpp](code/partA/lab02A1.cpp):

```cpp
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
```

### 2.

[lab02A2.cpp](code/partA/lab02A2.cpp):

```cpp
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
```


### 3.

[lab02A3.cpp](code/partA/lab02A3.cpp):

```cpp
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
```


### 4.

[lab02A4.cpp](code/partA/lab02A4.cpp):

```cpp
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
```


