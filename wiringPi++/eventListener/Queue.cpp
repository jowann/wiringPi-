//
//  Queue.cpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Queue.hpp"


MainQueue *MainQueue::mainQueue = 0;
std::mutex MainQueue::mutex;

MainQueue &MainQueue::instance(){
    if (mainQueue == 0){
        mutex.lock();
        if (mainQueue == 0){
            mainQueue = new MainQueue();
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

void MainQueue::launch(){
    printf("TODO");
}


void AsyncQueue::launch(){
    printf("TODO");
}