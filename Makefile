#Copyright (c) 2021 Heewon Cho 

CC=g++
TARGET=Ceriumd
CXXFLAGS=-lcrypto -o
COMPILE_FLAGS=-std=c++17 

SRC_PATH=src/

ECHO_FLAGS=[Ceriumd]

CFILES=src/Ceriumd.cpp src/crypto/Crypto.cpp

${TARGET}: ${CFILES}
	@${CC} ${CFILES} ${CXXFLAGS} ${TARGET}
	@echo ${ECHO_FLAGS} ${CC} ${CFILES} ${CXXFLAGS} ${TARGET}
 
.PHONY: clean install

install:
	@echo install

clean:
	@echo ${ECHO_FLAGS} Cleaning...
	@rm -f ${TARGET}