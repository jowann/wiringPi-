//
//  EventDispatcher.cpp
//  test
//
//  Created by johann Vandromme on 12/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "EventListener.hpp"

EventListener::EventListener(AnalogReader &analogReader, Queue &queue, MessageBox &messageBox):analogReader(analogReader), messageBox(messageBox){
    queue.registerEventListener(this);
}

void EventListener::addListener(AnalogValueChangedListener *listener){
    listener->eventListener = this;
    listeners.push_back(listener);
}


void EventListener::addMessage(float value, std::function<void(float,AnalogReader&)> callback){
    messageBox.addMessage(new Message<float, AnalogReader>(value, analogReader, callback));
}

void EventListener::listen(){
    float newValue = analogReader.read();
    for (AnalogValueChangedListener *listener : listeners){
        listener->valueRead(newValue);
    }
}

void EventListener::dispatchMessages(){
    messageBox.sendMessages();
}