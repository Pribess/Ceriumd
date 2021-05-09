#Copyright (c) 2021 Heewon Cho 

CC=g++
TARGET=Ceriumd
CXXFLAGSC=-Wunused-command-line-argument -Wno-deprecated-declarations -c
CXXFLAGSO=-lcrypto
COMPILE_FLAGS=-std=c++17 

RM=rm
ECHO=echo

SRC_PATH=src
SRC_EXT=cpp

ECHO_FLAGS=[Ceriumd]

SOURCES:=${shell find ${SRC_PATH} -name "*.${SRC_EXT}"}
OBJECTS=*.o

${TARGET}: ${OBJECTS}
	@${ECHO} "${ECHO_FLAGS} Linking... *.o -> TARGET"
	@${CC} ${OBJECTS} ${CXXFLAGSO} -o ${TARGET}

${OBJECTS}: ${SOURCES}
	@${ECHO} "${ECHO_FLAGS} Compiling... $@"
	@${CC} ${CXXFLAGSC} $< -o $@

.PHONY: install

install:
	@${ECHO} install

.PHONY: clean

clean:
	@${ECHO} ${ECHO_FLAGS} Cleaning...
	@${RM} -f ${TARGET} ${OBJECTS}
