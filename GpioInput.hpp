//
//  GpioInput.hpp
//  test
//
//  Created by johann Vandromme on 27/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef GpioInput_hpp
#define GpioInput_hpp

#include <wiringPi.h>
#include "Gpio.hpp"
#include "GpioValue.hpp"
#include <mutex>
#include "ReaderT.hpp"
typedef enum GpioInputReadingMode_enum{
    PullUp = PUD_UP,
    PullDown = PUD_DOWN
}GpioInputMode;


class GpioInput: public Gpio, public ReaderT<GpioValue>{
private:
    std::mutex mutex;
public:
    
    GpioInput(int identifier, GpioInputMode mode);
    
    GpioValue digitalRead();
    GpioValue read();
    ~GpioInput();
    
};

#endif /* GpioInput_hpp */
