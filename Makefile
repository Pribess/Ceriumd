#Copyright (c) 2021 Heewon Cho 

CC=g++
TARGET=Ceriumd
CXXFLAGS=-o
COMPILE_FLAGS=-std=c++17

SRC_PATH=src/

CFILES=${SRC_PATH}Ceriumd.cpp

${TARGET}: ${CFILES}
	${CC} ${CFILES} ${CXXFLAGS} ${TARGET}

.PHONY: clean install

install:
	@echo install

clean:
	@echo Cleaning...
	@rm -f ${TARGET}