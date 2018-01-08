//
//  GpioInput.cpp
//  test
//
//  Created by johann Vandromme on 27/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "GpioInput.hpp"


GpioInput::GpioInput(int identifier, GpioInputMode mode):Gpio(identifier){
    pinMode(identifier, INPUT);
    pullUpDnControl(identifier, mode);
}

GpioValue GpioInput::digitalRead(){
    mutex.lock();
    GpioValue gpioValue = (GpioValue) ::digitalRead(_id);
    mutex.unlock();
    return static_cast<GpioValue>(gpioValue);
}



GpioInput::~GpioInput(){
    
}