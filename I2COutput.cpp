//
//  I2COutput.cpp
//  test
//
//  Created by johann Vandromme on 15/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "I2COutput.hpp"
#include <wiringPiI2C.h>

I2COutput::I2COutput(int address, std::mutex &mutex): mutex(mutex){
    _fd = wiringPiI2CSetup(address);
}

void I2COutput::write(int value){
    wiringPiI2CWrite(_fd, value);
}


