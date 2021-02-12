//
// Created by daohn on 27/12/2020.
//

#ifndef UNTITLED_SENSOR_H
#define UNTITLED_SENSOR_H

/**
 * Equação:
 * A entrada analógica do esp32 possui resolução de 12bits -> 4096 <br>
 * 1.1v para 4096 -> 1.1/4096 = 0.268mV. <br>
 * Cada alteração na leitura analógica irá corresponder a 0.268mV <br>
 * Para o Lm35 1ºC corresponde a 10mV, assim 10mV/0.268mV = 37.31 <br>
 *
 * @return std::tuple<double, double> temperatura, input
 */
std::tuple<double, double> doRead();

/**
 * Configura canal analógico para utilizar entrada de 12 bits <br>
 * Reduz a tensão de entrada para 1.1v para aumentar a precisão da conversão [tensão -> temperatura]
 */
void setupAnalogChannel();

#endif //UNTITLED_SENSOR_H
