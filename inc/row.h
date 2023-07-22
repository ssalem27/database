#ifndef ROW_H
#define ROW_H

#include "stdlib.h"
#include "columnList.h"
#define BUFFER_SIZE 18

class Row{
    private:
    char* rowId;
    ColumnList* list;
    int length;

    public:
    Row();
    int addColumn(char* key, char* value = NULL);
    int deleteColumn(char* key);
    int updateVal(char* key, char* value);
    int updateKey(char* oldKey, char* newKey);
    void deleteRow();
    void printRow();
    ColumnNode* getColumnHead();
    char* getRowId();
    int setRowId(char* rowId);
    int getLength();
};

#endif /*ROW_H*/