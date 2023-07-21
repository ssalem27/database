#-----------------------------------------------------------------------------
# Makefile
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Choose a compiler and its options
#--------------------------------------------------------------------------
CC   = g++	# Use gcc for Zeus
OPTS = -Og -Wall -Werror -Wno-error=unused-variable -Wno-error=unused-function -Wunused-private-field -Wc++11-compat-deprecated-writable-strings
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

$(OBJDIR)/node.o: $(SRCDIR)/node.cpp $(INCDIR)/node.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ node.cpp  

$(OBJDIR)/llist.o: $(SRCDIR)/llist.cpp $(INCDIR)/llist.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ llist.cpp  

$(OBJDIR)/row.o: $(SRCDIR)/row.cpp $(INCDIR)/row.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ row.cpp  


clean:
	rm -rf $(OBJDIR)/*.o database




