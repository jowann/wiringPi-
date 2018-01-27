//
//  VoidMessage.hpp
//  wiringPi4CPP
//
//  Created by johann Vandromme on 27/01/2018.
//  Copyright © 2018 Johann Vandromme. All rights reserved.
//

#ifndef VoidMessage_hpp
#define VoidMessage_hpp

#include "AbstractMessage.hpp"

class VoidMessage:public AbstractMessage{
public:
    VoidMessage(std::function<void()> callback):callback(callback){};
    
    void send(){callback();};
protected:
    std::function<void()> callback;
};

#endif /* VoidMessage_hpp */
