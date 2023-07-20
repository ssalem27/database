#ifndef NODE_H
#define NODE_H
 
#include "stdlib.h"
#include "stdio.h"
#include <cstring>
#include <iostream>
using namespace std;


class Node{
    private:
        char *key;
        char *value;

    public:
        Node *next;
        Node(char *key=NULL, char*value=NULL);
        int setKey(char* key);
        int setValue(char* value);
        char* getKey();
        char* getValue();
        void freeNode();
        void printNode();
        int compare(char* key);
};

#endif /*NODE_H*/