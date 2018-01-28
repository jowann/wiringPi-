//
//  GPIOInputController.cpp
//  test
//
//  Created by johann Vandromme on 29/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "GPIOInputController.hpp"
#include "Gpio40Pins.hpp"

GPIOInputController::GPIOInputController(BCM bcmNumber, GpioInputMode mode, Gpio40Pins &board, Queue & queue):gpioInput(board.gpioInput(bcmNumber, mode)), queue(queue) {
    queue.registerDispatcher(this);
}

GPIOInputController::GPIOInputController(GpioInput &gpioInput, Queue &queue):gpioInput(gpioInput), queue(queue){
    queue.registerDispatcher(this);
}

void GPIOInputController::addEventListerner(EventListenerT<GpioValue> *eventListener){
    listeners.push_back(eventListener);
}

void GPIOInputController::readAndDispatch(){
    GpioValue value = gpioInput.read();
    for (EventListenerT<GpioValue> *listener : listeners){
        listener->valueRead(value, queue);
    }
}

GPIOInputController::~GPIOInputController(){
    
}
