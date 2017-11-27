//
//  PwmGpioOutput.cpp
//  test
//
//  Created by johann Vandromme on 25/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "PwmGpioOutput.hpp"

#include <wiringPi.h>

#define DEFAULT_GPIO_MAX 1023
PwmGpioOutput::PwmGpioOutput(int identifier, float maxPower): Gpio(identifier), currentPower(0.0f), maxPower(maxPower){
    pinMode(_id,PWM_OUTPUT);
    applyCurrentPower();
}

void PwmGpioOutput::pwmWrite(float power){
    currentPower = power / maxPower * DEFAULT_GPIO_MAX;
    applyCurrentPower();
}
float PwmGpioOutput::power(){
    return currentPower;
}

void PwmGpioOutput::applyCurrentPower(){
    ::pwmWrite(_id, currentPower);
}
PwmGpioOutput::~PwmGpioOutput(){
    currentPower = 0.0f;
    applyCurrentPower();
}



