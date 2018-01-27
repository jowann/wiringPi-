//
//  MessageBox.hpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef MessageBox_hpp
#define MessageBox_hpp

#include <vector>
#include <mutex>
#include "AbstractMessage.hpp"

class MessageBox{
private:
    std::mutex mutex;
    std::vector<AbstractMessage *> messages;
public:
    void addMessage(AbstractMessage *message);
    void sendMessages();
};

#endif /* MessageBox_hpp */
