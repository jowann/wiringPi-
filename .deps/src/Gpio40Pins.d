build/src/Gpio40Pins.o .deps/src/Gpio40Pins.d: src/Gpio40Pins.cpp \
 include/Gpio40Pins.hpp include/Gpio.hpp include/GpioOutput.hpp \
 include/BCM.hpp include/GpioValue.hpp include/GenGPIOMode.hpp \
 include/GpioInput.hpp include/PwmGpioOutput.hpp include/SpiChannel.hpp \
 include/SpiChannelId.hpp include/I2C.hpp include/I2COutput.hpp \
 include/I2C.hpp
-.deps/src/Gpio40Pins.d: | .deps/src/BCM.d .deps/src/I2C.d .deps/src/I2COutput.d .deps/src/GpioInput.d .deps/src/SpiChannelId.d .deps/src/SpiChannel.d .deps/src/GenGPIOMode.d .deps/src/Gpio.d .deps/src/PwmGpioOutput.d .deps/src/GpioOutput.d
src/Gpio40Pins_EDGES =$(eval src/Gpio40Pins_EDGES:=build/src/Gpio40Pins.o src/BCM_EDGES src/I2C_EDGES src/I2COutput_EDGES src/GpioInput_EDGES src/SpiChannelId_EDGES src/SpiChannel_EDGES src/GenGPIOMode_EDGES src/Gpio_EDGES src/PwmGpioOutput_EDGES src/GpioOutput_EDGES)$(src/Gpio40Pins_EDGES)
src/Gpio40Pins_OBJS =$(eval RET:=)$(eval src/Gpio40Pins_OBJS:=$(call expand_deps,src/Gpio40Pins_EDGES)$(RET))$(src/Gpio40Pins_OBJS)
