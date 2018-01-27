build/src/I2C.o .deps/src/I2C.d: src/I2C.cpp include/I2C.hpp \
 include/I2COutput.hpp
-.deps/src/I2C.d: | .deps/src/I2COutput.d
src/I2C_EDGES =$(eval src/I2C_EDGES:=build/src/I2C.o src/I2COutput_EDGES)$(src/I2C_EDGES)
src/I2C_OBJS =$(eval RET:=)$(eval src/I2C_OBJS:=$(call expand_deps,src/I2C_EDGES)$(RET))$(src/I2C_OBJS)
