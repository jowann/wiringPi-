//
//  AnalogValueChangedListener.hpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef AnalogValueChangedListener_hpp
#define AnalogValueChangedListener_hpp

#include <AnalogReader.hpp>
#include <thread>
#include <mutex>
#include "MessageBox.hpp"

class EventListener;

class AnalogValueChangedListener{
private:
    float lastValue = -1;
    std::mutex mutex;
    void emitMessage(float value);
    
public:
    AnalogValueChangedListener();
    std::function<void(float, AnalogReader&)> callback;
    EventListener *eventListener;
    void valueRead(float newValue);
};
#endif /* AnalogValueChangedListener_hpp */
