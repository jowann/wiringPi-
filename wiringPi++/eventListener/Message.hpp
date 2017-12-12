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
class Message: public AbstractMessage{
public:
    Message(U value, V &sender, std::function<void(U, V&)> callback):value(value), sender(sender), callback(callback){};
    void send(){callback(value, sender);};
protected:
    U value;
    V &sender;
    std::function<void(U, V&)> callback;
};

#endif /* Message_hpp */
