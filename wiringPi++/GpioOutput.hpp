//
//  GpioOutput.hpp
//  test
//
//  Created by johann Vandromme on 24/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef GpioOutput_hpp
#define GpioOutput_hpp

#include "BCM.hpp"
#include "Gpio.hpp"
#include "GpioValue.hpp"
#include "GenGPIOMode.hpp"

class GpioOutput: public Gpio{
    
private:
    
    GpioValue _value;
public:
    
    GpioOutput(int identifier);
    
    void digitalWrite(GpioValue value);
    
    GpioValue value();
    
    ~GpioOutput();
};
#endif /* GPIOOutput_hpp */
