//
//  ReaderT.hpp
//  test
//
//  Created by johann Vandromme on 29/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef ReaderT_hpp
#define ReaderT_hpp

template <typename T>
class ReaderT{
public:
    virtual T read() = 0;
};

#endif /* ReaderT_hpp */
