# wiringPi ++

## What is wiringPi++
Wiring Pi ++ is not only a C++ version of wiringPi.
This (currently beta) library aims are :
- make a c++ version of c library wiringPi
- add easy to use electronic devices drivers 
- allow use of events by using c++ sd::function
- allow easy multi threading.

## A c++ version of wiringPi

An object oriented and strongly typed version of the imperative c library can help developper to make less errors.

## Add a notion of driver

Drivers can be helpfull for dealing with IIC or Spi GPIOs, given that each hardware uses its own communication protocol.

## Event based code

Event based code can be easyer to create and to maintain

## Multi threading

Multi threading is mostly dangerous and hard to maintain.
WiringPi++ aim is to be easy to use, safe and unvisibly multi threaded based.
