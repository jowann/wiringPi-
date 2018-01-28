//
//  Mcp300XChannelController.cpp
//  test
//
//  Created by johann Vandromme on 17/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#include "Mcp300XChannelController.hpp"


Mcp300XChannelController::Mcp300XChannelController(Mcp300XChannel &channel, Queue &queue): EventDispatcherT<float>(channel, queue){
    
}



