//
//  AnalogValueCahngedListener2.hpp
//  test
//
//  Created by johann Vandromme on 17/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef AnalogValueChangedListener2_hpp
#define AnalogValueChangedListener2_hpp

#include <ValueChangedListenerT.hpp>

class AnalogValueChangedListener2:public ValueChangedListenerT<float>{
public:
    AnalogValueChangedListener2(std::function<void(float)> callback, float initialValue = 0, Queue &queue = Queue::main()): ValueChangedListenerT<float>(callback, initialValue, queue){}
};

#endif /* AnalogValueCahngedListener2_hpp */
