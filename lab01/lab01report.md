# Lab 01 Report
## Part B
### 1.

[lab01B1.cpp](code/partB/lab01B1.cpp):

```cpp
struct Time{//military time, no am/pm
    int hour;
    int minute;
};

struct Carpool {
    string name[5];
    int num = 0;
    Time arrival;
};
```


### 2.

[lab01B2.cpp](code/partB/lab01B2.cpp):

```cpp
#include <iostream>

using namespace std;

struct Time{//military time, no am/pm
    int hour;
    int minute;
};

struct Carpool {
    string name[5];
    int num = 0;
    Time arrival;
};

Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else {
        ret = t2;
    }
    return ret;
}

Carpool combineCarpool(Carpool car1, Carpool car2) {
    Carpool newCarpool;
    if (car1.num + car2.num <= 5) {
        newCarpool.num = car1.num + car2.num;
        int count = 0;
        for (; count < car1.num; count++) {
            newCarpool.name[count] = car1.name[count];
	}
	for (; count < car1.num + car2.num; count++) {
            newCarpool.name[count] = car2.name[count-car1.num];
	}
	Time newTime = earlier(car1.arrival, car2.arrival);
	newCarpool.arrival = newTime;
    } else {
	newCarpool.num = 0;
	newCarpool.arrival.hour = 0;
	newCarpool.arrival.minute = 0;
    }

    return newCarpool;
}

int main() {
    Carpool car1, car2;
    int num1, num2, hour, minute;
    string s;
    Time arrival;

    cout << "Please enter the number of people in car1 and car2\n";
    cin >> num1 >> num2;
    car1.num = num1;
    car2.num = num2;
    cout << "Please enter the name for car1\n";
    for (int i = 0; i < num1; i++) {
        cin >> s;
	car1.name[i] = s;
    }
    cout << "Please enter the arriving hour and minute\n";
    cin >> hour >> minute;
    arrival.hour = hour;
    arrival.minute = minute;
    car1.arrival = arrival;


    cout << "Please enter the name for car2\n";
    for (int i = 0; i < num2; i++) {
        cin >> s;
	car2.name[i] = s;
    }
    cout << "Please enter the arriving hour and minute\n";
    cin >> hour >> minute;
    arrival.hour = hour;
    arrival.minute = minute;
    car2.arrival = arrival;

    Carpool newCarpool = combineCarpool(car1, car2);
    cout << "Number of people: " << newCarpool.num;
    cout << "\nNames: ";
    for (int i = 0; i < newCarpool.num; i++) cout << newCarpool.name[i] << " ";
    cout << "\nArriving time: " << newCarpool.arrival.hour << ":" << newCarpool.arrival.minute;
}
```


### 3.

[lab01B3.cpp](code/partB/lab01B3.cpp):

```cpp
#include <iostream>

using namespace std;


struct Time { //military time, no am/pm
    int hour;
    int minute;
};

Time earlier(Time t1, Time t2) {
    Time ret;
    if (t1.hour == t2.hour) {
        if (t1.minute < t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour < t2.hour) {
        ret = t1;
    }
    else {
        ret = t2;
    }
    return ret;
}

class Carpool
{
    private:
        int num_of_people = 0;
        string names[5];
        Time arrive_time;

    public:
        Carpool()
        {
        }

        Carpool(string *names, Time arrive_time, int num_of_people)
        {
            for (int i = 0; i < num_of_people; i++) {
                this->names[i] = names[i];
            }

            this->arrive_time = arrive_time;
            this->num_of_people = num_of_people;
        }

        Carpool combineCarpool(Carpool car1, Carpool car2)
        {
            Carpool return_val = Carpool();

            if (car1.num_of_people + car2.num_of_people > 5)
                return return_val;

            return_val.add_names(car1.names, car1.num_of_people);
            return_val.add_names(car2.names, car2.num_of_people);
            return_val.arrive_time = earlier(car1.arrive_time, car2.arrive_time);

            return return_val;
        }

        void add_name(string name)
        {
            if (num_of_people < 5) {
                this->names[num_of_people++] = name;
            }
        }

        void add_names(string *new_names, int size)
        {
            for (int i = 0; i < size; i++) {
                this->add_name(new_names[i]);
            }
        }

        void print()
        {
            for (int i = 0; i < num_of_people; i++) {
                cout << names[i] << endl;
            }
            cout << endl;
        }
};

int main()
{
    string n1[2] = { "a", "b" };
    string n2[3] = { "a", "b", "c" };
    Time t1;
    Time t2;
    t1.hour = 1;
    t1.minute = 50;
    t2.hour = 2;
    t2.minute = 50;

    Carpool car1 = Carpool(n1, t1, 2);
    Carpool car2 = Carpool(n2, t2, 3);

    car1.print();
    car2.print();
    car1.combineCarpool(car1, car2).print();
}
```


