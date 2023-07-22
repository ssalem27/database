#include "rowNode.h"

 
RowNode::RowNode(char *key, Row *value){
    this->setKey(key);
    this->setValue(value);
    this->next = NULL;
}

int RowNode::setKey(char* key){
    int size = 0;
    if(!key){
        this->key = NULL;
        return -1;
    }
    size = sizeof(key);
    this->key = (char*) calloc(1,size);
    if(this->key == NULL){
        return -1;
    }

    strncpy(this->key,key,size);
    return 0;
}

int RowNode::setValue(Row* value){
    ColumnNode* head = value->getColumnHead();
    Row* row = new Row();
    while(head){
        row->addColumn(head->getKey(),head->getValue());
        head = head->next;
    }
    if(value){
        this->value = row;
        return 0;
    }
    this->value = NULL;
    return -1;
}

char* RowNode::getKey(){
    return this->key;
}

Row* RowNode::getValue(){
    return this->value;
}

void RowNode::freeNode(){
    free(this->key);
    this->value->deleteRow();
    delete(value);
    this->next = NULL;
}

void RowNode::printNode(){
    printf("\"%s\": ",this->key);
    this->value->printRow();

}

int RowNode::compare(char* key){
    int strlength = strlen(this->getKey()) >= strlen(key) ? strlen(this->getKey()) : strlen(key);
    if (strncmp(this->getKey(),key,strlength) == 0){
        return 1;
    }
    return 0;
}
