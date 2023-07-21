#ifndef ROW_H
#define ROW_H

#include "stdlib.h"
#include "node.hpp"
#include "llist.hpp"
#define BUFFER_SIZE 18

class Row{
    private:
    char* rowId;
    Llist<char>* list;

    public:
    Row();
    int addColumn(char* key, char* value = NULL);
    int deleteColumn(char* key);
    int updateVal(char* key, char* value);
    int updateKey(char* oldKey, char* newKey);
    char* getRowId();
    int setRowId(char* rowId);
    Row* deleteRow();
    void printRow();
};

#endif /*ROW_H*/