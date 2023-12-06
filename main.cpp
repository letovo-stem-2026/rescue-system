#include <VB_MPU9250.h>
#include <VB_BMP280.h>
#include <Servo.h>

Servo parachute;
VB_BMP280 barometer;

bool barometer_connection = false;
bool opened = false;
float max_height = 0;

const float EPS = 1.0;
const int SERVOPIN = 9;

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
    }
    parachute.attach(SERVOPIN);
    parachute.write(90);
    delay(100);
    barometer.start_altitude = 0;
    while (!barometer_connection)
        barometer_connection = barometer.begin();
}

void loop()
{
    barometer.read();
    float cur_height = barometer.alti;
    Serial.println(cur_height);
    max_height = max(max_height, barometer.alti);

    if (!opened && cur_height + EPS < max_height)
    {
        opened = true;
        Serial.println("OPENED");
        parachute.write(180);
    }

    delay(100);
}
