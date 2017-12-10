//
//  OnValueChangedListener.hpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef OnValueChangedListener_hpp
#define OnValueChangedListener_hpp

#include <AnalogReader.hpp>
#include <thread>

class OnValueChangedListener{
private:
    float lastValue = -1;
    AnalogReader &reader;
    bool isFinished;
    std::thread athread;
    void loop();
public:
    OnValueChangedListener(AnalogReader &reader);
    void start();
    void stop();
    std::function<void(float)> callback;
    
};
#endif /* OnValueChangedListener_hpp */
