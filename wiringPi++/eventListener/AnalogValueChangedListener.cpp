//
//  OnValueChangedListener.cpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "AnalogValueChangedListener.hpp"

#include <wiringPi.h>

AnalogValueChangedListener::AnalogValueChangedListener(AnalogReader &reader): reader(reader){
    
}


void AnalogValueChangedListener::listen(){
    mutex.lock();
    float newValue = reader.read();
    if (newValue != lastValue && callback){
        lastValue = newValue;
        callback(reader, newValue);
    }
    
    mutex.unlock();
    
}
