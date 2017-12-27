//
//  Queue.hpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <thread>
#include <mutex>
#include <vector>
#include "AbstractMessage.hpp"
#include "MessageBox.hpp"

class MainQueue;
class EventDispatcher;
class EventListener;

class Queue{
protected:
    std::vector<EventListener *>eventListeners;
    MessageBox messageBox;
    int _delay;
    bool _finish = false;
    Queue(int delayInMs):_delay(delayInMs){};
    virtual void start() = 0;
    virtual void stop() = 0;
    void loop();
    virtual ~Queue();
public:
    std::function<void()> idle;
    static MainQueue &main();
    void registerEventListener(EventListener *eventListener);
    void addMessage(AbstractMessage *message);
    void addMessage(std::function<void()> message);
};

class MainQueue:public Queue{
protected:
    MainQueue(int delayInMs):Queue(delayInMs){}
public:
    void start();
    static MainQueue &instance();
    void stop();
    virtual ~MainQueue();
private:
    static std::mutex mutex;
    static MainQueue *mainQueue;
};

class AsyncQueue:public Queue{
protected:
    std::thread *thread;
public:
    AsyncQueue(int delayInMs):Queue(delayInMs), thread(0){}
    void start();
    void stop();
    virtual ~AsyncQueue();
};

#endif /* Queue_hpp */
