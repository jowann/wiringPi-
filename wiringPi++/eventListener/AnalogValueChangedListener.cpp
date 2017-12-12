//
//  OnValueChangedListener.cpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "AnalogValueChangedListener.hpp"

#include <wiringPi.h>
#include "Queue.hpp"
#include "EventListener.hpp"

AnalogValueChangedListener::AnalogValueChangedListener(){
   
}


void AnalogValueChangedListener::valueRead(float newValue){
    
    if (newValue != lastValue){
        mutex.lock();
        if (newValue != lastValue){
            lastValue = newValue;
            emitMessage(newValue);

        }
        mutex.unlock();
    }
    
}
    



void AnalogValueChangedListener::emitMessage(float value){
    eventListener->addMessage(value, callback);
    
}
