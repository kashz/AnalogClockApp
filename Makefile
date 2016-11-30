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

CFILES=$(wildcard $(SRC_DIR)/*.c)
HEADERS=$(wildcard $(INC_DIR)/*.h)
SRCS=$(CFILES)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TARGET=$(BIN_DIR)/app.exe
ICON=$(MEDIA_DIR)/icon.ico
ICON_OBJ=$(OBJ_DIR)/icon.o

CC = gcc
CCFLAGS = -Wall -I/usr/include/opengl
LD = gcc
LDFLAGS =
LIBS = -lm -lglpng -lglut32 -lglu32 -lopengl32

$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) -o $@ -c $<

$(OBJS) : $(HEADERS) Makefile

$(ICON_OBJ) : $(ICON)
	windres -i icon.rc -o $(ICON_OBJ)

all: clean $(TARGET)

clean :
	rm -f $(TARGET) $(OBJS) core *-
