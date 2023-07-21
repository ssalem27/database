#ifndef ROW_H
#define ROW_H

#include "stdlib.h"
#include "node.hpp"
#include "llist.hpp"


class Row{
    private:
    int index;
    Llist<char>* list;

    public:
    Row(int index);
    int addColumn(char* key, char* value = NULL);
    int deleteColumn(char* key);
    int updateVal(char* key, char* value);
    int updateKey(char* oldKey, char* newKey);
    void deleteRow();
    void printRow();
};

#endif /*ROW_H*/