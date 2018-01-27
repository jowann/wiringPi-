build/src/SpiChannelId.o .deps/src/SpiChannelId.d: src/SpiChannelId.cpp \
 include/SpiChannelId.hpp
-.deps/src/SpiChannelId.d: | 
src/SpiChannelId_EDGES =$(eval src/SpiChannelId_EDGES:=build/src/SpiChannelId.o )$(src/SpiChannelId_EDGES)
src/SpiChannelId_OBJS =$(eval RET:=)$(eval src/SpiChannelId_OBJS:=$(call expand_deps,src/SpiChannelId_EDGES)$(RET))$(src/SpiChannelId_OBJS)
