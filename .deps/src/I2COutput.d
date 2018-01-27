build/src/I2COutput.o .deps/src/I2COutput.d: src/I2COutput.cpp \
 include/I2COutput.hpp
-.deps/src/I2COutput.d: | 
src/I2COutput_EDGES =$(eval src/I2COutput_EDGES:=build/src/I2COutput.o )$(src/I2COutput_EDGES)
src/I2COutput_OBJS =$(eval RET:=)$(eval src/I2COutput_OBJS:=$(call expand_deps,src/I2COutput_EDGES)$(RET))$(src/I2COutput_OBJS)
