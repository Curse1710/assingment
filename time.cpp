#include <iostream>
#include <cmath>

using namespace std;

double findClockAngle(double hour, double minute) 
{
    if (hour < 0 || hour > 12 || minute < 0 || minute >= 60) 
    {
        return -1; // Invalid input
    }

    if (hour == 12) 
    {
        hour = 0;
    }

    // Calculate the angles of the hour and minute hands from 12 o'clock
    double hourAngle = 0.5 * (hour * 60 + minute);
    double minuteAngle = 6 * minute;

    // Calculate the absolute difference between the two angles
    double angle = abs(hourAngle - minuteAngle);

    // Take the smaller angle (360 - angle) if it's greater than 180 degrees
    if (angle > 180) 
    {
        angle = 360 - angle;
    }

    return angle;
}

int main() 
{
    double hour, minute;
    cout << "Enter the time (hh:mm or h.mm): ";
    char separator;
    if (cin >> hour >> separator >> minute) 
    {
        double clockAngle = findClockAngle(hour, minute);
        if (clockAngle >= 0) 
        {
            cout << "Angle between hour and minute hands: " << clockAngle << " degrees" << endl;
        } 
        else 
        {
            cout << "Invalid input" << endl;
        }
    } 
    else 
    {
        cout << "Invalid input" << endl;
    }
    return 0;
}