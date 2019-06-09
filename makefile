# Generic Multi-purpose Makefile
# Claudia Jughashvili, 2019

AS      := nasm
CC      := gcc
CPP     := g++
LD      := ld
INC     := include
OBJDIR  := obj
SRCDIR  := src
OUTDIR  := lib
OUT     := $(OUTDIR)/libgeo.so
CFLAGS  := -c -Wall -I$(INC) -fPIC
LFLAGS  := -shared
SRC     := $(notdir $(shell find $(SRCDIR) -maxdepth 1 -name '*.cpp'))
OBJ     := $(addprefix $(OBJDIR)/,$(SRC:%.cpp=%.o))

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) $(CFLAGS) $< -o $@

all : $(OBJ)
	$(LD) $(LFLAGS) $(OBJ) -o $(OUT)
	strip -s $(OUT)

.PHONY : clean
clean :
	rm -f $(OBJ) $(OUT)
