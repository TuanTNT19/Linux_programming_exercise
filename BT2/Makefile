
CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
LIB_DIR := $(CUR_DIR)/lib
OBJ_DIR := $(CUR_DIR)/obj
SRC_DIR := $(CUR_DIR)/src
BIN_DIR := $(CUR_DIR)/bin
STA_DIR := $(LIB_DIR)/static
CC := gcc
INC_FLAG := -I $(INC_DIR)
LIB_NAME := name
mk_objs:
	$(CC) -c $(SRC_DIR)/hello2.c -o $(OBJ_DIR)/hello2.o $(INC_FLAG)
	$(CC) -c $(SRC_DIR)/hello1.c -o $(OBJ_DIR)/hello1.o $(INC_FLAG)
	$(CC) -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o $(INC_FLAG)
mk_static:
	ar src $(STA_DIR)/lib$(LIB_NAME).a $(OBJ_DIR)/hello2.o $(OBJ_DIR)/hello1.o
all: mk_objs mk_static
	gcc $(OBJ_DIR)/main.o -L$(STA_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/runfile
clean:
	rm -rf bin/*
	rm -rf obj/*
	rm -rf lib/static/*







