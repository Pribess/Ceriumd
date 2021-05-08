#Copyright (c) 2021 Heewon Cho 

CC=g++
TARGET=Ceriumd
CXXFLAGS=-lcrypto -Wno-deprecated-declarations -o
COMPILE_FLAGS=-std=c++17 

SRC_PATH=src/

ECHO_FLAGS=[Ceriumd]

CFILES=src/Ceriumd.cpp src/crypto/Crypto.cpp

${TARGET}: ${CFILES}
	@echo ${ECHO_FLAGS} ${CC} ${CFILES} ${CXXFLAGS} ${TARGET}
	@${CC} ${CFILES} ${CXXFLAGS} ${TARGET}
 
.PHONY: clean install

install:
	@echo install

clean:
	@echo ${ECHO_FLAGS} Cleaning...
	@rm -f ${TARGET}
