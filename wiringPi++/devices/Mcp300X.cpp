//
//  Mcp3008.cpp
//  test
//
//  Created by johann Vandromme on 02/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Mcp300X.hpp"



Mcp300X::Mcp300X(SpiChannel &spiChannel, int nbChannels): _spiChannel(spiChannel){
    _channels = new Mcp300XChannel*[nbChannels];
    for (int i = 0; i<nbChannels; ++i){
        _channels[i] = 0;
    }
}

Mcp300X::~Mcp300X(){
    delete [] _channels;
}

Mcp300XChannel &Mcp300X::mcp300XChannel(int channel){
    if (_channels[channel] == 0){
        _channels[channel] = new Mcp300XChannel(_spiChannel, channel);
    }
    return *_channels[channel];
}

Mcp300XChannel &Mcp3008::mcp3008Channel(Mcp3008ChannelNumber channel){
    return mcp300XChannel((int) channel);
}

Mcp300XChannel &Mcp3004::mcp3004Channel(Mcp3004ChannelNumber channel){
    return mcp300XChannel((int) channel);
}

