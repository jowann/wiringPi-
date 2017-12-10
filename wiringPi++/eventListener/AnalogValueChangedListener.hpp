//
//  AnalogValueChangedListener.hpp
//  test
//
//  Created by johann Vandromme on 09/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef AnalogValueChangedListener_hpp
#define AnalogValueChangedListener_hpp

#include <AnalogReader.hpp>
#include <thread>
#include <mutex>


class AnalogValueChangedListener{
private:
    float lastValue = -1;
    AnalogReader &reader;
    std::mutex mutex;
public:
    AnalogValueChangedListener(AnalogReader &reader);
    std::function<void(AnalogReader &, float)> callback;
    void listen();
};
#endif /* AnalogValueChangedListener_hpp */
