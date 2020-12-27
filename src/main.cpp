#include <Arduino.h>
#include <tuple>
#include <Sensor.h>

void setup() {
    Serial.begin(115200);
    setupADC();
}

void loop() {
    double temperatura, input;
    std::tie(temperatura, input) = doRead();
    Serial.println(input);
    Serial.println(temperatura);
    delay(2000);
}


