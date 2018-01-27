//
//  AbstractMessage.hpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef AbstractMessage_hpp
#define AbstractMessage_hpp


class AbstractMessage{
public:
    virtual void send() = 0;
    virtual ~AbstractMessage(){};
};

#endif /* AbstractMessage_hpp */
