#ifndef LLIST_H
#define LLIST_H
 
#include "stdlib.h"
#include "node.h"


class Llist{
    private:
        Node *head;
        Node *tail;
        int length;

    public:
        Llist();
        int append(Node *node);
        Node* deleteNode(char* key);
        Node* get(char* key);
        void freeList();
        void printList();
};

#endif /*LLIST_H*/


