//
//  EventListener.cpp
//  test
//
//  Created by johann Vandromme on 12/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "EventListener.hpp"

EventListener::EventListener(AnalogReader &analogReader, Queue &queue, MainQueue &mainQueue):analogReader(analogReader), mainQueue(mainQueue){
    queue.registerEventListener(this);
}

void EventListener::addListener(AnalogValueChangedListener *listener){
    listener->eventListener = this;
    listeners.push_back(listener);
}


void EventListener::postMessageOnMainThread(float value, std::function<void(float,AnalogReader&)> callback){
    mainQueue.addMessage(new MessageUV<float, AnalogReader>(value, analogReader, callback));
}

void EventListener::listen(){
    float newValue = analogReader.read();
    for (AnalogValueChangedListener *listener : listeners){
        listener->valueRead(newValue);
    }
}

