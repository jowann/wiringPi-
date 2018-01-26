LDFLAGS=-g
OPTFLAG=-O0
INCPATH=-IwiringPi++ -IwiringPi++/devices/ -IwiringPi++/capabilities/ -IwiringPi++/eventListener/ -IwiringPi++ -IwiringPi++/devices/Mcp300X/ -IwiringPi++/devices/Lcd1602/ -IwiringPi++/queue/ -IwiringPi++/boardControllers/

LDLIBS=-lwiringPi -lpthread



test: test.o wiringPipp. device. capabilities. eventListener.o Mcp300X.o Lcd1602.o queue.o boardControllers.
g++ $(LDFLAGS) -o test *.o $(LDLIBS)

test.o: test.cpp
g++ $(OPTFLAG) $(INCPATH) -c test.cpp

wiringPipp.: wiringPi++/*.cpp
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/*.cpp

boardControllers.: wiringPi++/boardControllers/*.cpp
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/boardControllers/*.cpp

device.:
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/devices/*.cpp

capabilities.:
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/capabilities/*.cpp

eventListener.o:
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/eventListener/*.cpp

Mcp300X.o:
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/devices/Mcp300X/*.cpp

Lcd1602.o:
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/devices/Lcd1602/*.cpp

queue.o:
g++ $(OPTFLAG)  $(INCPATH) -c wiringPi++/queue/*.cpp

clean:
rm *.o test
