#ifndef COLUMNLIST_H
#define COLUMNLIST_H
 
#include "stdlib.h"
#include "columnNode.h"


class ColumnList{
    private:
        ColumnNode *head;
        ColumnNode *tail;
        int length;

    public:
        ColumnList();
        int append(ColumnNode *node);
        ColumnNode* deleteNode(char* key);
        ColumnNode* get(char* key);
        void freeList();
        void printList();
        ColumnNode* getHead();
        int getLength();
};

#endif /*COLUMNLIST_H*/


