//
//  Mcp3004.hpp
//  test
//
//  Created by johann Vandromme on 13/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Mcp3004_hpp
#define Mcp3004_hpp

#include "Mcp300X.hpp"

#define MCP_3004_CHANNEL_NUMBER 4

typedef enum Mcp3004Channel_enum{
    Mcp3004_Channel0 = 0,
    Mcp3004_Channel1 = 1,
    Mcp3004_Channel2 = 2,
    Mcp3004_Channel3 = 3
}Mcp3004ChannelNumber;

class Mcp3004: public Mcp300X{
public:
    Mcp3004(SpiChannel &spiChannel): Mcp300X(spiChannel, MCP_3004_CHANNEL_NUMBER){}
    Mcp300XChannel &mcp3004Channel(Mcp3004ChannelNumber channel);
    
};


#endif /* Mcp3004_hpp */
