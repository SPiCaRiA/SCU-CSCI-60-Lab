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
