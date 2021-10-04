#include <iostream>
#include <string>
#include <cmath>
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

//function to display the time based on data given by the user
void display_time(int hours, int minutes, string halve){
    if (minutes < 10){
        cout << hours << ":" << "0" << minutes << " " << halve << endl;
    } else {
        cout << hours << ":" << minutes << " " << halve << endl;
    }
}


//function to count total minutes in a time
int count_minutes(int hours, int minutes, string halve){
    int total;
    if (halve == "PM" && hours != 12){
        total = 12 * 60 + hours * 60 + minutes;
    } else if (hours == 12 && halve =="AM"){ //12:00 AM means total minutes is 0 instead of 720 
        total = minutes;
    } else{
        total = hours * 60 + minutes;
    }
    return total;
}

//function to get hour data from the user
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

//function to receive minute data from user
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

//function to receive halve data from the user
string period::get_halve(){

    do {

        cout << "Halve (AM or PM): ";
        cin >> halve;

    } while (halve != "PM" && halve != "AM");
    return halve;
}

//display the duration in (1-12) Hours and (1-59) minutes format
void display_duration_time(int duration_total_minutes){
    int duration_hour = duration_total_minutes/60;
    double duration_minute = remainder(duration_total_minutes, 60);
    cout << "Duration: " << duration_hour << " Hours " << duration_minute << " Minutes" << endl;
}

int main(){
    period starting; 
    period ending;

    do{
        cout << "Enter Start time: ";
        starting.hour = starting.get_hour();
        starting.minute = starting.get_minute();
        starting.halve = starting.get_halve();
        cout << "Start: "; display_time(starting.hour, starting.minute, starting.halve); //display start time given by the user
        starting.total_minutes = count_minutes(starting.hour, starting.minute, starting.halve);

        cout << "Enter End time: ";
        ending.hour = ending.get_hour();
        ending.minute = ending.get_minute();
        ending.halve = ending.get_halve();
        cout << "End: "; display_time(ending.hour, ending.minute, ending.halve); //display end time given by the user
        ending.total_minutes = count_minutes(ending.hour, ending.minute, ending.halve);

        if (starting.total_minutes > ending.total_minutes){
            cout << "Starting time is bigger than end time, choose a new time" << endl;
        } else {
            int duration_total_minutes = ending.total_minutes - starting.total_minutes;
            display_duration_time(duration_total_minutes);
        }
        
    } while (starting.total_minutes > ending.total_minutes);
}
