CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++20
TARGET = ts
SRC = tst
SRC_CPP = $(SRC).cpp
O_DIR = obj_dir/
O_CPP = $(SRC).o
DUPSCPP = dups.cpp
BITREE = gen_bi_tree

all: $(TARGET)

$(TARGET): 
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

mw: clean
	$(CC) $(SRC_CPP) -o $(TARGET)

mo: clean
	$(CC) -c $(SRC_CPP) -o $(O_DIR)$(O_CPP)

bi:
	$(RM) size_dup.txt
	echo "Len Dup" >> size_dup.txt;
	$(CC) $(DUPSCPP) $(CFLAGS) -o $(BITREE)

clean:
	$(RM) $(TARGET) $(O_CPP)

oclean:
	$(RM) $(O_DIR)$(O_CPP)

re: clean
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

aclean: clean oclean

.PHONY: some_file
