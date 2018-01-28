//
//  test.cpp
//  test
//
//  Created by johann Vandromme on 22/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

//#include "test.hpp"

//
//  test.c
//  test
//
//  Created by johann Vandromme on 17/11/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <wiringPiSPI.h>


//#include <iostream>
#include "Lcd1602Controller.hpp"
#include "Queue.hpp"
#include "GPIOInputController.hpp"
#include <wiringPiI2C.h>
#include "DigitalValueChangedListener.hpp"
#include "SpiChannelController.hpp"
#include "Mcp300XChannelController.hpp"
#include "AnalogValueChangedListener.hpp"
#include <iostream>
#include "wiringPi++.hpp"
#include "Mcp3008.hpp"
#define  ButtonPin   0





#define CHAN_CONFIG_SINGLE  8
#define CHAN_CONFIG_DIFF    0


bool finished = false;

void onFinished( int )
{
    
    finished = true;
    Queue::main().stop();
    
}

void onchange(float value, ReaderT<float>& channel){
    printf("valueChanged %f\n", value);
};




int main(int argc, char **argv){
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = onFinished;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    
    sigaction(SIGINT, &sigIntHandler, NULL);
    
    //GpioOutput gpIO17 = GpioOutput(GPIO17);
    //GpioOutput gpIO17 = Gpio40Pins::Instance().gpioOutput(GPIO_17);
    //GpioOutput *gpIO17Ptr = new GpioOutput(GPIO17);
    //GpioOutput &gpIO17 = *gpIO17Ptr;
    //GpioOutput gpIO17 =  GpioOutput(GPIO17);
    //pinMode(GPIO17,OUTPUT);
    
    AsyncQueue spiQueue(5000);
    Gpio40Pins &board = Gpio40Pins::Instance();
    SpiChannel &channel = board.spiChannel(Channel0);
    SpiChannelController spicontroller(Channel0, board, spiQueue);
    Mcp3008 mcp3008(channel);
    Mcp300XChannel &channel1 = mcp3008.mcp3008Channel(Mcp3008_Channel1);
    Mcp300XChannelController mcpChannelController(channel1,spiQueue);
    
    
    AnalogValueChangedListener *avcl = new AnalogValueChangedListener([&spiQueue](float newValue) {
        
        printf("\n\n- %f %d - \n\n", newValue, spiQueue.getId() == std::this_thread::get_id());
    });
    mcpChannelController.addEventListerner(avcl);
    
    
    //GpioOutput *gpioOutput = board2->gpioOutput(GPIO_18);
    //PwmGpioOutput &pwm = board.pwmGpio18Output(1);
    GpioOutput &output = board.gpioOutput(GPIO_17);
   // GpioInput &input = board.gpioInput(GPIO_17, PullUp);
    //output.digitalWrite(High);
    MainQueue &mainQueue = Queue::main();
    // ATTENTION !!
    //AnalogValueChangedListener *valueChangedListener = new AnalogValueChangedListener(10);
    // ATTENTION !!
    //EventListener eventListener(channel1, mainQueue, mainQueue);
    //eventListener.addListener(valueChangedListener);
    //valueChangedListener->callback = onchange;
    
    //Lcd1602Controller lcd(board.i2c(), 0x3f);
    
    GpioInput &tiltInput = board.gpioInput(GPIO_05, PullDown);
    
    AsyncQueue tiltQueue;
    GPIOInputController controller(tiltInput, tiltQueue);
    //std::function<void(GpioValue)> f_display =
    DigitalValueChangedListener *dvcl = new DigitalValueChangedListener([&tiltQueue](GpioValue newValue) {
        std::cout << tiltQueue.getId();
        //std::cout << std::this_thread::get_id();
        printf("\n\n%d\n\n", tiltQueue.getId() == std::this_thread::get_id());
    }, Low, tiltQueue);
    controller.addEventListerner(dvcl);
    std::cout << std::this_thread::get_id();
    
    //AsyncQueue lcdQueue(5000);
    
    //lcd.write(0, 0, "coucou");
    /*
    Queue::main().idle = [&tiltInput](){
        printf("%d\n", tiltInput.digitalRead());
        delay(200);
    };
    */
    tiltQueue.start();
    spiQueue.start();
    
    
    Queue::main().start();

    while(!finished){
        
        delay(751);
    }
    return 0;
}
