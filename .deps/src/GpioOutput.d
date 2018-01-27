build/src/GpioOutput.o .deps/src/GpioOutput.d: src/GpioOutput.cpp \
 include/GpioOutput.hpp include/BCM.hpp include/Gpio.hpp \
 include/GpioValue.hpp include/GenGPIOMode.hpp
-.deps/src/GpioOutput.d: | .deps/src/BCM.d .deps/src/GenGPIOMode.d .deps/src/Gpio.d
src/GpioOutput_EDGES =$(eval src/GpioOutput_EDGES:=build/src/GpioOutput.o src/BCM_EDGES src/GenGPIOMode_EDGES src/Gpio_EDGES)$(src/GpioOutput_EDGES)
src/GpioOutput_OBJS =$(eval RET:=)$(eval src/GpioOutput_OBJS:=$(call expand_deps,src/GpioOutput_EDGES)$(RET))$(src/GpioOutput_OBJS)
