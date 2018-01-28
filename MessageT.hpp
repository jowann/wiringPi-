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



template <typename T>
class MessageT:public AbstractMessage{
protected:
    T value;
public:
    MessageT(std::function<void(T)> callback, T value):value(value), callback(callback){};
    
    void send(){callback(value);};
protected:
    std::function<void(T)> callback;
};

#endif /* Message_hpp */
