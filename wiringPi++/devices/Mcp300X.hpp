//
//  Mcp3008.hpp
//  test
//
//  Created by johann Vandromme on 02/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Mcp3008_hpp
#define Mcp3008_hpp

#include <stdio.h>
#include "../SpiChannel.hpp"
#include "Device.hpp"
#include "Mcp300XChannel.hpp"

#define MCP_3008_CHANNEL_NUMBER 8
#define MCP_3004_CHANNEL_NUMBER 4


typedef enum Mcp3008Channel_enum{
    Mcp3008_Channel0 = 0,
    Mcp3008_Channel1 = 1,
    Mcp3008_Channel2 = 2,
    Mcp3008_Channel3 = 3,
    Mcp3008_Channel4 = 4,
    Mcp3008_Channel5 = 5,
    Mcp3008_Channel6 = 6,
    Mcp3008_Channel7 = 7,
}Mcp3008ChannelNumber;

typedef enum Mcp3004Channel_enum{
    Mcp3004_Channel0 = 0,
    Mcp3004_Channel1 = 1,
    Mcp3004_Channel2 = 2,
    Mcp3004_Channel3 = 3
}Mcp3004ChannelNumber;



class Mcp300X: public Device{
protected:
    unsigned int _nbChannels;
    Mcp300XChannel **_channels;
    Mcp300X(SpiChannel &spiChannel, unsigned int nbChannels);
    SpiChannel &_spiChannel;
    Mcp300XChannel &mcp300XChannel(int channel);
    virtual ~Mcp300X();
};

class Mcp3008: public Mcp300X{
public:
    Mcp3008(SpiChannel &spiChannel): Mcp300X(spiChannel, 8){}
    Mcp300XChannel &mcp3008Channel(Mcp3008ChannelNumber channel);

};
class Mcp3004: public Mcp300X{
public:
    Mcp3004(SpiChannel &spiChannel): Mcp300X(spiChannel, 4){}
    Mcp300XChannel &mcp3004Channel(Mcp3004ChannelNumber channel);
    
};



#endif /* Mcp3008_hpp */
