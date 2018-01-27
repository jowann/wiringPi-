build/src/Gpio.o .deps/src/Gpio.d: src/Gpio.cpp include/Gpio.hpp
-.deps/src/Gpio.d: | 
src/Gpio_EDGES =$(eval src/Gpio_EDGES:=build/src/Gpio.o )$(src/Gpio_EDGES)
src/Gpio_OBJS =$(eval RET:=)$(eval src/Gpio_OBJS:=$(call expand_deps,src/Gpio_EDGES)$(RET))$(src/Gpio_OBJS)
