########VALS#############
CC     = g++
CFLAGS = -Wall -Werror -Wno-unused-variable -std=c++20
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

all: rell resbt reser reclock

rell:
	$(RM) $(BIN)$(LL) 
	$(CC) $(D_SRC)$(SLL) $(CFLAGS) -o $(BIN)$(LL)

resbt:
	$(RM) $(D_DATA)size_dup.txt $(BIN)$(STBT)
	echo "Len Dup" >> $(D_DATA)size_dup.txt;
	$(CC) $(D_SRC)$(SSTBT) $(CFLAGS) -o $(BIN)$(STBT)

reser:
	$(RM) $(BIN)$(SER) $(D_DATA)$(B_SER)
	$(CC) $(D_SRC)$(SSER) -std=c++20 -o $(BIN)$(SER)

reclock:
	$(RM) $(BIN)clock
	$(CC) $(SCLOCK) $(CFLAGS) -lglut -lGLU -lGL -lglfw \
	-o $(BIN)clock

clean:
	$(RM) size_dup.txt $(BIN)$(STBT) $(BIN)$(LL) \
	$(BIN)$(SER) $(BIN)$(ROT) $(BIN)clock

re: clean rell resbt reser

.PHONY: some_file
