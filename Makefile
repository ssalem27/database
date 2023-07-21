#-----------------------------------------------------------------------------
# Makefile
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Choose a compiler and its options
#--------------------------------------------------------------------------
CC = g++
OPTS = -Og -Wall -Werror -Wno-error=unused-variable -Wdeprecated -Wno-error=unused-function -Wunused-private-field -Wc++11-compat-deprecated-writable-strings
DEBUG = -g

#--------------------------------------------------------------------
# Build Environment
#--------------------------------------------------------------------
SRCDIR=./src
OBJDIR=./obj
INCDIR=./inc
BINDIR=.

#--------------------------------------------------------------------
# Build Files
#--------------------------------------------------------------------

#--------------------------------------------------------------------
# Compiler Options
#--------------------------------------------------------------------
INCLUDE=$(addprefix -I,$(INCDIR))
HEADERS=$(wildcard $(INCDIR)/*.h)
CFLAGS=$(OPTS) $(INCLUDE) $(DEBUG)
OBJECTS=$(addprefix $(OBJDIR)/,node.o llist.o row.o)
#--------------------------------------------------------------------
# Build Recipies for the Executables (binary)
#--------------------------------------------------------------------
all: database

database: $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^
#	g++ -Wall -std=gnu11 -o database node.o llist.o

$(OBJDIR)/node.o:  $(INCDIR)/node.hpp
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ node.cpp  

$(OBJDIR)/llist.o:  $(INCDIR)/llist.hpp
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ llist.hpp  

$(OBJDIR)/row.o: $(SRCDIR)/row.cpp $(INCDIR)/row.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ row.cpp  


clean:
	rm -rf $(OBJDIR)/*.o database




