//
//  SpiChannel.hpp
//  test
//
//  Created by johann Vandromme on 01/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef SpiChannel_hpp
#define SpiChannel_hpp


#include "SpiChannelId.hpp"

class SpiChannel{
public:
    SpiChannel(SpiChannelId channelId);
    void dataRW(unsigned char *buffer, unsigned int bufferSize);
    ~SpiChannel();
protected:
    SpiChannelId _channelId;
    
};

#endif /* SpiChannel_hpp */
