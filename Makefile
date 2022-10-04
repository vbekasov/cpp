########VALS############
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++20
BT = struct_bt
LIST = l_list
BIN = bin/
T_SRC = cpp_src/
SBT = st_dups.cpp
LSRC = linked_list.cpp
#########################

all: $(TARGET)

$(TARGET): 
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

rell:
	$(RM) $(BIN)$(LIST) 
	$(CC) $(T_SRC)$(LSRC) $(CFLAGS) -o $(BIN)$(LIST)

resbt:
	$(RM) size_dup.txt $(BIN)$(BT)
	echo "Len Dup" >> size_dup.txt;
	$(CC) $(T_SRC)$(SBT) $(CFLAGS) -o $(BIN)$(BT)

clean:
	$(RM) $(BIN)$(BT) $(BIN)$(LIST)

re: clean

.PHONY: some_file