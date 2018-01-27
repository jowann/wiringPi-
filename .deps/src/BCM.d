build/src/BCM.o .deps/src/BCM.d: src/BCM.cpp include/BCM.hpp
-.deps/src/BCM.d: | 
src/BCM_EDGES =$(eval src/BCM_EDGES:=build/src/BCM.o )$(src/BCM_EDGES)
src/BCM_OBJS =$(eval RET:=)$(eval src/BCM_OBJS:=$(call expand_deps,src/BCM_EDGES)$(RET))$(src/BCM_OBJS)
