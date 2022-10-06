########VALS#############
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++20
BIN    = bin/
D_SRC  = cpp_src/
D_DATA = data/
#########################
STBT  = st_bt
SSTBT = $(STBT).cpp
LL    = linked_list
SLL   = $(LL).cpp
SER   = serealization
SSER  = $(SER).cpp
#########################
B_SER = data.dat
#########################

all: clean rell resbt reser

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

clean:
	$(RM) size_dup.txt $(BIN)$(STBT) $(BIN)$(LL) $(BIN)$(SER)

re: clean rell resbt

.PHONY: some_file
