//
//  SpiChannelController.cpp
//  test
//
//  Created by johann Vandromme on 13/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#include "SpiChannelController.hpp"


SpiChannelController::SpiChannelController(SpiChannel &channel, Queue &controllerQueue):channel(channel), queue(controllerQueue){
    
}

SpiChannelController::SpiChannelController(SpiChannelId channelId, Gpio40Pins &board, Queue &controllerQueue): channel(board.spiChannel(channelId)), queue(controllerQueue){
    
}