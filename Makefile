CC = c++
CFLAGS = -Wall -Werror -Wextra
TARGET = ts
SRC = tst
SRC_CPP = $(SRC).cpp
O_DIR = obj_dir/
O_CPP = $(SRC).o

all: $(TARGET)

$(TARGET): 
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

mw: clean
	$(CC) $(SRC_CPP) -o $(TARGET)

mo: clean
	$(CC) -c $(SRC_CPP) -o $(O_DIR)$(O_CPP)

clean:
	$(RM) $(TARGET) $(O_CPP)

oclean:
	$(RM) $(O_DIR)$(O_CPP)

re: clean
	$(CC) $(SRC_CPP) $(CFLAGS) -o $(TARGET)

aclean: clean oclean

.PHONY: some_file
