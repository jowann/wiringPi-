//
//  I2C.cpp
//  test
//
//  Created by johann Vandromme on 15/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "I2C.hpp"


I2COutput I2C::output(int address){
    return I2COutput(address, mutex);
}