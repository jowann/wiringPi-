//
//  AsyncAnalogValueChangedListener.hpp
//  test
//
//  Created by johann Vandromme on 10/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef AsyncAnalogValueChangedListener_hpp
#define AsyncAnalogValueChangedListener_hpp

#include <AnalogValueChangedListener.hpp>
#include <thread>

class AsyncAnalogValueChangedListener{
private:
    AnalogValueChangedListener listener;
    std::thread athread;
    void loop();
public:
    AsyncAnalogValueChangedListener(AnalogReader &reader);
    void start();
    void stop();
    std::function<void(float)> callback;
    void onValueChanged(AnalogReader&, float);
};

#endif /* AsyncAnalogValueChangedListener_hpp */
