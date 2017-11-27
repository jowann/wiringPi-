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
    PwmGpioOutput(int identifier, float maxPower = 1023);
    void pwmWrite(float power);
    float power();
    ~PwmGpioOutput();
protected:
    int currentPower;
    float maxPower;
private:
    void applyCurrentPower();
};

#endif /* PwmGpioOutput_hpp */
