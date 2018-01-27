//
//  Mcp3008.cpp
//  test
//
//  Created by johann Vandromme on 02/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Mcp300X.hpp"


Mcp300X::Mcp300X(SpiChannel &spiChannel, unsigned int nbChannels): _spiChannel(spiChannel), _nbChannels(nbChannels){
    _channels = new Mcp300XChannel*[nbChannels];
    for (int i = 0; i<nbChannels; ++i){
        _channels[i] = 0;
    }
}

Mcp300X::~Mcp300X(){
    for (int i = 0; i<_nbChannels; ++i){
        delete _channels[i];
    }
    delete [] _channels;
}

Mcp300XChannel &Mcp300X::mcp300XChannel(int channel){
    if (_channels[channel] == 0){
        mutex.lock();
        if (_channels[channel] == 0){
            _channels[channel] = new Mcp300XChannel(_spiChannel, channel);
        }
        mutex.unlock();
    }
    return *_channels[channel];
}



