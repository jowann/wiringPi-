build/src/GenGPIOMode.o .deps/src/GenGPIOMode.d: src/GenGPIOMode.cpp \
 include/GenGPIOMode.hpp
-.deps/src/GenGPIOMode.d: | 
src/GenGPIOMode_EDGES =$(eval src/GenGPIOMode_EDGES:=build/src/GenGPIOMode.o )$(src/GenGPIOMode_EDGES)
src/GenGPIOMode_OBJS =$(eval RET:=)$(eval src/GenGPIOMode_OBJS:=$(call expand_deps,src/GenGPIOMode_EDGES)$(RET))$(src/GenGPIOMode_OBJS)
