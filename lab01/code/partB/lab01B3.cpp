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

