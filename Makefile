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
OBJECTS=$(addprefix $(OBJDIR)/,columnNode.o columnList.o row.o rowNode.o rowList.o hashmap.o database.o)
#--------------------------------------------------------------------
# Build Recipies for the Executables (binary)
#--------------------------------------------------------------------
all: database

database: $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^
#	g++ -Wall -std=gnu11 -o database columnNode.o columnList.o

$(OBJDIR)/json.o:  $(INCDIR)/json.hpp
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ json.hpp  

$(OBJDIR)/columnNode.o: $(SRCDIR)/columnNode.cpp $(INCDIR)/columnNode.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ columnNode.cpp  

$(OBJDIR)/columnList.o: $(SRCDIR)/columnList.cpp $(INCDIR)/columnList.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ columnList.cpp  

$(OBJDIR)/row.o: $(SRCDIR)/row.cpp $(INCDIR)/row.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ row.cpp  

$(OBJDIR)/rowNode.o: $(SRCDIR)/rowNode.cpp $(INCDIR)/rowNode.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ rowNode.cpp  

$(OBJDIR)/rowList.o: $(SRCDIR)/rowList.cpp $(INCDIR)/rowList.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ rowList.cpp  

$(OBJDIR)/hashmap.o: $(SRCDIR)/hashmap.cpp $(INCDIR)/hashmap.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ hashmap.cpp  

$(OBJDIR)/database.o: $(SRCDIR)/database.cpp $(INCDIR)/database.h
	$(CC) -c $(CFLAGS) -o $@ $<
#	g++ database.cpp  

clean:
	rm -rf $(OBJDIR)/*.o database




