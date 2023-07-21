#ifndef NODE_H
#define NODE_H
 
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <typeinfo>

template <typename T>
class Node{
    private:
        char *key;
        T* value;

    public:
    Node<T>* next;

    Node(char *key, T* value){
        this->setKey(key);
        this->setValue(value);
        this->next = NULL;
    }

    int setKey(char* key){
        int size = 0;
        if(!key){
            this->key = NULL;
            return 0;
        }
        size = sizeof(key);
        this->key = (char*) calloc(1,size);
        if(this->key == NULL){
            return 0;
        }

        strncpy(this->key,key,size);
        return 1;
    }

    int setValue(T* value){
        int size = 0;
        if(!value){
            this->value = NULL;
            return 0;
        }
        size = sizeof(value);
        this->value = (char*) calloc(1,size);
        if(this->value == NULL){
            return 0;
        }

        strncpy(this->value,value,size);
        return 1;
    }

    char* getKey(){
        return this->key;
    }

    T* getValue(){
        return this->value;
    }

    void freeNode(){
        free(this->key);
        free(this->value);
        this->next = NULL;
    }

    void printNode(){
        char* string;
        if(typeid(value)==typeid(string)){
            printf("\"%s\":\"%s\"",this->key,this->value);
        }

        

    }

    int compare(char* key){
        int strlength = strlen(this->getKey()) >= strlen(key) ? strlen(this->getKey()) : strlen(key);
        if (strncmp(this->getKey(),key,strlength) == 0){
            return 1;
        }
        return 0;
    }
};

#endif /*NODE_H*/