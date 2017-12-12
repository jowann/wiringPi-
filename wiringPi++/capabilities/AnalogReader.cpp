//
//  AnalogReader.cpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "AnalogReader.hpp"

AnalogReader::AnalogReader(float maxValue):maxValue(maxValue){}

float AnalogReader::read(){
    return normalized(_read(), maxValue);
}

float AnalogReader::normalized(float value, float maxValue){
    if (maxValue == _maxValue()){
        return value;
    }
    return (value / _maxValue()) * maxValue;
}