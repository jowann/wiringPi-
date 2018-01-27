//
//  Mcp3004.cpp
//  test
//
//  Created by johann Vandromme on 13/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Mcp3004.hpp"

Mcp300XChannel &Mcp3004::mcp3004Channel(Mcp3004ChannelNumber channel){
    return mcp300XChannel((int) channel);
}