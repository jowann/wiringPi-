//
//  SpiChannel.cpp
//  test
//
//  Created by johann Vandromme on 01/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "SpiChannel.hpp"

#include <wiringPiSPI.h>


SpiChannel::SpiChannel(SpiChannelId channelId):_channelId(channelId){
    
}
SpiChannel::~SpiChannel(){
    
}
void SpiChannel::dataRW(unsigned char *buffer, unsigned int bufferSize){
    mutex.lock();
    wiringPiSPIDataRW(_channelId, buffer, bufferSize);
    mutex.unlock();
}


