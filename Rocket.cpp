#include <iostream>
#include <cmath>
#define PI 3.14159265

using namespace std;

int main() {
    const double G = 6.67 * pow(10, -11);
    const double earthMass = 5.97 * pow(10, 24);

    double angle, burningSpeed, rocketMass, fuelMass, gasesSpeed;
    double speedX, speedY, g, previousSpeed;
    double speed = 0;
    double x = 0;
    double y = 0;
    
    cin >> angle >> burningSpeed >> rocketMass >> fuelMass >> gasesSpeed;

    angle = angle * PI / 180.0;

    while (fuelMass > 0) {
        if (y != 0) {
            g = (G * earthMass) / (pow(y, 2)); //m << M
        }
        else {
            g = 9.80665;
        }

        previousSpeed = speed;

        speed = burningSpeed * gasesSpeed / (rocketMass + fuelMass);
        speedX = cos(angle) * speed;
        speedY = sin(angle) * speed;

        x = x + speedX * 1 + cos(angle) * (speed - previousSpeed) / 2;
        y = y + speedY * 1 + (sin(angle) * (speed - previousSpeed) - g) / 2;

        angle = atan(speedY / speedX);

        cout << "Current x coordinate: " << x << endl;
        cout << "Current y coordinate: " << y << endl;
        cout << "Current speed: " << speed << endl;
        cout << "Current fuel mass: " << fuelMass << endl;
        cout << endl;

        fuelMass -= burningSpeed;
    }

    return 0;
}