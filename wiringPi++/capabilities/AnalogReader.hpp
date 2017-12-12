//
//  AnalogReader.hpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef AnalogReader_hpp
#define AnalogReader_hpp

class AnalogReader{
public:
    AnalogReader(float maxValue = 1023);
    float read();
protected:
    virtual float _read() = 0;
    virtual float _maxValue() = 0;

private:
    float maxValue;
    float normalized(float value, float maxValue);
};

#endif /* AnalogReader_hpp */
