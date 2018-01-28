//
//  AnalogValueCahngedListener2.hpp
//  test
//
//  Created by johann Vandromme on 17/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef AnalogValueChangedListener_hpp
#define AnalogValueChangedListener_hpp

#include "ValueChangedListenerT.hpp"
#include <mutex>

class AnalogValueChangedListener:public ValueChangedListenerT<float>{
public:
    AnalogValueChangedListener(std::function<void(float)> callback, float initialValue = 0, Queue &queue = Queue::main()): ValueChangedListenerT<float>(callback, initialValue, queue){}
};

#endif /* AnalogValueCahngedListener2_hpp */
