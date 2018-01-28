//
//  Gpio40Pins.hpp
//  test
//
//  Created by johann Vandromme on 24/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//


#ifndef Gpio40Pins_hpp
#define Gpio40Pins_hpp

#include "Gpio.hpp"
#include "GpioOutput.hpp"
#include "GpioInput.hpp"
#include "PwmGpioOutput.hpp"
#include "SpiChannel.hpp"
#include "I2C.hpp"

#define GPIO_PORT_COUNT 30
#define SPI_CHANNEL_COUNT 2

class Gpio40Pins{
    
private:
    static Gpio40Pins *_instance;
    Gpio *allGPIOs[GPIO_PORT_COUNT];
    
    Gpio40Pins();
    
    Gpio40Pins& operator= (const Gpio40Pins&){return *this;}
    int _spiFileDescriptor[SPI_CHANNEL_COUNT];
    I2C *_i2c = 0;
public:
    static Gpio40Pins &Instance();
    static void deleteInstance();
    GpioOutput &gpioOutput(BCM bcmNumber);
    GpioInput &gpioInput(BCM bcmNumber, GpioInputMode mode);
    PwmGpioOutput &pwmGpio18Output(float max = 1023);
    SpiChannel &spiChannel(SpiChannelId channelId);
    I2C &i2c();
    ~Gpio40Pins();
    
    
    
};

#endif /* Gpio40Pins_hpp */
