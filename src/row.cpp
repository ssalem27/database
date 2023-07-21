#include "row.h"


Row::Row(int index){
    this->index = index;
    this->list = new Llist();
}

int Row::addColumn(char* key, char* value){
    Node* node = new Node(key,value);
    return list->append(node);
}

int Row::deleteColumn(char* key){
    Node* deleted = list->deleteNode(key);
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

void Row::printRow(){
    printf("\"Row\":{\n\"index\": %d\n\"list\":{\n",this->index);
    this->list->printList();
    printf("}\n}");
}

