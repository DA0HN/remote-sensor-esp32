#include <Arduino.h>
#include <tuple>
#include <Service.h>
#include <Sensor.h>

void setup() {
    Serial.begin(115200);
    setupADC();
    initWifi();
}

void loop() {
    double temperatura, input;
    std::tie(temperatura, input) = doRead();
    Serial.println(input);
    Serial.println(temperatura);

    if(isConnected()) {
        sendToAPI(temperatura);
    }
    else {
        Serial.println("Não há conexão WiFi");
    }
    // TODO: usar timer no lugar do delay
    delay(8000);
}


