//
//  Mcm3008.hpp
//  test
//
//  Created by johann Vandromme on 13/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Mcp3008_hpp
#define Mcp3008_hpp

#include "Mcp300X.hpp"


#define MCP_3008_CHANNEL_NUMBER 8


typedef enum Mcp3008Channel_enum{
    Mcp3008_Channel0 = 0,
    Mcp3008_Channel1 = 1,
    Mcp3008_Channel2 = 2,
    Mcp3008_Channel3 = 3,
    Mcp3008_Channel4 = 4,
    Mcp3008_Channel5 = 5,
    Mcp3008_Channel6 = 6,
    Mcp3008_Channel7 = 7
}Mcp3008ChannelNumber;

class Mcp3008: public Mcp300X{
public:
    Mcp3008(SpiChannel &spiChannel): Mcp300X(spiChannel, MCP_3008_CHANNEL_NUMBER){}
    Mcp300XChannel &mcp3008Channel(Mcp3008ChannelNumber channel);
    
};



#endif /* Mcm3008_hpp */
