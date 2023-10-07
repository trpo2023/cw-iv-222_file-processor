CC = gcc
CFLAGS = -Wall -Wextra -Werror
CTESTFLAGS = -I thirdparty/ -I src/
TARGET = ./bin/main
TESTTARGET = ./bin/test

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(TARGET)

test: $(TESTTARGET)
	$(TESTTARGET)

$(TESTTARGET): thirdparty/ctest.h test/module.c test/tests.c src/fileprocessor.c
	$(CC) $(CFLAGS) $(CTESTFLAGS) test/module.c test/tests.c src/fileprocessor.c -o $(TESTTARGET)
	

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ_DIR)*.o

fclean: clean
	rm $(TARGET)

.PHONY: all clean fclean
