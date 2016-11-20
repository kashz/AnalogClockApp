#
# Makefile
# Auther: kash
#

SRC_DIR=./src
INC_DIR=./include
BIN_DIR=./bin
OBJ_DIR=./obj

TEST_DIR=./test
GTEST_DIR=../extsrc/googletest/googletest

CFILES=$(wildcard $(SRC_DIR)/*.c)
HEADERS=$(wildcard $(INC_DIR)/*.h)
SRCS=$(CFILES)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TARGET=$(BIN_DIR)/app.exe

CC = gcc
CCFLAGS = -Wall -I/usr/include/opengl
LD = gcc
LDFLAGS =
LIBS = -lm

$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) -o $@ -c $<

$(OBJS) : $(HEADERS) Makefile

all: clean $(TARGET)

clean :
	rm -f $(TARGET) $(OBJS) core *-
