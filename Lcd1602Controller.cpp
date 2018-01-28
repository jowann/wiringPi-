//
//  Lcd1602Controller.cpp
//  test
//
//  Created by johann Vandromme on 26/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Lcd1602Controller.hpp"

#include "I2C.hpp"


Lcd1602Controller::Lcd1602Controller(Lcd1602 *lcd1602, Queue &queue): _lcd1602(lcd1602), queue(queue) {
    
}
Lcd1602Controller::Lcd1602Controller(I2C &i2c, int address, Queue &queue): queue(queue), allocated(true){
    _lcd1602 = new Lcd1602(i2c, address);
}

void Lcd1602Controller::write(int x, int y, std::string message){
    queue.addMessage([message,x, y, this](){
        _lcd1602->write(x, y, (char *)message.c_str());
        
    });
    
}

Lcd1602Controller::~Lcd1602Controller(){
    if (allocated){
        delete _lcd1602;
    }
}