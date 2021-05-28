#Copyright (c) 2021 Heewon Cho

CC:=g++
TARGET=Ceriumd
INCFLAGS:=-I ${shell pwd}/src
CXXFLAGSC:=-Wno-deprecated-declarations -c ${INCFLAGS}
CXXFLAGSO:=-lcrypto
COMPILE_FLAGS:=-std=c++17

RM:=rm
ECHO=echo ${ECHO_FLAGS}
MAKE:=make
SH:=sh

SRC_PATH:=src
SRC_EXT:=cpp

ECHO_FLAGS:=[Ceriumd]

SOURCES:=${shell find ${SRC_PATH} -name "*.${SRC_EXT}" | tr -d "\n" | sed "s/.cpp/.cpp /g"}
OBJECTS:=${shell find ${SRC_PATH} -name "*.${SRC_EXT}" | rev | cut -f 1 -d "/" | rev | tr -d "\n" | sed "s/.cpp/.o /g"}


${TARGET}: ${OBJECTS}
	@${ECHO} "Linking... *.o -> TARGET"
	@${CC} ${OBJECTS} ${CXXFLAGSO} -o ${TARGET}
	@${ECHO} "Clearing Object Files..."
	@${RM} *.o

${OBJECTS}: ${SOURCES}
	@${ECHO} "Amount of Source Files to Compile : ${words $^}"
	@for var in $^ ; do ${ECHO} "Compiling... $$var -> " | tr -d "\n" && echo "$$var" | rev | cut -f 1 -d "/" | rev | sed "s/.cpp/.o/g" && ${CC} ${CXXFLAGSC} $$var; done


.PHONY: install

install:
	@${ECHO} install

.PHONY: clean

clean:
	@${ECHO} "Cleaning..."
	@${RM} -f ${TARGET} ${OBJECTS}

.PHONY: run

run:
	@${MAKE}
	@${SH} -c "./${TARGET}"