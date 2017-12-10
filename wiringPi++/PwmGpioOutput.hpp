//
//  PwmGpioOutput.hpp
//  test
//
//  Created by johann Vandromme on 25/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef PwmGpioOutput_hpp
#define PwmGpioOutput_hpp

#include "Gpio.hpp"

class PwmGpioOutput:public Gpio{
public:
    PwmGpioOutput(int identifier, float maxValue = 1023);
    void pwmWrite(float value);
    float value();
    ~PwmGpioOutput();
protected:
    int currentValue;
    float maxValue;
private:
    void applyCurrentValue();
};

#endif /* PwmGpioOutput_hpp */
