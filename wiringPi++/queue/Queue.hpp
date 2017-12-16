//
//  Queue.hpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <mutex>
#include <vector>
#include "AbstractMessage.hpp"
#include "MessageBox.hpp"

class MainQueue;
class EventDispatcher;
class EventListener;

class Queue{
private:
    std::vector<EventListener *>eventListeners;
protected:
    Queue(){};
    virtual void launch() = 0;
public:
    static MainQueue &main();
    void registerEventListener(EventListener *eventListener);
};

class MainQueue:public Queue{
public:
    void launch();
    MessageBox messageBox;
    
    static MainQueue &instance();
private:
    static std::mutex mutex;
    static MainQueue *mainQueue;

    
    
    
};

class AsyncQueue:public Queue{
    void launch();
};

#endif /* Queue_hpp */
