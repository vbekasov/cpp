#########OS##############
ifeq ($(OS), Linux)
	SIS    = Linux
	CFLAGS = -Wall -Werror -Wno-unused-variable -std=c++20
else
	SIS    = Mac
	CFLAGS = -std=c++20
endif
########VALS#############
CC     = g++

OGLLIB   = -lglut -lGLU -lGL -lglfw #OpenGL libs
BIN    = bin/
D_SRC  = cpp_src/
D_DATA = data/
#########################
STBT   = st_bt
SSTBT  = $(STBT).cpp
LL     = linked_list
SLL    = $(LL).cpp
SER    = serealization
SSER   = $(SER).cpp
SCLOCK = openGL/main.cpp
#########################
B_SER = data.dat
#########################

all: os_info rell resbt reser reclock

rell: os_info
	$(RM) $(BIN)$(LL) 
	$(CC) $(D_SRC)$(SLL) $(CFLAGS) -o $(BIN)$(LL)

resbt: os_info
	$(RM) $(D_DATA)size_dup.txt $(BIN)$(STBT)
	echo "Len Dup" >> $(D_DATA)size_dup.txt;
	$(CC) $(D_SRC)$(SSTBT) $(CFLAGS) -o $(BIN)$(STBT)

reser: os_info
	$(RM) $(BIN)$(SER) $(D_DATA)$(B_SER)
	$(CC) $(D_SRC)$(SSER) $(CFLAGS) -o $(BIN)$(SER)

reclock: os_info
	$(RM) $(BIN)clock
	$(CC) $(SCLOCK) $(CFLAGS)  $(OGLLIB) \
		-o $(BIN)clock

clean:
	$(RM) size_dup.txt $(BIN)$(STBT) $(BIN)$(LL) \
	$(BIN)$(SER) $(BIN)$(ROT) $(BIN)clock

os_info:
	$(info OS = ${SIS})

re: clean rell resbt reser

.PHONY: some_file
