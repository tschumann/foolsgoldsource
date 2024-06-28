CPP = g++
CPPFLAGS = -std=c++14 -march=core2 -mfpmath=sse \
		-Wall -Wextra -Wno-unused-parameter -Wno-unknown-pragmas \
		-I./hlsdk -I./hlsdk/steam -DCLIENT_DLL

# include the parent directory in the build
VPATH=..

ALL: foolsgoldsource

FOOLSGOLDSOURCE_OBJ = main.o foolsgoldsource.o vgui.o

# links the objects
DO_BUILD = ${CPP} -g -o foolsgoldsource ${FOOLSGOLDSOURCE_OBJ} -lstdc++

foolsgoldsource:CPPFLAGS += -g -O3
foolsgoldsource: ${FOOLSGOLDSOURCE_OBJ}
	${DO_BUILD}

clean:
	-rm -f *.o
	-rm -f foolsgoldsource

%.o:    %.cpp
	${CPP} ${CPPFLAGS} -c $< -o $@

%.o:    %.c
	${CPP} ${CPPFLAGS} -c $< -o $@

