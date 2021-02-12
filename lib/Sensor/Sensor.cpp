//
// Created by daohn on 27/12/2020.
//
#include <driver/adc.h>
#include <tuple>
#include "Sensor.h"

void setupAnalogChannel() {
    adc1_config_width(          // configura para leitura de 12 bits da entrada analógica
            ADC_WIDTH_BIT_12
    );
    adc1_config_channel_atten(  // reduz para 1.1v a tensão de entrada do canal analógico 0 (GPIO 36 / pin VP)
            ADC1_CHANNEL_0,
            ADC_ATTEN_DB_0
    );
}

std::tuple<double, double> doRead() {
    double constant = 37.31;
    double input = adc1_get_raw(ADC1_CHANNEL_0);        // Realiza leitura da GPIO 36
    double temperatura = input / constant;                      // Converte a temperatura utilizando a constante
    return std::make_tuple(temperatura, input);
}
