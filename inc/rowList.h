#ifndef ROWLIST_H
#define ROWLIST_H
 
#include "stdlib.h"
#include "rowNode.h"


class RowList{
    private:
        RowNode *head;
        RowNode *tail;
        int length;

    public:
        RowList();
        int append(RowNode *node);
        RowNode* deleteNode(char* key);
        RowNode* get(char* key);
        void freeList();
        void printList(int i);
        RowNode* getHead();
        int getLength();
};

#endif /*ROWLIST*/
