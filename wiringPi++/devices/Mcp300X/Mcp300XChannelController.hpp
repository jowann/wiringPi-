//
//  Mcp300XChannelController.hpp
//  test
//
//  Created by johann Vandromme on 17/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef Mcp300XChannelController_hpp
#define Mcp300XChannelController_hpp

#include <EventDispatcherT.hpp>
#include <Mcp300XChannel.hpp>

class Mcp300XChannelController: public EventDispatcherT<float>{

    
public:
    Mcp300XChannelController(Mcp300XChannel &channel, Queue &queue = Queue::main());
    
};

#endif /* Mcp300XChannelController_hpp */
