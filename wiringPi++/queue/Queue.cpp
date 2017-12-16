//
//  Queue.cpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Queue.hpp"
#include <EventListener.hpp>
#include <wiringPi.h>

MainQueue *MainQueue::mainQueue = 0;
std::mutex MainQueue::mutex;

MainQueue &MainQueue::instance(){
    if (mainQueue == 0){
        mutex.lock();
        if (mainQueue == 0){
            mainQueue = new MainQueue(0);
        }
        mutex.unlock();
    }
    return *mainQueue;
}

MainQueue &Queue::main(){
    return MainQueue::instance();
}

void Queue::registerEventListener(EventListener *eventListener){
    eventListeners.push_back(eventListener);
}

void Queue::loop(){
    for (EventListener *eventListener: eventListeners){
        eventListener->listen();
    }
    messageBox.sendMessages();
    if (idle){
        idle();
    }
    delay(_delay);
}

void Queue::addMessage(AbstractMessage *message){
    messageBox.addMessage(message);
}
void Queue::addMessage(std::function<void()> message){
    messageBox.addMessage(new VoidMessage(message));
}

void MainQueue::start(){
    while (!_finish) {
        loop();
    }
}

void MainQueue::stop(){
    _finish = true;
}


void AsyncQueue::stop(){
    if (thread == 0){
        return;
    }
    thread->detach();
    delete  thread;
    thread = 0;
}


void AsyncQueue::start(){
    thread = new std::thread([this]() {
        loop();
    });
}