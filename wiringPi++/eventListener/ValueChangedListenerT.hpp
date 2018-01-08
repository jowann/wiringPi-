//
//  ValueChangedListenerT.hpp
//  test
//
//  Created by johann Vandromme on 08/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef ValueChangedListenerT_hpp
#define ValueChangedListenerT_hpp

#include <EventListenerT.hpp>
#include <Message.hpp>

template <typename T>
class ValueChangedListenerT: EventListenerT<T>{
protected:
    T oldValue;
    std::function<void(T)> callback;
public:
    ValueChangedListenerT(std::function<void(T)> callback, T initialValue = 0, Queue &queue = Queue::main()): EventListenerT<T>(queue), oldValue(initialValue), callback(callback){
        
    }
    
    
    AbstractMessage *valueRead(T value){
        if (value != oldValue){
            return MessageT<T>(callback, value);
        }
        oldValue = value;
    }
};

#endif /* ValueChangedListenerT_hpp */
