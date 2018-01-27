//
//  Mcm3008.cpp
//  test
//
//  Created by johann Vandromme on 13/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Mcp3008.hpp"

Mcp300XChannel &Mcp3008::mcp3008Channel(Mcp3008ChannelNumber channel){
    return mcp300XChannel((int) channel);
}

