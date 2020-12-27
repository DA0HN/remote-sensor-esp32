//
// Created by daohn on 27/12/2020.
//

#include <WiFi.h>
#include <HTTPClient.h>
#include "Service.h"

const char *ssid = "Wifi-Curvo2.0";
const char *password = "Josemaria11";

boolean isConnected() {
    return WiFiClass::status() == WL_CONNECTED;
}

void initWifi() {
    WiFi.begin(ssid, password);
    getWifiConnection();
    Serial.println("..::Conectado com sucesso!::..");
    Serial.println("Endereço IP: " + String(WiFi.localIP()));
}

void getWifiConnection() {
    Serial.print("Conectando ao WiFi " + String(ssid));
    while (WiFiClass::status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
}

void sendToAPI(double data) {
//    String local_api = "http://192.168.0.32:8080/api/v1/remote-sensors/temperature";
    String api = "http://192.168.0.32:8080/api/v1/remote-sensors/temperature";
    HTTPClient client;

    client.begin(api);
    client.addHeader("Content-Type", "application/json");

    int status = client.POST(String(data));

    if (status > 0) {
        String payload = client.getString();
        Serial.println("Status code: " + String(status));
        Serial.println(payload);
        client.end();
    } else {
        Serial.println("Um erro ocorreu ao receber uma resposta HTTP");
    }
}
