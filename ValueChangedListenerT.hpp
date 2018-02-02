//
//  ValueChangedListenerT.hpp
//  test
//
//  Created by johann Vandromme on 08/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef ValueChangedListenerT_hpp
#define ValueChangedListenerT_hpp

#include "EventListenerT.hpp"
#include "AbstractMessage.hpp"
#include "MessageT.hpp"
template <typename T>
class ValueChangedListenerT: public EventListenerT<T>{
protected:
    T oldValue;
    std::function<void(T)> callback;
public:
    ValueChangedListenerT(std::function<void(T)> callback, T initialValue = 0, Queue &queue = Queue::main()): EventListenerT<T>(queue), oldValue(initialValue), callback(callback){
        
    }
    
    
    virtual AbstractMessage *valueRead(T value){
        AbstractMessage *message = 0;
        if (value != oldValue){
            message = new MessageT<T>(callback, oldValue);
        }
        oldValue = value;
        return message;
    }
    virtual ~ValueChangedListenerT(){}
};

#endif /* ValueChangedListenerT_hpp */
