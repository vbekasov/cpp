CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++20
TARGET = l_list
SRC = linked_list
SRC_CPP = $(SRC).cpp
O_DIR = obj_dir/
O_CPP = $(SRC).o
DUP_SRC = dups
DUP_CPP = $(DUP_SRC).cpp
BITREE = gen_bi_tree

all: $(TARGET)

$(TARGET): 
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

list: clean
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

olist: clean
	$(CC) -c $(SRC_CPP) -o $(O_DIR)$(O_CPP)

bi:
	$(RM) size_dup.txt
	echo "Len Dup" >> size_dup.txt;
	$(CC) $(DUP_CPP) $(CFLAGS) -o $(BITREE)

rebi:
	$(RM) size_dup.txt $(BITREE)
	echo "Len Dup" >> size_dup.txt;
	$(CC) $(DUP_CPP) $(CFLAGS) -o $(BITREE)

clean:
	$(RM) $(TARGET) $(O_DIR)$(O_CPP)

oclean:
	$(RM) $(O_DIR)$(O_CPP)

re: clean
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

aclean: clean oclean

.PHONY: some_file