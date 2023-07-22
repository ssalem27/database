#ifndef ROWNODE_H
#define ROWNODE_H
 
#include "stdlib.h"
#include "stdio.h"
#include <cstring>
#include <iostream>
#include "row.h"


class RowNode{
    private:
        char *key;
        Row *value;

    public:
        RowNode *next;
        RowNode(char *key=NULL, Row*value=NULL);
        int setKey(char* key);
        int setValue(Row* value);
        char* getKey();
        Row* getValue();
        void freeNode();
        void printNode();
        int compare(char* key);
};

#endif /*ROWNODE_H*/