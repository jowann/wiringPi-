//
//  Mcp300XChannel.cpp
//  test
//
//  Created by johann Vandromme on 05/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Mcp300XChannel.hpp"

Mcp300XChannel::Mcp300XChannel(SpiChannel spiChannel, int channel): _channel(channel), _spiChannel(spiChannel){
}




float Mcp300XChannel::_read(){
    unsigned char buffer[3] = {1}; // start bit
    buffer[1] = (channelConfig+_channel) << 4;
    _spiChannel.dataRW(buffer, 3);
    return ( (buffer[1] & 3 ) << 8 ) + buffer[2]; // get last 10 bits
}

float Mcp300XChannel::_maxValue(){
    return __maxValue;
}