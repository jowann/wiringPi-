//
//  OnValueChangedListener.cpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "OnValueChangedListener.hpp"

#include <wiringPi.h>

OnValueChangedListener::OnValueChangedListener(AnalogReader &reader): reader(reader){
    
}


void OnValueChangedListener::loop(){
    while (1){
    delay(233);
    float newValue = reader.read();
    if (newValue != lastValue && callback){
        callback(newValue);
    }
    lastValue = newValue;
    }
}
void OnValueChangedListener::start(){
    isFinished = false;
    lastValue = reader.read();
    athread = std::thread (&OnValueChangedListener::loop, this);
    //athread.join();
   
}
void OnValueChangedListener::stop(){
    athread.detach();
}
