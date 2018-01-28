//
//  Lcd1602.hpp
//  test
//
//  Created by johann Vandromme on 13/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Lcd1602_hpp
#define Lcd1602_hpp

#include "I2C.hpp"

class Lcd1602{
protected:
    void init();
    void writeData(int data);
    I2COutput i2cOutput;
    void sendCommand(int command);
    void sendData(int data);
public:
    Lcd1602(I2C &i2c, int address = 0x3f);
    void write(int x, int y, char data[]);
    void clear();
};

#endif /* Lcd1602_hpp */
