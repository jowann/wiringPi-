//
//  AsyncAnalogValueChangedListener.cpp
//  test
//
//  Created by johann Vandromme on 10/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "AsyncAnalogValueChangedListener.hpp"

#include <wiringPi.h>
/*
AsyncAnalogValueChangedListener::AsyncAnalogValueChangedListener(AnalogReader &reader): listener(reader){
}

void AsyncAnalogValueChangedListener::onValueChanged(AnalogReader& channel, float value){
    
}

void AsyncAnalogValueChangedListener::loop(){
    while (1){
        delay(233);
        listener.listen();
    }
}
void AsyncAnalogValueChangedListener::start(){
    listener.callback = [](AnalogReader& channel, float value){
        printf("%f", value);
    };

    athread = std::thread (&AsyncAnalogValueChangedListener::loop, this);
    //athread.join();
    
}
void AsyncAnalogValueChangedListener::stop(){
    //listener.callback = false;
    athread.detach();
}*/