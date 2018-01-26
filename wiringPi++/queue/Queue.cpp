//
//  Queue.cpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Queue.hpp"
#include <EventDispatcher.hpp>
#include <wiringPi.h>

MainQueue *MainQueue::mainQueue = 0;
std::mutex Queue::queueMutex;
std::map<std::thread::id, Queue*> Queue::_processingQueues;

MainQueue &MainQueue::instance(){
    if (mainQueue == 0){
        queueMutex.lock();
        if (mainQueue == 0){
            mainQueue = new MainQueue(0);
        }
        queueMutex.unlock();
    }
    return *mainQueue;
}

MainQueue::MainQueue(int delayInMs):Queue(delayInMs), _id(std::this_thread::get_id()){
    
    
}

std::thread::id MainQueue::getId() const{
    return _id;
}

MainQueue &Queue::main(){
    return MainQueue::instance();
}

void Queue::registerDispatcher(EventDispatcher *eventDispatcher){
    eventDispatchers.push_back(eventDispatcher);
}

Queue &Queue::currentQueue(){
    return *Queue::_processingQueues[Queue::currentThreadId()];
}


Queue::~Queue(){
    
}

void Queue::loop(){
    while (!_finish) {
        for (EventDispatcher *eventDispatcher : eventDispatchers){
            eventDispatcher->readAndDispatch();
        }
        messageBox.sendMessages();
        if (idle){
            idle();
        }
        delay(_delay);
    }
}

void Queue::addMessage(AbstractMessage *message){
    messageBox.addMessage(message);
}
void Queue::addMessage(std::function<void()> message){
    messageBox.addMessage(new VoidMessage(message));
}

bool Queue::isCurrentQueue(){
    return Queue::currentThreadId() == getId();
}

void MainQueue::start(){
    _finish = false;
    queueMutex.lock();
    _processingQueues[getId()] = this;
    queueMutex.unlock();
    loop();
    
}
MainQueue::~MainQueue(){
    stop();
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

 std::thread::id AsyncQueue::getId() const{
    return thread->get_id();
}


void AsyncQueue::start(){
    thread = new std::thread([this]() {
        loop();
    });
    queueMutex.lock();
    _processingQueues[getId()] = this;
    queueMutex.unlock();
}

AsyncQueue::~AsyncQueue(){
    stop();
}