//
//  MessageBox.cpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#include "MessageBox.hpp"


void MessageBox::addMessage(AbstractMessage *message){
    mutex.lock();
    messages.push_back(message);
    mutex.unlock();
}
void MessageBox::sendMessages(){
    if (!messages.empty()){
        mutex.lock();
        AbstractMessage *message = messages.front();
        messages.pop_front();
        mutex.unlock();
        
        message->send();
        delete message;
    }
    
}