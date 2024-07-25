#include <iostream>
#include <iomanip> // For setw and setfill
#include <cctype>  // For tolower function

using namespace std;

bool isValidTime(int hours, int minutes, char ampm) {
    ampm = tolower(ampm); // Convert to lowercase for uniformity
    if (hours < 0 || hours > 12) {
        return false;
    }
    if (minutes < 0 || minutes >= 60) {
        return false;
    }
    if (ampm != 'a' && ampm != 'p') {
        return false;
    }
    return true;
}

void calculateNewTime(int hours, int minutes, char ampm, int waitTime) {
    int originalHours = hours;
    int originalMinutes = minutes;
    char originalAmpm = ampm;

    // Convert 12-hour time to 24-hour time for easier calculation
    ampm = tolower(ampm); // Convert to lowercase for uniformity
    if (hours == 0) {
        hours = 12; // Handle 0 as 12 in 12-hour format
    }
    if (ampm == 'p' && hours != 12) {
        hours += 12;
    }
    if (ampm == 'a' && hours == 12) {
        hours = 0;
    }

    // Add the waiting time
    minutes += waitTime;
    hours += minutes / 60;
    minutes = minutes % 60;
    hours = hours % 24;

    // Convert back to 12-hour time
    string newAmpm = "AM";
    if (hours >= 12) {
        newAmpm = "PM";
    }
    if (hours > 12) {
        hours -= 12;
    }
    if (hours == 0) {
        hours = 12;
    }

    // Print the result
    cout << "Current time = " << setw(2) << setfill('0') << originalHours << ":"
         << setw(2) << setfill('0') << originalMinutes << " "
         << (originalAmpm == 'a' || originalAmpm == 'A' ? "AM" : "PM") << endl;
    cout << "Time after waiting period = " << setw(2) << setfill('0') << hours << ":"
         << setw(2) << setfill('0') << minutes << " " << newAmpm << endl;
    cout << endl;
}

int main() {
    int hours, minutes, waitTime;
    char ampm, again;

    do {
        do {
            cout << "Enter hour:" << endl;
            cin >> hours;
            cout << endl;

            cout << "Enter minutes:" << endl;
            cin >> minutes;
            cout << endl;

            cout << "Enter A for AM, P for PM:" << endl;
            cin >> ampm;
            cout << endl;

            if (!isValidTime(hours, minutes, ampm)) {
                cout << "Invalid time input. Please try again." << endl;
            }
        } while (!isValidTime(hours, minutes, ampm));

        cout << "Enter waiting time:" << endl;
        cin >> waitTime;
        cout << endl;

        calculateNewTime(hours, minutes, ampm, waitTime);

        cout << "Again:" << endl;
        cin >> again;
        if (again == 'y' || again == 'Y')
            cout << endl;
    } while (again == 'y' || again == 'Y');

    return 0;
}
