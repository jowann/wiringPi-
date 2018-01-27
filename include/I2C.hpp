//
//  I2C.hpp
//  test
//
//  Created by johann Vandromme on 15/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef I2C_hpp
#define I2C_hpp

#include <mutex>
#include <I2COutput.hpp>


class I2C{
private:
    std::mutex mutex;
public:
    I2COutput output(int address);
};

#endif /* I2C_hpp */
