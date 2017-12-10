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
PwmGpioOutput::PwmGpioOutput(int identifier, float maxValue): Gpio(identifier), currentValue(0.0f), maxValue(maxValue){
    pinMode(_id,PWM_OUTPUT);
    applyCurrentValue();
}

void PwmGpioOutput::pwmWrite(float value){
    mutex.lock();
    currentValue = value / maxValue * DEFAULT_GPIO_MAX;
    applyCurrentValue();
    mutex.unlock();
}
float PwmGpioOutput::value(){
    return currentValue;
}

void PwmGpioOutput::applyCurrentValue(){
    ::pwmWrite(_id, currentValue);
}
PwmGpioOutput::~PwmGpioOutput(){
    currentValue = 0.0f;
    applyCurrentValue();
}



