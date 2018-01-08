//
//  Message.hpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Message_hpp
#define Message_hpp

#include <thread>
#include "AbstractMessage.hpp"

template <class U, class V>
class MessageUV: public AbstractMessage{
public:
    MessageUV(U value, V &sender, std::function<void(U, V&)> callback):value(value), sender(sender), callback(callback){};
    void send(){callback(value, sender);};
protected:
    U value;
    V &sender;
    std::function<void(U, V&)> callback;
};


class VoidMessage:public AbstractMessage{
public:
    VoidMessage(std::function<void()> callback):callback(callback){};

    void send(){callback();};
protected:
    std::function<void()> callback;
};

template <typename T>
class MessageT:public AbstractMessage{
protected:
    T value;
public:
    MessageT(std::function<void(T)> callback, T value):callback(callback), value(value){};
    
    void send(){callback(value);};
protected:
    std::function<void(T)> callback;
};

#endif /* Message_hpp */
