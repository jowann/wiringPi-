//
//  EventListenerV2.hpp
//  test
//
//  Created by johann Vandromme on 01/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef EventListenerT_hpp
#define EventListenerT_hpp

#include <Queue.hpp>
#include <AbstractMessage.hpp>

template <typename T>
class EventListenerT{
protected:
    Queue &queue;
    virtual AbstractMessage *valueRead(T value) = 0;
public:
    EventListenerT(Queue &queue = Queue::main()):queue(queue){}
    void valueRead(T value, Queue &onQueue){
        AbstractMessage *message = valueRead(value);
        if (!message) return;
        if (&onQueue == &queue){
            message->send();
            delete message;
        } else {
            queue.addMessage(message);
        }
    }
};

#endif /* EventListenerV2_hpp */
