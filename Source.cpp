#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>
#include <map>

using namespace std;

int main() {
    long double angle, burningSpeed, rocketMass, fuel_mass, gasesSpeed, current_g;
    long double speed_x = 0, speed_y = 0, a = 0, current_speed = 0, current_x = 0, current_y = 0;

    const long double pi = 3.1415;
    const long double G = 6.67 * pow(10, -11);
    const int radius_of_Earth = 6371000;
    long double mass_of_Earth = 5.97 * pow(10, 24);

    cout << "Enter angle:" << endl;
    cin >> angle;
    angle = angle * pi / 180;
    cout << "Enter gases burning speed:" << endl;
    cin >> burningSpeed;
    cout << "Enter gases rocket mass:" << endl;
    cin >> rocketMass;
    cout << "Enter gases fuel mass:" << endl;
    cin >> fuel_mass;
    cout << "Enter gases gases speed:" << endl;
    cin >> gasesSpeed;

    while (current_y >= 0) {
        current_g = (G * mass_of_Earth) / pow(current_y + radius_of_Earth, 2);

        if (fuel_mass > 0)
            a = burningSpeed * gasesSpeed / (rocketMass + fuel_mass);
        else
            a = 0;

        fuel_mass -= burningSpeed;

        if (fuel_mass < 0)
            fuel_mass = 0;

        speed_x = speed_x + a * cos(angle);
        speed_y = speed_y + a * sin(angle) - current_g;
        current_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

        current_x = current_x + speed_x;
        current_y = current_y + speed_y;

        cout << "Current statistics: " << endl;
        cout << "---Coordinate X: " << current_x << endl;
        cout << "---Coordinate Y: " << current_y << endl;
        cout << "---Current speed: " << current_speed << endl;
        cout << "---Current fuel mass: " << fuel_mass << endl;
        cout << endl;
    }
    return 0;
}
