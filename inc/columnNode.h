#ifndef COLUMNNODE_H
#define COLUMNNODE_H
 
#include "stdlib.h"
#include "stdio.h"
#include <cstring>
#include <iostream>


class ColumnNode{
    private:
        char *key;
        char *value;

    public:
        ColumnNode *next;
        ColumnNode(char *key=NULL, char*value=NULL);
        int setKey(char* key);
        int setValue(char* value);
        char* getKey();
        char* getValue();
        void freeNode();
        void printNode();
        int compare(char* key);
};

#endif /*COLUMNNODE_H*/