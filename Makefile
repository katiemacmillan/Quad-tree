# Makefile
# Makefile for CSC300 Data Structures PA1 Paint Program

# Author:
# Class: CSC300 Data Structures
# Date: Fall 2015

# Usage: make target1 target2 ...

#------------------------------------------------------------------------------

# GNU C/C++ compiler and linker:
LINK = g++

# Preprocessor and compiler flags (turn on warning, optimization, and debugging):
# CPPFLAGS = <preprocessor flags go here>

CFLAGS = -Wall -O -g
CXXFLAGS = $(CFLAGS)

# OpenGL/Mesa libraries for Linux
GL_LIBS = -lglut -lGLU -lGL -lm

#------------------------------------------------------------------------------
# Targets

all: paint

#------------------------------------------------------------------------------

paint:	ellipses.o paint.o callbacks.o globals.o graphics.o rectangle.o shape.o line.o
	$(LINK) -o $@ $^ $(GL_LIBS)

#------------------------------------------------------------------------------

clean:
	rm -f *.o *~ core

cleanall:
	rm -f *.o *~ core paint
