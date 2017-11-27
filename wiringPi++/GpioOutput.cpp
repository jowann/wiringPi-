//
//  GpioOutput.cpp
//  test
//
//  Created by johann Vandromme on 24/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "GpioOutput.hpp"

GpioOutput::GpioOutput(int identifier): Gpio(identifier){
    _value = Low;
    pinMode(_id, OUTPUT);
}

void GpioOutput::digitalWrite(GpioValue value){
    _value = value;
    // call digitalWrite from global namespace (wiringPi C function)
    ::digitalWrite(_id,_value);
}

GpioValue GpioOutput::value(){
    return _value;
}

GpioOutput::~GpioOutput(){
    ::digitalWrite(_id,LOW);
}