//
//  Lcd1602.cpp
//  test
//
//  Created by johann Vandromme on 13/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Lcd1602.hpp"
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <string.h>

int BLEN = 1;

Lcd1602::Lcd1602(I2C &i2c, int address):i2cOutput(i2c.output(address)){
    init();
}

void Lcd1602::init(){
    sendCommand(0x33); // Must initialize to 8-line mode at first
    delay(5);
    sendCommand(0x32); // Then initialize to 4-line mode
    delay(5);
    sendCommand(0x28); // 2 Lines & 5*7 dots
    delay(5);
    sendCommand(0x0C); // Enable display without cursor
    delay(5);
    sendCommand(0x01); // Clear Screen
    i2cOutput.write(0x08);
}

void Lcd1602::clear(){
    sendCommand(0x01);
}

//send command to lcd
void Lcd1602::sendCommand(int command){
    int buf;
    // Send bit7-4 firstly
    buf = command & 0xF0;
    buf |= 0x04;            // RS = 0, RW = 0, EN = 1
    writeData(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    writeData(buf);
    
    // Send bit3-0 secondly
    buf = (command & 0x0F) << 4;
    buf |= 0x04;            // RS = 0, RW = 0, EN = 1
    writeData(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    writeData(buf);
}

void Lcd1602::writeData(int data){
    int temp = data;
    if ( BLEN == 1 )
        temp |= 0x08;
    else
        temp &= 0xF7;
    i2cOutput.write(temp);
}

void Lcd1602::sendData(int data){
    int buf;
    // Send bit7-4 firstly
    buf = data & 0xF0;
    buf |= 0x05;            // RS = 1, RW = 0, EN = 1
    writeData(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    writeData(buf);
    
    // Send bit3-0 secondly
    buf = (data & 0x0F) << 4;
    buf |= 0x05;            // RS = 1, RW = 0, EN = 1
    writeData(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    writeData(buf);
}

void Lcd1602::write(int x, int y, char *data){
    int addr, i;
    int tmp;
    if (x < 0)  x = 0;
    if (x > 15) x = 15;
    if (y < 0)  y = 0;
    if (y > 1)  y = 1;
    
    // Move cursor
    addr = 0x80 + 0x40 * y + x;
    sendCommand(addr);
    
    tmp = (int)strlen(data);
    for (i = 0; i < tmp; i++){
        sendData(data[i]);
    }
}

