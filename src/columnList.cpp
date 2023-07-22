#include "columnList.h"



ColumnList::ColumnList(){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

int ColumnList::append(ColumnNode *node){
    if(node){
        if(head==NULL){
            head= tail = node;
            return 0;
        }
        tail->next = node;
        tail = node;
        this->length++;
        return 0;
    }
    return -1;
}


ColumnNode* ColumnList::deleteNode(char *key){
    ColumnNode* node = NULL;
    ColumnNode* deleted = NULL;
    ColumnNode* nodeNext = NULL; 
    ColumnNode* current = this->head;
    
    if(!current){
        return NULL;
    }

    if(head->compare(key)){
        ColumnNode* node;
        if(head->next){
            node = head->next;
            head->freeNode();
            deleted = head;
            head = node;
            return deleted;
        }
        head->freeNode();
        deleted = head;
        head = tail = NULL;
        return deleted;
    }
    while(current->next){
        if(current->next->compare(key)){
            node = current->next;
            nodeNext = node->next;
            current->next = nodeNext;
            node->freeNode();
            deleted = node;
            this->length--;
            return deleted;
        }
        current = current->next;
    }
    return NULL;
}

ColumnNode* ColumnList::get(char *key){
    ColumnNode* current = this->head;
    while(current){
        if (current->compare(key)){
            return current;
        }
        current = current->next;
    }
    return NULL;

}

void ColumnList::freeList(){
    ColumnNode* current = this->head;
    ColumnNode* temp = NULL;
    while(current->next){
        temp = current->next;
        current->freeNode();
        current = temp;
    }
    this->head = this->tail = current;
}

void ColumnList::printList(){
    ColumnNode* current = this->head;
    while(current){
        current->printNode();
        current = current->next;
        std::cout << "\n";
    }
}

ColumnNode* ColumnList::getHead(){
    return this->head;
}

int ColumnList::getLength(){
    return this->length;
}

