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

#define Gpio40Number 30


class Gpio40Pins{
    
private:
    static Gpio40Pins *_instance;
    Gpio *allGPIOs[Gpio40Number];
    
    Gpio40Pins();
    
    Gpio40Pins& operator= (const Gpio40Pins&){}
public:
    static Gpio40Pins &Instance();
    static void deleteInstance();
    GpioOutput &gpioOutput(BCM bcmNumber);
    GpioInput &gpioInput(BCM bcmNumber, GpioInputMode mode);
    PwmGpioOutput &pwmGpio18Output(float max = 1023);
    ~Gpio40Pins();
    
    
    
};

#endif /* Gpio40Pins_hpp */
