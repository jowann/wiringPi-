//
//  SpiChannelController.hpp
//  test
//
//  Created by johann Vandromme on 13/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef SpiChannelController_hpp
#define SpiChannelController_hpp

#include "SpiChannel.hpp"
#include "Queue.hpp"
#include "SpiChannelId.hpp"
#include "Gpio40Pins.hpp"
class SpiChannelController{
protected:
    SpiChannel &channel;
    Queue &queue;
public:
    SpiChannelController(SpiChannel &channel, Queue &controllerQueue);
    SpiChannelController(SpiChannelId channelId, Gpio40Pins &board, Queue &controllerQueue);
    //void dataRW(unsigned char *buffer, unsigned int bufferSize);
};

#endif /* SpiChannelController_hpp */
