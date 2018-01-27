build/src/GpioInput.o .deps/src/GpioInput.d: src/GpioInput.cpp \
 include/GpioInput.hpp include/Gpio.hpp include/GpioValue.hpp
-.deps/src/GpioInput.d: | .deps/src/Gpio.d
src/GpioInput_EDGES =$(eval src/GpioInput_EDGES:=build/src/GpioInput.o src/Gpio_EDGES)$(src/GpioInput_EDGES)
src/GpioInput_OBJS =$(eval RET:=)$(eval src/GpioInput_OBJS:=$(call expand_deps,src/GpioInput_EDGES)$(RET))$(src/GpioInput_OBJS)
