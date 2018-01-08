//
//  EventListener.hpp
//  test
//
//  Created by johann Vandromme on 12/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef EventListener_hpp
#define EventListener_hpp

#include <AnalogReader.hpp>
#include "Queue.hpp"
#include "MessageBox.hpp"
#include "AnalogValueChangedListener.hpp"
#include <vector>
#include <thread>


class EventListener{
private:
    AnalogReader &analogReader;
    std::vector<AnalogValueChangedListener *>listeners;
    MainQueue &mainQueue;
public:
    void listen();
    EventListener(AnalogReader &analogReader, Queue &queue, MainQueue &mainQueue);
    void addListener(AnalogValueChangedListener *listener);
    void postMessageOnMainThread(float value, std::function<void(float,AnalogReader&)> callback);
};

#endif /* EventListener_hpp */
