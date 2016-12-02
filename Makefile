#
# Makefile
# Auther: kash
#

SRC_DIR=./src
INC_DIR=./include
BIN_DIR=./bin
OBJ_DIR=./obj
MEDIA_DIR=./media

TEST_DIR=./test

UNAME_S := $(shell uname -s)

CFILES=$(wildcard $(SRC_DIR)/*.c)
HEADERS=$(wildcard $(INC_DIR)/*.h)
SRCS=$(CFILES)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

ifeq ($(OS),Windows_NT)
endif

CC = gcc
CCFLAGS = -Wall -I/usr/include/opengl
CCFLAGS_MAC = -Wall -Wno-deprecated
LD = gcc
LDFLAGS =
LIBS = -lm -lglpng -lglut32 -lglu32 -lopengl32
LIBS_MAC = -framework GLUT -framework OpenGL

ifeq ($(OS),Windows_NT)
TARGET=$(BIN_DIR)/app.exe
ICON=$(MEDIA_DIR)/icon.ico
ICON_OBJ=$(OBJ_DIR)/icon.o

$(TARGET): $(OBJS) $(ICON_OBJ)
	$(LD) $(OBJS) $(ICON_OBJ) $(LDFLAGS) -o $(TARGET) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) -o $@ -c $<

$(ICON_OBJ) : $(ICON)
	windres -i icon.rc -o $(ICON_OBJ)
endif


ifeq ($(UNAME_S),Darwin)
TARGET = $(BIN_DIR)/app

$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBS_MAC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS_MAC) -o $@ -c $<
endif

$(OBJS) : $(HEADERS) Makefile

all: clean $(TARGET)

clean :
	rm -f $(TARGET) $(OBJS) $(ICON_OBJ) core *-
