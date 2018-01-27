//
//  GPIOInputController.hpp
//  test
//
//  Created by johann Vandromme on 29/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef GPIOInputController_hpp
#define GPIOInputController_hpp

#include <BCM.hpp>
#include <Queue.hpp>
#include <ReaderT.hpp>
#include <GpioInput.hpp>
#include <Gpio40Pins.hpp>
#include <EventDispatcher.hpp>
#include <EventListenerT.hpp>

#include <vector>

class GPIOInputController: public EventDispatcher{
private:
    GpioInput &gpioInput;
    Queue &queue;
    std::vector<EventListenerT<GpioValue> *> listeners;
public:
    GPIOInputController(GpioInput &gpioInput, Queue &queue = Queue::main());
    GPIOInputController(BCM bcmNumber, GpioInputMode mode, Gpio40Pins &board, Queue &queue = Queue::main());
    
    void addEventListerner(EventListenerT<GpioValue> *eventListener);
    void readAndDispatch();
    
    virtual ~GPIOInputController();
};

#endif /* GPIOInputController_hpp */
