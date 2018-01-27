build/src/wiringPi++.o .deps/src/wiringPi++.d: src/wiringPi++.cpp \
 include/wiringPi++.hpp include/BCM.hpp include/Gpio.hpp \
 include/GpioValue.hpp include/GpioOutput.hpp include/GenGPIOMode.hpp \
 include/Gpio40Pins.hpp include/GpioInput.hpp include/PwmGpioOutput.hpp \
 include/SpiChannel.hpp include/SpiChannelId.hpp include/I2C.hpp \
 include/I2COutput.hpp
-.deps/src/wiringPi++.d: | .deps/src/BCM.d .deps/src/I2C.d .deps/src/I2COutput.d .deps/src/GpioInput.d .deps/src/SpiChannelId.d .deps/src/SpiChannel.d .deps/src/Gpio40Pins.d .deps/src/GenGPIOMode.d .deps/src/Gpio.d .deps/src/PwmGpioOutput.d .deps/src/GpioOutput.d
src/wiringPi++_EDGES =$(eval src/wiringPi++_EDGES:=build/src/wiringPi++.o src/BCM_EDGES src/I2C_EDGES src/I2COutput_EDGES src/GpioInput_EDGES src/SpiChannelId_EDGES src/SpiChannel_EDGES src/Gpio40Pins_EDGES src/GenGPIOMode_EDGES src/Gpio_EDGES src/PwmGpioOutput_EDGES src/GpioOutput_EDGES)$(src/wiringPi++_EDGES)
src/wiringPi++_OBJS =$(eval RET:=)$(eval src/wiringPi++_OBJS:=$(call expand_deps,src/wiringPi++_EDGES)$(RET))$(src/wiringPi++_OBJS)
