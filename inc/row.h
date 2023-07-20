#ifndef ROW_H
#define ROW_H

#include "stdlib.h"
#include "llist.h"

class Row{
    private:
    int index;
    Llist* list;

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