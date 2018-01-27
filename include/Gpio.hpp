

#ifndef GPIO_hpp
#define GPIO_hpp

class Gpio{
public:
    virtual ~Gpio(){};
protected:
    Gpio(int identifier):_id(identifier){};
    int _id;
};

#endif