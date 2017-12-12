//
//  EventDispatcher.hpp
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
    MessageBox &messageBox;
    std::vector<AnalogValueChangedListener *>listeners;
public:
    void listen();
    EventListener(AnalogReader &analogReader, Queue &queue, MessageBox &messageBox);
    void addListener(AnalogValueChangedListener *listener);
    void addMessage(float value, std::function<void(float,AnalogReader&)> callback);
    void dispatchMessages();
    
};

#endif /* EventDispatcher_hpp */
