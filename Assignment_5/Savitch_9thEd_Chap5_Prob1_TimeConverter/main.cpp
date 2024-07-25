#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

void getInput(int& hours, int& minutes);
void convertTime(int hours, int minutes, int& convertedHours, int& convertedMinutes, char& period);
void outputResult(int hours, int minutes, int convertedHours, int convertedMinutes, char period);
bool isValidTimeSimple(int hours, int minutes);

int main() {
    int hours, minutes;
    char again;

    cout << "Military Time Converter to Standard Time" << endl;

    cout << "Input Military Time hh:mm" << endl;
    
    do {
        getInput(hours, minutes);

        if (isValidTimeSimple(hours, minutes)) {
            int convertedHours, convertedMinutes;
            char period;
            convertTime(hours, minutes, convertedHours, convertedMinutes, period);
            outputResult(hours, minutes, convertedHours, convertedMinutes, period);
        } else {
            cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " is not a valid time" << endl;
        }

        cout << "Would you like to convert another time (y/n)" << endl;
        cin >> again;
        again = tolower(again);
    } while (again == 'y');

    return 0;
}

void getInput(int& hours, int& minutes) {
    char colon;
    cin >> hours >> colon >> minutes;
}

void convertTime(int hours, int minutes, int& convertedHours, int& convertedMinutes, char& period) {
    if (hours == 0) {
        convertedHours = 12;
        period = 'A';
    } else if (hours == 12) {
        convertedHours = 12;
        period = 'P';
    } else if (hours > 12) {
        convertedHours = hours - 12;
        period = 'P';
    } else {
        convertedHours = hours;
        period = 'A';
    }

    convertedMinutes = minutes;
}

void outputResult(int hours, int minutes, int convertedHours, int convertedMinutes, char period) {
    cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " = "
         << convertedHours << ":" << setw(2) << setfill('0') << convertedMinutes << " " << period << "M" << endl;
}

bool isValidTimeSimple(int hours, int minutes) {
    return (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59);
}
