//
// Created by daohn on 27/12/2020.
//

#ifndef REMOTE_SENSOR_CPP_SERVICE_H
#define REMOTE_SENSOR_CPP_SERVICE_H

void initWifi();

boolean isConnected();

void getWifiConnection();

void sendToAPI(double data);

#endif //REMOTE_SENSOR_CPP_SERVICE_H
