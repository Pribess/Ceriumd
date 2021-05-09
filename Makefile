#Copyright (c) 2021 Heewon Cho 

CC=g++
TARGET=Ceriumd
CXXFLAGS=-lcrypto -Wno-deprecated-declarations -o
COMPILE_FLAGS=-std=c++17 

RM=rm
ECHO=echo

SRC_PATH=src/

ECHO_FLAGS=[Ceriumd]

CFILES=src/Ceriumd.cpp src/crypto/Crypto.cpp

${TARGET}: ${CFILES}
	@${ECHO} ${ECHO_FLAGS} ${CC} ${CFILES} ${CXXFLAGS} ${TARGET}
	@${CC} ${CFILES} ${CXXFLAGS} ${TARGET}
 



.PHONY: install

install:
	@${ECHO} install

.PHONY: clean

clean:
	@${ECHO} ${ECHO_FLAGS} Cleaning...
	@${RM} -f ${TARGET}
