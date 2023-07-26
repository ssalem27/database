#include "row.h"


Row::Row(){
    this->rowId = (char*) calloc(BUFFER_SIZE, sizeof(char));
    this->list = new ColumnList();
}

int Row::addColumn(char* key, char* value){
    ColumnNode* node = new ColumnNode(key,value);
    return list->append(node);
}

int Row::deleteColumn(char* key){
    ColumnNode* deleted = list->deleteNode(key);
    if(deleted){
        delete(deleted);
        return 0;
    }
    return -1;
}

int Row::updateVal(char *key, char *value){
    return list->get(key)->setValue(value);
}

int Row::updateKey(char *oldKey, char *newKey){
    return list->get(oldKey)->setKey(newKey);
}

void Row::deleteRow(){
    list->freeList();
    delete(list);
}

void Row::printRow(int i){
    printf("\"index\":\"%d\",\n\"list\":{\n",i);
    this->list->printList();
    printf("\n}");
}

ColumnNode* Row::getColumnHead(){
    return this->list->getHead();
}

char* Row::getRowId(){
    return this->rowId;
}

int Row::setRowId(char* rowId){
    if(rowId){
        strncpy(this->rowId,rowId,BUFFER_SIZE);
        return 0;
    }
    return -1;
}