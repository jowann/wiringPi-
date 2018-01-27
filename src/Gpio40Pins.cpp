//
//  Gpio40Pins.cpp
//  test
//
//  Created by johann Vandromme on 24/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "Gpio40Pins.hpp"

#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <unistd.h>
#include <I2C.hpp>


Gpio40Pins *Gpio40Pins::_instance;


Gpio40Pins::Gpio40Pins(){
    if(wiringPiSetup()== -1){
        printf("Setup wiringPi Failed!");
        exit(-1);
    }
    for (int i = 0; i < GPIO_PORT_COUNT; ++i){
        allGPIOs[i] = 0;
    }
    for (int i = 0; i < SPI_CHANNEL_COUNT; ++i){
        _spiFileDescriptor[i] = 0;
    }
    
}


GpioOutput &Gpio40Pins::gpioOutput(BCM bcmNumber){
    if (allGPIOs[bcmNumber] == 0){
        allGPIOs[bcmNumber] = new GpioOutput(bcmNumber);
    }
    return *static_cast<GpioOutput *>(allGPIOs[bcmNumber]);
}


GpioInput &Gpio40Pins::gpioInput(BCM bcmNumber, GpioInputMode mode){
    if (allGPIOs[bcmNumber] == 0){
        allGPIOs[bcmNumber] = new GpioInput(bcmNumber, mode);
    }
    return *static_cast<GpioInput *>(allGPIOs[bcmNumber]);
}

PwmGpioOutput &Gpio40Pins::pwmGpio18Output(float max){
    PWM pwmNumber = PWM_GPIO_18;
    if (allGPIOs[pwmNumber] == 0){
        allGPIOs[pwmNumber] = new PwmGpioOutput(pwmNumber, max);
    }
    return *static_cast<PwmGpioOutput *>(allGPIOs[pwmNumber]);
    
}

SpiChannel &Gpio40Pins::spiChannel(SpiChannelId channelId){
    if (_spiFileDescriptor[channelId] == 0){
        _spiFileDescriptor[channelId] = wiringPiSPISetup (channelId, 10000);
        if (_spiFileDescriptor[channelId] < 0){
            printf ("Can't open the SPI bus\n") ;
            exit (EXIT_FAILURE) ;
        }
    }
    
    return *(new SpiChannel(channelId));
}

I2C &Gpio40Pins::i2c(){
    if (_i2c == 0){
        _i2c = new I2C();
    }
    return *_i2c;
}

Gpio40Pins::~Gpio40Pins(){
    for (int i = 0; i< GPIO_PORT_COUNT; ++i){
        delete allGPIOs[i];
    }
    for (int i = 0; i < SPI_CHANNEL_COUNT; ++i){
        close(_spiFileDescriptor[i]);
    }
}



 Gpio40Pins &Gpio40Pins::Instance(){
    if (_instance == 0){
        _instance = new Gpio40Pins();
    }
    return *_instance;
}
 void Gpio40Pins::deleteInstance(){
    delete _instance;
     _instance = 0;
}


