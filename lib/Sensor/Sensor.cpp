//
// Created by daohn on 27/12/2020.
//
#include <driver/adc.h>
#include <tuple>
#include "Sensor.h"

void setupADC() {
    // configura para leitura de 12 bits da entrada analógica
    adc1_config_width(ADC_WIDTH_BIT_12);
    // reduz para 1.1v a tensão de entrada do canal analógico 0 (GPIO 36 / pin VP)
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_0);
}

std::tuple<double, double> doRead() {
//    double voltage = (input * 5 * 100) / 4096;
//    double temperatura = voltage / 0.1;
    // Realiza leitura da GPIO 36
    double input = adc1_get_raw(ADC1_CHANNEL_0);
    // Equação:
    // A entrada analógica do esp32 possui resolução de 12bits -> 4096
    // 1.1v para 4096 -> 1.1/4096 = 0.268mV.
    // Cada alteração na leitura analógica irá corresponder a 0.268mV
    // Para o Lm35 1ºC corresponde a 10mV, assim 10mV/0.268mV = 37.31
    double temperatura = input / 37.31;
    return std::make_tuple(temperatura, input);
}
