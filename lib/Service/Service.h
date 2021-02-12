//
// Created by daohn on 27/12/2020.
//

#ifndef REMOTE_SENSOR_CPP_SERVICE_H
#define REMOTE_SENSOR_CPP_SERVICE_H


/**
 * Checa se o microcontrolador está conectado com o WiFi
 * @return true se houver conexão WiFi false caso contrário
 */
boolean isConnected();

/**
 * Inicia a conexão WiFi
 */
void connect();

/**
 * Envia a temperatura coletada para a API
 * @param data
 */
void sendData(double data);

#endif //REMOTE_SENSOR_CPP_SERVICE_H
