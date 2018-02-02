//
//  AnalogWorthyValueChangedListener.hpp
//  wiringPi4CPP
//
//  Created by johann Vandromme on 02/02/2018.
//  Copyright © 2018 Johann Vandromme. All rights reserved.
//

#ifndef WorthyValueChangedListener_hpp
#define WorthyValueChangedListener_hpp

#include <AnalogValueChangedListener.hpp>
#include <functional>
#include <cmath>

class WorthyValueChangedListener:public AnalogValueChangedListener{
private:
    float delta;
public:
    WorthyValueChangedListener(std::function<void(float)> callback, float delta, float initialValue = 0, Queue &queue = Queue::main()): AnalogValueChangedListener(callback, initialValue, queue), delta(delta){};
    
    virtual AbstractMessage *valueRead(float value){
        AbstractMessage *message = 0;
        float currentDelta = std::abs (value - oldValue);
        if (currentDelta >= delta){
            message = new MessageT<float>(callback, oldValue);
            oldValue = value;
        }
        
        return message;
    }
    
};

#endif /* AnalogWorthyValueChangedListener_hpp */
