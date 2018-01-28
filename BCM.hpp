//
//  BCM.hpp
//  test
//
//  Created by johann Vandromme on 24/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef BCM_hpp
#define BCM_hpp

#include <stdio.h>

typedef enum WiringPiToBCM_GenGPIO_enum{
    GPIO_04 = 7,
    GPIO_05 = 21,
    GPIO_06 = 22,
    GPIO_12 = 26,
    GPIO_13 = 23,
    GPIO_16 = 27,
    GPIO_17 = 0,
    GPIO_18 = 1,
    GPIO_19 = 24,
    GPIO_20 = 28,
    GPIO_21 = 29,
    GPIO_22 = 3,
    GPIO_23 = 4,
    GPIO_24 = 5,
    GPIO_25 = 6,
    GPIO_26 = 25,
    GPIO_27 = 2
} BCM;

typedef enum Hardware_PWM_enum{
    PWM_GPIO_18 = GPIO_18
}PWM;

#endif /* BCM_hpp */
