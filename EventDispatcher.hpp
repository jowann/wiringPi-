//
//  EventDispatcher.hpp
//  test
//
//  Created by johann Vandromme on 01/01/2018.
//  Copyright © 2018 Ineat-conseil. All rights reserved.
//

#ifndef EventDispatcher_hpp
#define EventDispatcher_hpp

class EventDispatcher{
public:
    virtual void readAndDispatch() = 0;
    virtual ~EventDispatcher(){}
};



#endif /* EventDispatcher_hpp */
