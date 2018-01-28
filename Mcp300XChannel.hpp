//
//  Mcp300XChannel.hpp
//  test
//
//  Created by johann Vandromme on 05/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//
 
#ifndef Mcp300XChannel_hpp
#define Mcp300XChannel_hpp

#include "SpiChannel.hpp"
#include <mutex>
#include "ReaderT.hpp"

typedef enum Mcp300XChannelConfig_enum{
    DIFF   = 0,
    SINGLE = 8
}Mcp300XChannelConfig;


class Mcp300XChannel: public ReaderT<float>{
    Mcp300XChannelConfig channelConfig = SINGLE;
protected:
    int _channel;
    SpiChannel &_spiChannel;
    float read();
    const float __maxValue = 1023;
    float _maxValue();
public:
    Mcp300XChannel(SpiChannel &spiChannel, int channel);

};
    
#endif /* Mcp300XChannel_hpp */
