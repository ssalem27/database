#include "node.h"
 
Node::Node(char *key, char *value){
    this->setKey(key);
    this->setValue(value);
}

int Node::setKey(char* key){
    if(!key){
        this->key = NULL;
        return 0;
    }
    int size = sizeof(key);
    this->key = (char*) calloc(1,size);
    if(this->key == NULL){
        return 0;
    }

    strncpy(this->key,key,size);
    return 1;
}

int Node::setValue(char* value){
    if(!value){
        this->value = NULL;
        return 0;
    }
    int size = sizeof(value);
    this->value = (char*) calloc(1,size);
    if(this->value == NULL){
        return 0;
    }

    strncpy(this->value,value,size);
    return 1;
}

char* Node::getKey(){
    return this->key;
}

char* Node::getValue(){
    return this->value;
}

