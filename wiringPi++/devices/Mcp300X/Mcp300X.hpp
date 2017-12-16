//
//  Mcp3008.hpp
//  test
//
//  Created by johann Vandromme on 02/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Mcp300X_hpp
#define Mcp300X_hpp

#include <stdio.h>
#include <mutex>
#include <SpiChannel.hpp>
#include <Device.hpp>
#include <Mcp300XChannel.hpp>





class Mcp300X: public Device{
protected:
    unsigned int _nbChannels;
    Mcp300XChannel **_channels;
    Mcp300X(SpiChannel &spiChannel, unsigned int nbChannels);
    SpiChannel &_spiChannel;
    Mcp300XChannel &mcp300XChannel(int channel);
    virtual ~Mcp300X();
private:
    std::mutex mutex;
};





#endif /* Mcp3008_hpp */
