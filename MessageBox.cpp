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
    mutex.lock();
    for (AbstractMessage *message : messages){
        message->send();
        delete message;
    }
    messages.clear();
    mutex.unlock();
}