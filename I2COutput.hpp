//
//  I2COutput.hpp
//  test
//
//  Created by johann Vandromme on 15/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef I2COutput_hpp
#define I2COutput_hpp

#include <mutex>

class I2COutput{
private:
    int _fd; // file descriptor
    int address;
    std::mutex &mutex;
public:
    I2COutput(int address, std::mutex &mutex);
    void write(int value);

};

#endif /* I2COutput_hpp */
