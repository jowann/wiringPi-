//
//  Lcd1602Controller.hpp
//  test
//
//  Created by johann Vandromme on 26/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Lcd1602Controller_hpp
#define Lcd1602Controller_hpp

#include "Lcd1602.hpp"
#include <string>
#include "Queue.hpp"

class Lcd1602Controller{

public:
    Lcd1602Controller(I2C &i2c, int address, Queue &queue = Queue::main());
    Lcd1602Controller(Lcd1602 *lcd1602, Queue &queue = Queue::main());

    void write(int x, int y, std::string message);
    ~Lcd1602Controller();
protected:
    Lcd1602 *_lcd1602 = 0;
    Queue &queue;
private:
    bool allocated = false;
};

#endif /* Lcd1602Controller_hpp */
