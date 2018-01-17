//
//  EventDispatcherT.hpp
//  test
//
//  Created by johann Vandromme on 17/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef EventDispatcherT_hpp
#define EventDispatcherT_hpp

#include <EventDispatcher.hpp>
#include <ReaderT.hpp>
#include <Queue.hpp>
#include <vector>
#include <EventListenerT.hpp>

template <typename T>
class EventDispatcherT: public EventDispatcher{
protected:
    ReaderT<T> &reader;
    Queue &queue;
    std::vector<EventListenerT<T> *> listeners;
public:
    EventDispatcherT(ReaderT<T> &reader, Queue &queue = Queue::main()): reader(reader), queue(queue){
        queue.registerDispatcher(this);
    }
    
    void addEventListerner(EventListenerT<T> *eventListener){
        listeners.push_back(eventListener);
    }
    void readAndDispatch(){
        T value = reader.read();
        for (EventListenerT<T> *listener : listeners){
            listener->valueRead(value, queue);
        }
    }
    
    virtual ~EventDispatcherT(){
        for (EventListenerT<T> *listener : listeners){
            delete listener;
        }
    }
};

#endif /* EventDispatcherT_hpp */
