//
//  GenGPIOMode.hpp
//  test
//
//  Created by johann Vandromme on 24/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef GenGPIOMode_hpp
#define GenGPIOMode_hpp

#include <wiringPi.h>

typedef enum GenGPIOMode_enum{
    Input = INPUT,
    Output = OUTPUT
}GenGPIOMode;

#endif /* GenGPIOMode_hpp */
