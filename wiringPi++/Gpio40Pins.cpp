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

Gpio40Pins *Gpio40Pins::_instance;


Gpio40Pins::Gpio40Pins(){
    if(wiringPiSetup()== -1){
        printf("Setup wiringPi Failed!");
        exit(-1);
    }
    for (int i = 0; i<Gpio40Number; i++){
        allGPIOs[i] = 0;
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

Gpio40Pins::~Gpio40Pins(){
    for (int i = 0; i< Gpio40Number; ++i){
        delete allGPIOs[i];
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


