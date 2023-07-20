#include "node.h"
 
Node::Node(char *key, char *value){
    this->setKey(key);
    this->setValue(value);
    this->next = NULL;
}

int Node::setKey(char* key){
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

int Node::setValue(char* value){
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

char* Node::getKey(){
    return this->key;
}

char* Node::getValue(){
    return this->value;
}

void Node::freeNode(){
    free(this->key);
    free(this->value);
    this->next = NULL;
}

void Node::printNode(){
    printf("\"%s\":\"%s\"",this->key,this->value);

}

int Node::compare(char* key){
    int strlength = strlen(this->getKey()) >= strlen(key) ? strlen(this->getKey()) : strlen(key);
    if (strncmp(this->getKey(),key,strlength) == 0){
        return 1;
    }
    return 0;
}

