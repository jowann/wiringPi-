build/src/SpiChannel.o .deps/src/SpiChannel.d: src/SpiChannel.cpp \
 include/SpiChannel.hpp include/SpiChannelId.hpp
-.deps/src/SpiChannel.d: | .deps/src/SpiChannelId.d
src/SpiChannel_EDGES =$(eval src/SpiChannel_EDGES:=build/src/SpiChannel.o src/SpiChannelId_EDGES)$(src/SpiChannel_EDGES)
src/SpiChannel_OBJS =$(eval RET:=)$(eval src/SpiChannel_OBJS:=$(call expand_deps,src/SpiChannel_EDGES)$(RET))$(src/SpiChannel_OBJS)
