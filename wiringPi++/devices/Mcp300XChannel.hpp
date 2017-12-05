//
//  Mcp300XChannel.hpp
//  test
//
//  Created by johann Vandromme on 05/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Mcp300XChannel_hpp
#define Mcp300XChannel_hpp

#include "../SpiChannel.hpp"

typedef enum Mcp300XChannelConfig_enum{
    DIFF   = 0,
    SINGLE = 8
}Mcp300XChannelConfig;


class Mcp300XChannel{
    Mcp300XChannelConfig channelConfig = SINGLE;
protected:
    int _channel;
    SpiChannel _spiChannel;
public:
    Mcp300XChannel(SpiChannel spiChannel, int channel);
    int read();

};
    
#endif /* Mcp300XChannel_hpp */
