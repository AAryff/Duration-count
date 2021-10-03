#include <iostream>
#include <string>
using namespace std;

class period {
    public:
        int hour;
        int get_hour();
        int minute;
        int get_minute();
        string halve;
        string get_halve();
        int total_minutes;
};

void display_time(int hours, int minutes, string halve){
    if (minutes < 10){
        cout << hours << ":" << "0" << minutes << " " << halve << endl;
    } else {
        cout << hours << ":" << minutes << " " << halve << endl;
    }
}

int count_minutes(int hours, int minutes, string halve){
    int total;
    if (halve == "PM" && hours != 12){
        total = 12 * 60 + hours * 60 + minutes;
    } else if (hours == 12 && halve =="AM"){ //12:00 AM means total minutes is 0 instead of 720 
        total = minutes;
    } else {
        total = hours * 60 + minutes;
    }
    return total;
}

int period::get_hour(){
    do {
    cout << "Hour (1 - 12): ";
    cin >> hour;

        if (hour > 12 || hour < 1){
            cout << "Invalid value";
        }

    } while (hour > 12 || hour < 1);
    return hour;
}

int period::get_minute(){
    do {
    cout << "Minute (1 - 59): ";
        cin >> minute;

            if (minute > 59 || minute < 0){
                cout << "Invalid value";
            }

    } while (minute > 59 || minute < 0);
    return minute;
}

string period::get_halve(){

    do {

        cout << "Halve (AM or PM): ";
        cin >> halve;

    } while (halve != "PM" && halve != "AM");
    return halve;
}

int main(){
    period starting; 
    period ending;

    starting.hour = starting.get_hour();
    starting.minute = starting.get_minute();
    starting.halve = starting.get_halve();
    cout << "Start: "; display_time(starting.hour, starting.minute, starting.halve);
    starting.total_minutes = count_minutes(starting.hour, starting.minute, starting.halve);
    
    ending.hour = 7;
    ending.minute = 30;
    ending.halve = "PM";
    cout << "End: "; display_time(ending.hour, ending.minute, ending.halve);
    ending.total_minutes = count_minutes(ending.hour, ending.minute, ending.halve);

    int duration = ending.total_minutes - starting.total_minutes;
    cout << "Duration: " << duration << " minutes";
}