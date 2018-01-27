//
//  DigitalValueChangedListener.hpp
//  test
//
//  Created by johann Vandromme on 08/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef DigitalValueChangedListener_hpp
#define DigitalValueChangedListener_hpp

#include <ValueChangedListenerT.hpp>
#include <GpioValue.hpp>

class DigitalValueChangedListener:public ValueChangedListenerT<GpioValue>{
public:
    DigitalValueChangedListener(std::function<void(GpioValue)> callback, GpioValue initialValue = Low, Queue &queue = Queue::main()): ValueChangedListenerT<GpioValue>(callback, initialValue, queue){}
};


#endif /* DigitalValueChangedListener_hpp */
