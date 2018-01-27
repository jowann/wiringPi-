build/src/PwmGpioOutput.o .deps/src/PwmGpioOutput.d: \
 src/PwmGpioOutput.cpp include/PwmGpioOutput.hpp include/Gpio.hpp
-.deps/src/PwmGpioOutput.d: | .deps/src/Gpio.d
src/PwmGpioOutput_EDGES =$(eval src/PwmGpioOutput_EDGES:=build/src/PwmGpioOutput.o src/Gpio_EDGES)$(src/PwmGpioOutput_EDGES)
src/PwmGpioOutput_OBJS =$(eval RET:=)$(eval src/PwmGpioOutput_OBJS:=$(call expand_deps,src/PwmGpioOutput_EDGES)$(RET))$(src/PwmGpioOutput_OBJS)
